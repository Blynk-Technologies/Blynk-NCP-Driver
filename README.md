# Blynk.NCP low-level driver
A shared interface to the services provided by Blynk.NCP

[![version](https://img.shields.io/github/release/Blynk-Technologies/Blynk-NCP-Driver.svg)](https://github.com/Blynk-Technologies/Blynk-NCP-Driver/releases/latest)
[![downloads](https://img.shields.io/github/downloads/Blynk-Technologies/Blynk-NCP-Driver/total)](https://github.com/Blynk-Technologies/Blynk-NCP-Driver/releases/latest)
[![issues](https://img.shields.io/github/issues/Blynk-Technologies/Blynk-NCP-Example-Arduino.svg)](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Arduino/issues)
[![ci status](https://img.shields.io/github/actions/workflow/status/Blynk-Technologies/BlynkNcpDriver/build.yml?branch=main&logo=github&label=tests)](https://github.com/Blynk-Technologies/BlynkNcpDriver/actions)
[![license](https://img.shields.io/github/license/Blynk-Technologies/Blynk-NCP-Driver)](LICENSE)
[![Stand With Ukraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://stand-with-ukraine.pp.ua)

## Minimum System Requirements

`C99` compiler | `1KB` RAM | `8KB` Flash | `38400 8N1` UART

## Documentation

- [Supported Connectivity Modules](https://docs.blynk.io/en/getting-started/supported-boards#connectivity-modules-supported-by-blynk.ncp)
- [Blynk.NCP Protocol Specification](docs/NCP%20Protocol%20Specification.md)
- [Advanced Time and Location API](docs/Time%20and%20Location.md)
- [Primary MCU OTA upgrades](docs/Firmware%20Upgrade.md)
- [Factory Testing](docs/Factory%20Testing.md)

## Implementations

Based on this low-level NCP driver, Blynk also provides first class support and examples for multiple platforms.  
This includes reference inplementation of **NCP initialization, re-initialization, primary MCU OTA updates** and other features.

- [**Zephyr OS**](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Zephyr)
- [**Arduino**](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Arduino)

## Disclaimer

> The community edition of Blynk.NCP is available for personal use and evaluation.  
> If you're interested in using Blynk.NCP for commercial applications, feel free to [contact Blynk][blynk_sales]. Thank you!

[blynk_sales]: https://blynk.io/en/contact-us-business
