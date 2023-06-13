/* === CONFIGURATION ============= */

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define SerialDbg     Serial
//#define SerialNCP   Serial1

/* =============================== */

#include "NCP_Helpers.h"

void setup() {
  SerialDbg.begin(115200);
  SerialNCP.begin(115200);

  // Power-up NCP
  ncpInitialize();

  delay(3000);

  if (!ncpWaitResponse()) {
    return;
  }

  const char* ncpFwVer = "unknown";
  if (rpc_blynk_getNcpVersion(&ncpFwVer)) {
    SerialDbg.print("NCP firmware: ");
    SerialDbg.println(ncpFwVer);
  }

  ncpConfigure();

  // Provide Primary MCU firmware info to the NCP
  rpc_blynk_setFirmwareInfo(BLYNK_FIRMWARE_TYPE,
                            BLYNK_FIRMWARE_VERSION,
                            __DATE__ " " __TIME__,
                            BLYNK_RPC_LIB_VERSION);

  // White labeling
  //rpc_blynk_setVendorPrefix("MyCompany");
  //rpc_blynk_setVendorServer("dashboard.mycompany.com");

  // Product setup
  if (!rpc_blynk_initialize(BLYNK_TEMPLATE_ID, BLYNK_TEMPLATE_NAME)) {
    SerialDbg.println("rpc_blynk_initialize failed");
  }
}

void loop() {
  rpc_run();
}

// Define the callback for the NCP state change event
void rpc_client_blynkStateChange_impl(uint8_t state) {
  SerialDbg.print("NCP state: ");
  SerialDbg.println(ncpGetStateString(state));
}

