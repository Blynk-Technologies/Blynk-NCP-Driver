# Blynk.Air


## Firmware Update

1. **NCP** invokes `OTA_UPDATE_AVAILABLE` on the Client, indicating the `filename`, `size`, `type`, `version` of the new firmware
   - `type`, `version` could be empty strings, in case the firmware info was not detected by Blynk Cloud
2. The **Client** should validate the received info (e.g., check if it is compatible with the current hardware and software) and return true if it accepts the update
3. If the **Client** confirms the update (returns OK), it **may** (optionally) perform any of the following steps:
   - Wait until the firmware update is appropriate, finish any critical operations
   - Re-configure the NCP UART, i.e. change the baud rate
   - Reboot into bootloader mode or load a special firmware for handling the update process
   - Initialize the memory for receiving the new firmware (e.g., erase the target memory sector)
   - Ping NCP several times to ensure that the communication is working and the framing layer is synchronised
   - If the ping-pong process fails, the Client can attempt to reinitialize the communication (e.g., reconfigure the UART) and retry the process
   - etc.
4. **Client** invokes `OTA_UPDATE_START` function, indicating a suggested chunk size
   - The **NCP** should validate the proposed chunk size and ensure it is within acceptable limits
5. **NCP** invokes `OTA_UPDATE_WRITE` for each chunk sequentially; each request includes `offset`, `data`, `CRC32`
   - The actual chunk size can vary throughout the update, but it should never exceed the suggested chunk size
   - The **Client** returns false if it encounters a CRC mismatch or otherwise cannot process the packet
   - If the request fails or times out, **NCP** should resend the request up to 5 times before terminating the OTA process
   - If **NCP** faces issues downloading the update (i.e. due to the network failure), it invokes `OTA_UPDATE_CANCEL`
   - **Client** should also cancel the OTA if:
     - NCP stops sending new chunks of data (i.e. after 1 minute)
     - There is a power failure
6. After the last packet is transfered, **NCP** invokes `OTA_UPDATE_FINISH`
   - The **Client** can query additional info about the firmware, i.e. the `CRC32`, `MD5` or `SHA256` digest of the complete file
   - The **Client** should perform a final verification of the received firmware before confirming the completion of the update process
   - The **Client** returns True to the NCP to indicate that OTA will be applied.
   - **NCP** reboots at this stage and waits initialization from the Client (this step may be unneded/modified in future)
7. The **Client** reboots and loads the new firmware
8. As part of it's regular initialization procedure, the **Client** sends the new firmware type and version to the NCP
9. The **NCP** provides the new firmware info to the cloud, at which point the upgrade is succesfully completed

