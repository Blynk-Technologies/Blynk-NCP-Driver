# Direct usage of the BlynkRcpDriver

The driver provides Blynk Cloud API that is very similar to that in [Blynk C++ API documentation](https://docs.blynk.io/en/blynk-library-firmware-api/virtual-pins).

However, because BlynkRcpDriver is based on C99, the API syntax is different:

## Fucntions

```cpp
Blynk.virtualWrite(...)       -> rpc_blynk_virtualWrite(vpin, buffer_t)
Blynk.syncAll()               -> rpc_blynk_syncAll()
Blynk.syncVirtual(...)        -> rpc_blynk_syncVirtual(buffer_t)
Blynk.setProperty(...)        -> rpc_blynk_setProperty(vpin, property, buffer_t)
Blynk.logEvent(name)          -> rpc_blynk_logEvent(name, "")
Blynk.logEvent(name,descr)    -> rpc_blynk_logEvent(name, descr)
Blynk.resolveEvent(name)      -> rpc_blynk_resolveEvent(name)
Blynk.resolveAllEvents(name)  -> rpc_blynk_resolveAllEvents(name)
Blynk.beginGroup()            -> rpc_blynk_beginGroup(0)
Blynk.beginGroup(ts)          -> rpc_blynk_beginGroup(ts)
Blynk.endGroup()              -> rpc_blynk_endGroup()
```

## Callbacks

### BLYNK_CONNECTED(), BLYNK_DISCONNECTED(), Blynk.onStateChange()

```cpp
void rpc_client_blynkStateChange_impl(uint8_t state) {
    // Your handling
}
```

### BLYNK_WRITE(VPIN)

```cpp
void rpc_client_blynkVPinChange_impl(uint16_t vpin, buffer_t param)
{
    // Your handling
}
```

## `buffer_t` format

Most values will be plain strings: "Hello world", "1234", "123.456", etc.

However, sometimes the value contains multiple items (like an array).
In this case the values are separated using a `0x00` byte, i.e:

```cpp
"First\0Second\0Third"
```
