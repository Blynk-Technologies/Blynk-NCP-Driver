/* === CONFIGURATION ============= */

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define SerialDbg     Serial
//#define SerialNCP   Serial1

/* =============================== */

#if defined(SerialNCP)
  // OK, use it
#elif defined(ARDUINO_NANO_RP2040_CONNECT) && defined(__MBED__)
  #define SerialNCP   SerialNina
#else
  #error "SerialNCP is not defined"
#endif

#include <BlynkRpcClient.h>
#include <BlynkRpcInfraArduino.h>

#if !defined(BLYNK_FIRMWARE_TYPE) && defined(BLYNK_TEMPLATE_ID)
  #define BLYNK_FIRMWARE_TYPE BLYNK_TEMPLATE_ID
#endif

#if !defined(BLYNK_TEMPLATE_ID) || !defined(BLYNK_TEMPLATE_NAME)
  #error "Please specify your BLYNK_TEMPLATE_ID and BLYNK_TEMPLATE_NAME"
#endif

#if defined(ARDUINO_NANO_RP2040_CONNECT) && defined(__MBED__)
  void ncpInitialize() {
    pinMode(NINA_RESETN, OUTPUT);
    digitalWrite(NINA_RESETN, HIGH);
  }

  void ncpConfigure() {
    rpc_hw_initRGB(27, 25, 26, true);
    rpc_hw_setLedBrightness(128);
  }
#else
  void ncpInitialize() {
    // TODO: Power-up NCP, if needed
  }
  void ncpConfigure() {}
#endif

bool waitNCP() {
  for (int i = 0; i < 10; i++) {
    uint32_t tbeg = micros();
    if (RPC_STATUS_OK == rpc_system_ping()) {
      uint32_t tend = micros();
      Serial.println("Blynk.NCP response OK");
      return true;
    }
  }
  Serial.println("NCP not responding");
  return false;
}

void setup() {
  SerialDbg.begin(115200);
  SerialNCP.begin(115200);

  ncpInitialize();

  delay(1000);

  if (!waitNCP()) {
    return;
  }

  const char* ncpFwVer = "unknown";
  if (rpc_blynk_getNcpVersion(&ncpFwVer)) {
    Serial.print("NCP firmware: ");
    Serial.println(ncpFwVer);
  }

  ncpConfigure();

  rpc_blynk_setFirmwareInfo(BLYNK_FIRMWARE_TYPE,
                            BLYNK_FIRMWARE_VERSION,
                            __DATE__ " " __TIME__,
                            BLYNK_RPC_LIB_VERSION);

  if (!rpc_blynk_initialize(BLYNK_TEMPLATE_ID, BLYNK_TEMPLATE_NAME)) {
    Serial.println("rpc_blynk_initialize failed");
  }
}

void loop() {
  rpc_run();
}
