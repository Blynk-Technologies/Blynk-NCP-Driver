# Blynk.NCP low-level driver
A shared interface to the services provided by Blynk.NCP

[![version](https://img.shields.io/github/release/Blynk-Technologies/Blynk-NCP-Driver.svg)](https://github.com/Blynk-Technologies/Blynk-NCP-Driver/releases/latest)
[![downloads](https://img.shields.io/github/downloads/Blynk-Technologies/Blynk-NCP-Driver/total)](https://github.com/Blynk-Technologies/Blynk-NCP-Driver/releases/latest)
[![issues](https://img.shields.io/github/issues/Blynk-Technologies/Blynk-NCP-Driver.svg)](https://github.com/Blynk-Technologies/Blynk-NCP-Driver/issues)
[![ci status](https://img.shields.io/github/actions/workflow/status/Blynk-Technologies/BlynkNcpDriver/build.yml?branch=main&logo=github&label=tests)](https://github.com/Blynk-Technologies/BlynkNcpDriver/actions)
[![license](https://img.shields.io/github/license/Blynk-Technologies/Blynk-NCP-Driver)](LICENSE)
[![Stand With Ukraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://stand-with-ukraine.pp.ua)

**Blynk.NCP** is a solution that off-loads connectivity to a **Network Co-Processor (NCP)** while your application logic resides on the **Primary MCU**. This implies a [dual-Microcontroller Unit (MCU)](https://docs.google.com/presentation/d/1aP2sQWB0J9EWj8Y1h5qeyfm2aFwaNSUKnCE-k7zxVnk/present) architecture.

<details><summary><b>When to use Blynk.NCP?</b></summary>

Using Blynk.NCP is recommended if one of these is true:

- You're building a new IoT product with specific requirements for the Primary MCU, and you're adding a separate connectivity module
- You are using Blynk for retrofitting your existing products
- You have included an **AT command**-based module, but you struggle to make it work right or to achieve your product goals
- You are looking for **ridiculously low** risks, integration efforts, and time to market, along with **improved reliability** of your products

</details>

<details><summary><b>Core Features</b></summary>

- **Blynk.Inject**: connect your devices easily using [**Blynk IoT App**](https://docs.blynk.io/en/downloads/blynk-apps-for-ios-and-android) (<img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/googleplay.svg" width="18" height="18" /> Android, <img src="https://cdn.rawgit.com/simple-icons/simple-icons/develop/icons/apple.svg" width="18" height="18" /> iOS) or [🌐 Web Dashboard](https://blynk.cloud)
  - `BLE`-assisted device provisioning for the best end-user experience
  - `WiFiAP`-based provisioning for devices without BLE support
  - **Network Manager**: WiFi (up to 16 saved networks), Ethernet, Cellular (depending on the hardware)
  - Advanced network connection troubleshooting
- Secure **Blynk.Cloud** connection that provides simple API for:
  - Data transfer with Virtual Pins, reporting Events, and accessing Metadata
  - `Time`, `Timezone` and `Location` with an ability to track local time when the device is offline, including DST transitions
- **Blynk.Air** - automatic Over The Air firmware updates using Web Dashboard
  - Both NCP and the Primary MCU firmware updates
  - Direct firmware upgrade using iOS/Android App before device activation

</details>

<details><summary><b>Extra Features</b></summary>

Additional services provided by the Blynk.NCP:

- `⏳ soon` Persistent automation scenarios - work even if the device is offline
- `⏳ soon` Non-volatile storage for the [Preferences](https://github.com/vshymanskyy/Preferences) library
- `✅ ready` NCP-assisted [fail-safe OTA updates](https://github.com/Blynk-Technologies/BlynkNcpDriver/blob/main/docs/Firmware%20Upgrade.md#ncp-assisted-fail-safe-ota-updates)
- `✅ ready` Connectivity-related **device state indication** - requires a monochrome/RGB/addressable LED attached to the NCP
- `✅ ready` **User button** (also used for configuration reset) - requires a momentary push button attached to the NCP
- `✅ ready` **Factory testing** and provisioning
- `🤔 later` Generic File System storage
- `🤔 later` Generic UDP/TCP/TLS socket API

</details>

## Minimum System Requirements

`C99` compiler | `1KB` RAM | `8KB` Flash | `38400 8N1` UART

## Integrations

Based on this low-level NCP driver, Blynk also provides first class support and examples for multiple platforms.  
This includes reference inplementation of **NCP initialization, re-initialization, primary MCU OTA updates** and other features.

- [**Zephyr OS**](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Zephyr)
- [**Arduino**](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Arduino)

## Documentation

- [**Blynk.NCP Overview**](https://docs.blynk.io/en/blynk.ncp/overview)
- [Supported Connectivity Modules](https://docs.blynk.io/en/getting-started/supported-boards#connectivity-modules-supported-by-blynk.ncp)
- [Blynk.NCP Protocol Specification](docs/NCP%20Protocol%20Specification.md)
- [Advanced Time and Location API](docs/Time%20and%20Location.md)
- [Primary MCU OTA upgrades](docs/Firmware%20Upgrade.md)
- [Factory Testing](docs/Factory%20Testing.md)

## Disclaimer

> The community edition of Blynk.NCP is available for personal use and evaluation.  
> If you're interested in using Blynk.NCP for commercial applications, feel free to [contact Blynk][blynk_sales]. Thank you!

[blynk_sales]: https://blynk.io/en/contact-us-business
