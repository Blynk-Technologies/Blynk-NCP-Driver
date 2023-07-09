#if !defined(BLYNK_FIRMWARE_TYPE) && defined(BLYNK_TEMPLATE_ID)
  #define BLYNK_FIRMWARE_TYPE BLYNK_TEMPLATE_ID
#endif

#if !defined(BLYNK_TEMPLATE_ID) || !defined(BLYNK_TEMPLATE_NAME)
  #error "Please specify your BLYNK_TEMPLATE_ID and BLYNK_TEMPLATE_NAME"
#endif

#include <Arduino.h>
#include <BlynkRpcClient.h>
#include <BlynkRpcUartFraming.h>

/*
 * Implement the UART interface
 */

#if defined(BLYNK_NCP_SERIAL)
  #define SerialNCP   BLYNK_NCP_SERIAL
#elif defined(ARDUINO_NANO_RP2040_CONNECT)
  #define SerialNCP   SerialNina
#elif defined(LINUX)
  #include <compat/LibSerialPort.h>
  #if !defined(BLYNK_NCP_PORT)
    #define BLYNK_NCP_PORT "/dev/ttyUSB0"
  #endif
  SerialPort SerialUSB(BLYNK_NCP_PORT);
  #define SerialNCP SerialUSB
#else
  #error "Your board needs extra configuration to work with Blynk.NCP: please define BLYNK_NCP_SERIAL and perform NCP hardware initialization if needed"
#endif

int rpc_uart_available() {
  // Return the amount of data in the UART input buffer
  return SerialNCP.available();
}
int rpc_uart_read() {
  // Get a byte from the UART input buffer
  return SerialNCP.read();
}
size_t rpc_uart_write(uint8_t data) {
  // Put a byte to the UART output buffer
  return SerialNCP.write(data);
}
void rpc_uart_flush() {
  // Wait for UART to output all the data
  SerialNCP.flush();
}
uint32_t rpc_system_millis() {
  // Return uptime in milliseconds
  // This is used to implement the RPC timeout
  return millis();
}

/*
 * Embed the info tag into the MCU firmware binary
 * This structure is used to identify the firmware type
 * and version during the OTA upgrade
 */

#define BLYNK_PARAM_KV(k, v)    k "\0" v "\0"

volatile const char firmwareTag[] PROGMEM = "blnkinf\0"
    BLYNK_PARAM_KV("mcu"    , BLYNK_FIRMWARE_VERSION)
    BLYNK_PARAM_KV("fw-type", BLYNK_FIRMWARE_TYPE)
    BLYNK_PARAM_KV("build"  , BLYNK_FIRMWARE_BUILD_TIME)
    BLYNK_PARAM_KV("blynk"  , BLYNK_RPC_LIB_VERSION)
    "\0";

/*
 * Implement some helpers
 */

bool ncpWaitResponse(uint32_t timeout = 10000) {
  RpcUartFraming_init();
  const uint32_t tbeg = millis();
  while (millis() - tbeg < timeout) {
    if (RPC_STATUS_OK == rpc_ncp_ping()) {
      SerialDbg.println(F("Blynk.NCP response OK"));
      return true;
    }
  }
  SerialDbg.println(F("NCP not responding"));
  return false;
}

const char* ncpGetStateString(uint8_t state) {
  switch (state) {
  case BLYNK_STATE_IDLE             : return "Idle";
  case BLYNK_STATE_CONFIG           : return "Configuration";
  case BLYNK_STATE_CONNECTING_NET   : return "Connecting Network";
  case BLYNK_STATE_CONNECTING_CLOUD : return "Connecting Cloud";
  case BLYNK_STATE_CONNECTED        : return "Connected";

  case BLYNK_STATE_NOT_INITIALIZED  : return "Not Initialized";
  case BLYNK_STATE_OTA_UPGRADE      : return "NCP Upgrade";
  case BLYNK_STATE_ERROR            : return "Error";

  default                           : return "Unknown";
  }
}

void virtualWrite(int virtualPin, const char* value) {
  buffer_t val = { (uint8_t*)value, strlen(value) };
  rpc_blynk_virtualWrite(virtualPin, val);
}

void virtualWrite(int virtualPin, int32_t value) {
  char buff[16];
  itoa(value, buff, 10);
  virtualWrite(virtualPin, buff);
}

template <typename T>
void waitSerialConsole(T& ser) {
#if !defined(LINUX)
  // Wait for serial console, up to 3 seconds
  const uint32_t tstart = millis();
  while (!ser && (millis() - tstart < 2900)) { delay(1); }
  delay(100);
#endif
}

#if defined(LINUX)
int main(int argc, char* argv[])
{
  (void) argc;
  (void) argv;

  setup();
  while (true) {
    loop();
    delay(1);
  }
  return 0;
}
#endif
