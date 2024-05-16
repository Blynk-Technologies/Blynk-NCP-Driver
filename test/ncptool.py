#!/usr/bin/env python3

"""
  ncptool.py /dev/ttyUSB0 --setVendor Blynk --blynkInit TMPLRjoMfbok Test --dump
  ncptool.py /dev/ttyUSB0 --initRGB 15 12 13 0
  ncptool.py /dev/ttyUSB0 --setLedBrightness 128
  ncptool.py /dev/ttyUSB0 --reboot
  ncptool.py /dev/ttyUSB0 --factoryTestWiFi SSID PASS
"""

import sys
import asyncio
import aioserial
import struct
import enum
import datetime
from io import BytesIO

__VERSION__ = '0.1.0'

ser = None

##
# Utilities
##

def crc8(data):
    crc = 0
    for d in data:
        crc ^= d
        for _ in range(8):
            crc <<= 1
            if crc & 0x0100:
                crc ^= 0x07
            crc &= 0xFF
    return crc

def hexdump(msg, data):
    txt = ''.join([chr(x) if x > 31 and x < 127 else '_' for x in data])
    print(msg, data.hex() + " | " + txt)

class MessageBuffer:
    def __init__(self, data=b''):
        self._buff = BytesIO(data)

    def _unpack(self, fmt):
        size = struct.calcsize(fmt)
        (val,) = struct.unpack(fmt, self._buff.read(size))
        return val

    def read_bool(self):
        return True if self._unpack('B') else False

    def read_uint8(self):
        return self._unpack('B')

    def read_int16(self):
        return self._unpack('<h')

    def read_uint16(self):
        return self._unpack('<H')

    def read_cstring(self):
        res = b''
        while True:
            b = self._buff.read(1)
            if ord(b) == 0:
                return res.decode('utf-8')
            else:
                res += b

    def write_bool(self, val):
        self._buff.write(struct.pack('B', 1 if int(val) else 0))

    def write_int8(self, val):
        self._buff.write(struct.pack('b', int(val)))

    def write_int16(self, val):
        self._buff.write(struct.pack('<h', int(val)))

    def write_int32(self, val):
        self._buff.write(struct.pack('<i', int(val)))

    def write_int64(self, val):
        self._buff.write(struct.pack('<q', int(val)))

    def write_uint8(self, val):
        self._buff.write(struct.pack('B', int(val)))

    def write_uint16(self, val):
        self._buff.write(struct.pack('<H', int(val)))

    def write_uint32(self, val):
        self._buff.write(struct.pack('<I', int(val)))

    def write_uint64(self, val):
        self._buff.write(struct.pack('<Q', int(val)))

    def write_float(self, val):
        self._buff.write(struct.pack('<f', float(val)))

    def write_double(self, val):
        self._buff.write(struct.pack('<d', float(val)))

    def write_cstring(self, val):
        self._buff.write(str(val).encode('utf-8') + b'\x00')

    def write_buffer(self, val):
        self.write_uint16(len(val))
        self._buff.write(val)

    def get_buffer(self):
        return self._buff.getvalue()

##
# Serial Framing
##

async def sendPacket(data):
    to_escape = [ 0x11, 0x13, 0xAA, 0xBB, 0xCC ]
    escaped = b''
    for b in data + bytes([crc8(data)]):
        if b in to_escape:
            escaped += bytes([0xCC, 0xFF ^ b])
        else:
            escaped += bytes([b])

    packet = b'\xAA' + escaped + b'\xBB'
    #hexdump("<<", packet)
    await ser.write_async(packet)

async def readPacketInfinite():
    packet = b''
    raw = b''
    unescape = False

    while True:
        data = await ser.read_async()
        raw += data

        if unescape:
            unescape = False
            packet += bytes([data[0] ^ 0xFF])
        elif data == b'\xCC':
            unescape = True
        elif data == b'\xAA':
            raw = data
            packet = b''
        elif data == b'\xBB':
            crc = packet[-1]
            packet = packet[0:-1]
            #hexdump(">>", raw)
            #hexdump(">D", packet)
            if crc == crc8(packet):
                return packet
            else:
                print("CRC mismatch")
        else:
            packet += data

async def readPacket(timeout = 1.0):
    try:
        return await asyncio.wait_for(readPacketInfinite(), timeout=timeout)
    except asyncio.TimeoutError:
        raise TimeoutError("No response")

##
# RPC
##

class RpcUID(enum.IntEnum):
  # System
  SYSTEM_PING               = 0x0101
  SYSTEM_REBOOT             = 0x0102
  SYSTEM_HASUID             = 0x0103

  # Hardware
  HW_SETUARTBAUDRATE        = 0x0201

  HW_INITUSERBUTTON         = 0x0211
  HW_INITLED                = 0x0221
  HW_INITRGB                = 0x0222
  HW_INITARGB               = 0x0223
  HW_SETLEDBRIGHTNESS       = 0x0224

  # Blynk
  BLYNK_INITIALIZE          = 0x0301
  BLYNK_SETVENDORPREFIX     = 0x0302
  BLYNK_SETVENDORSERVER     = 0x0303
  BLYNK_SETFIRMWAREINFO     = 0x0304
  BLYNK_GETNCPVERSION       = 0x0305
  BLYNK_GETSTATE            = 0x0306
  BLYNK_GETHOTSPOTNAME      = 0x0307

  BLYNK_VIRTUALWRITE        = 0x0311
  BLYNK_SYNCALL             = 0x0312
  BLYNK_SYNCVIRTUAL         = 0x0313
  BLYNK_SETPROPERTY         = 0x0314
  BLYNK_BEGINGROUP          = 0x0315
  BLYNK_ENDGROUP            = 0x0316
  BLYNK_LOGEVENT            = 0x0317
  BLYNK_RESOLVEEVENT        = 0x0318
  BLYNK_RESOLVEALLEVENTS    = 0x0319
  BLYNK_SETMETADATA         = 0x031A

  BLYNK_CONFIGRESET         = 0x0323

  BLYNK_FACTORYRESET        = 0x0331
  BLYNK_FACTORYTESTWIFI     = 0x0332
  BLYNK_FACTORYTESTWIFIAP   = 0x0333


class BlynkState(enum.IntEnum):
  BLYNK_STATE_UNKNOWN           = 0

  BLYNK_STATE_IDLE              = 1
  BLYNK_STATE_CONFIG            = 2
  BLYNK_STATE_CONNECTING_NET    = 3
  BLYNK_STATE_CONNECTING_CLOUD  = 4
  BLYNK_STATE_CONNECTED         = 5

  BLYNK_STATE_NOT_INITIALIZED   = 10
  BLYNK_STATE_OTA_UPGRADE       = 11
  BLYNK_STATE_ERROR             = 12

class FactoryTestStatus(enum.IntEnum):
  FACTORY_TEST_OK           = 1
  FACTORY_TEST_INVALID_ARGS = 2
  FACTORY_TEST_SYSTEM_FAIL  = 3
  FACTORY_TEST_WIFI_FAIL    = 4
  FACTORY_TEST_LOW_RSSI     = 5
  FACTORY_TEST_INET_FAIL    = 6


msgId = 0
def getMsgId():
    global msgId
    msgId += 1
    return msgId

async def rpcInvoke(uid, args, timeout = 1.0):
    reqid = getMsgId()

    req = MessageBuffer()
    req.write_uint16(0x67BC)
    req.write_uint16(uid)
    req.write_uint16(reqid)

    await sendPacket(req.get_buffer() + args.get_buffer())
    rsp_data = await readPacket(timeout)
    rsp = MessageBuffer(rsp_data)
    cmd   = rsp.read_uint16()
    msgid = rsp.read_uint16()
    if msgid != reqid:
        raise Exception(f"RPC message id mismatch")

    status = rsp.read_uint8()
    if status != 0:
        raise Exception(f"RPC invoke status: {status}")

    return rsp


async def rpc_system_ping():
    req = MessageBuffer()
    await rpcInvoke(RpcUID.SYSTEM_PING, req)

async def rpc_system_reboot():
    req = MessageBuffer()
    await rpcInvoke(RpcUID.SYSTEM_REBOOT, req)

async def rpc_system_hasUID(uid):
    uid = int(uid, 0)
    req = MessageBuffer()
    req.write_uint16(uid)
    rsp = await rpcInvoke(RpcUID.SYSTEM_HASUID, req)
    retval = rsp.read_bool()
    print(retval)

async def rpc_hw_initUserButton(gpio, active_low):
    req = MessageBuffer()
    req.write_uint16(gpio)
    req.write_bool(active_low)
    await rpcInvoke(RpcUID.HW_INITUSERBUTTON, req)

async def rpc_hw_initLED(gpio, inverted):
    req = MessageBuffer()
    req.write_uint16(gpio)
    req.write_bool(inverted)
    await rpcInvoke(RpcUID.HW_INITLED, req)

async def rpc_hw_initRGB(gpio_r, gpio_g, gpio_b, common_anode):
    req = MessageBuffer()
    req.write_uint16(gpio_r)
    req.write_uint16(gpio_g)
    req.write_uint16(gpio_b)
    req.write_bool(common_anode)
    await rpcInvoke(RpcUID.HW_INITRGB, req)

async def rpc_hw_initARGB(gpio, mode, count):
    req = MessageBuffer()
    req.write_uint16(gpio)
    req.write_uint8(mode)
    req.write_uint8(count)
    await rpcInvoke(RpcUID.HW_INITARGB, req)

async def rpc_hw_setLedBrightness(value):
    req = MessageBuffer()
    req.write_uint8(value)
    await rpcInvoke(RpcUID.HW_SETLEDBRIGHTNESS, req)

async def rpc_blynk_initialize(templateId, templateName):
    req = MessageBuffer()
    req.write_cstring(templateId)
    req.write_cstring(templateName)
    await rpcInvoke(RpcUID.BLYNK_INITIALIZE, req)

async def rpc_blynk_setVendorPrefix(name):
    req = MessageBuffer()
    req.write_cstring(name)
    await rpcInvoke(RpcUID.BLYNK_SETVENDORPREFIX, req)

async def rpc_blynk_setVendorServer(host):
    req = MessageBuffer()
    req.write_cstring(host)
    await rpcInvoke(RpcUID.BLYNK_SETVENDORSERVER, req)

async def rpc_blynk_getNcpVersion():
    req = MessageBuffer()
    rsp = await rpcInvoke(RpcUID.BLYNK_GETNCPVERSION, req)
    version = rsp.read_cstring()
    retval = rsp.read_bool()
    print(version)

async def rpc_blynk_getHotspotName():
    req = MessageBuffer()
    rsp = await rpcInvoke(RpcUID.BLYNK_GETHOTSPOTNAME, req)
    version = rsp.read_cstring()
    retval = rsp.read_bool()
    if retval:
        print(version)
    else:
        print("Not initialized")

async def rpc_blynk_getState():
    req = MessageBuffer()
    rsp = await rpcInvoke(RpcUID.BLYNK_GETSTATE, req)
    retval = BlynkState(rsp.read_uint8())
    print(retval.name)

async def rpc_blynk_setMetadata(field, value):
    req = MessageBuffer()
    req.write_cstring(field)
    req.write_cstring(value)
    await rpcInvoke(RpcUID.BLYNK_SETMETADATA, req)

async def rpc_blynk_configReset():
    req = MessageBuffer()
    await rpcInvoke(RpcUID.BLYNK_CONFIGRESET, req)

async def rpc_blynk_factoryReset():
    req = MessageBuffer()
    await rpcInvoke(RpcUID.BLYNK_FACTORYRESET, req)

async def rpc_blynk_factoryTestWiFi(ssid, password):
    req = MessageBuffer()
    req.write_cstring(ssid)
    req.write_cstring(password)
    rsp = await rpcInvoke(RpcUID.BLYNK_FACTORYTESTWIFI, req, 30000)
    rssi = rsp.read_int16()
    retval = FactoryTestStatus(rsp.read_uint8())
    print(f"Status: {retval.name}")
    print(f"RSSI:   {rssi}dBm")

    if not retval == FactoryTestStatus.FACTORY_TEST_OK:
        sys.exit(1)

async def rpc_blynk_factoryTestWiFiAP(channel):
    req = MessageBuffer()
    req.write_uint16(channel)
    rsp = await rpcInvoke(RpcUID.BLYNK_FACTORYTESTWIFIAP, req, 5000)
    retval = rsp.read_bool()

async def dumpCommands():
    while True:
        packet = await readPacketInfinite()
        hexdump(">>", packet)

async def run_commands(ops):
    opfunc = {
      "reboot":             rpc_system_reboot,
      "hasUID":             rpc_system_hasUID,
      "setVendor":          rpc_blynk_setVendorPrefix,
      "setServer":          rpc_blynk_setVendorServer,
      "blynkInit":          rpc_blynk_initialize,
      "getNcpVersion":      rpc_blynk_getNcpVersion,
      "getHotspotName":     rpc_blynk_getHotspotName,
      "initLED":            rpc_hw_initLED,
      "initRGB":            rpc_hw_initRGB,
      "initARGB":           rpc_hw_initARGB,
      "setLedBrightness":   rpc_hw_setLedBrightness,
      "configReset":        rpc_blynk_configReset,
      "getState":           rpc_blynk_getState,
      "setMeta":            rpc_blynk_setMetadata,

      "factoryReset":       rpc_blynk_factoryReset,
      "factoryTestWiFi":    rpc_blynk_factoryTestWiFi,
      "factoryTestWiFiAP":  rpc_blynk_factoryTestWiFiAP,

      "dump":               dumpCommands
    }
    ts = datetime.datetime.now()
    await rpc_system_ping()
    te = datetime.datetime.now() - ts
    te /= datetime.timedelta(milliseconds=1)
    print(f'Blynk.NCP ready (ping: {te}ms)')
    for op in ops:
        f = opfunc[op[0]]
        args = op[1:]
        print(f"Running {f.__name__}({', '.join(args)})")
        await f(*args)

def main():
    import argparse

    global ser

    parser = argparse.ArgumentParser(description=f'Blynk.NCP utility v{__VERSION__}')
    parser.add_argument('port',             help='serial port')
    parser.add_argument('--baud', type=int, help='baud rate')

    def opAction(op, minargs=1):
        class _action(argparse.Action):
            def __call__(self, parser, namespace, values, option_string=None):
                if len(values) < minargs:
                    raise argparse.ArgumentError(self, "not enough parameters")
                namespace.ops.append([op] + values)
        return _action

    def addCommand(cmd, nargs=0, metavar=None):
        parser.add_argument(f'--{cmd}', action=opAction(cmd, nargs), nargs=nargs, metavar=metavar)

    addCommand('dump')
    addCommand('reboot')
    addCommand('getNcpVersion')
    addCommand('getHotspotName')
    addCommand('hasUID',            1, metavar=('NAME'))
    addCommand('setVendor',         1, metavar=('NAME'))
    addCommand('setServer',         1, metavar=('HOST'))
    addCommand('blynkInit',         2, metavar=('TEMPLATE_ID', 'TEMPLATE_NAME'))
    addCommand('initLED',           2, metavar=('GPIO', 'INVERTED'))
    addCommand('initRGB',           4, metavar=('R', 'G', 'B', 'COMMON_ANODE'))
    addCommand('initARGB',          3, metavar=('GPIO', 'MODE', 'COUNT'))
    addCommand('setLedBrightness',  1, metavar=('0..255'))
    addCommand('configReset')
    addCommand('getState')

    addCommand('factoryReset')
    addCommand('factoryTestWiFi',   2, metavar=('SSID', 'PASS'))
    addCommand('factoryTestWiFiAP', 1, metavar=('CHANNEL'))

    addCommand('setMeta',           2, metavar=('FIELD', 'VALUE'))

    parser.set_defaults(
        baud  = 38400,
        ops   = []
    )
    args = parser.parse_args()
    ser = aioserial.AioSerial(args.port, args.baud)
    asyncio.run(run_commands(args.ops))

if __name__ == "__main__":
    import sys
    try:
        main()
    except Exception as e:
        print(e, file=sys.stderr)
        sys.exit(1)
