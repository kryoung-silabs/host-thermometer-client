# host-thermometer-client

This is a Linux/Posix BGAPI host application version of the bt_soc_thermometer_client example in the Silicon Labs Gecko SDK for EFR32 devices. It communicates with a serial NCP device via BGAPI, connects using BLE to devices implementing (and advertising) the GATT server role of the Health Thermometer Profile, and prints the RSSI and temperature readings from each server device when they arrive.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

1. Linux/Posix build environment (OSX, Raspberry Pi, etc.).
2. EFR32 device running a serial UART NCP (Network Co-Processor) firmware image. See the "To Run" section below for more details.
3. One or more devices implementing (and advertising) the GATT server role of the Health Thermometer Profile. See the "To Run" secton below for more details. The software currently supports up to four server devices.
4. Cloned Gecko SDK (tested with GSDK 4.4.2).

### To Build (Linux/OSX)

1. Clone or copy the contents of this repository. 
2. Clone the Silicon Labs Gecko SDK (tested with GSDK 4.4.2). 

Commands shown here are from OSX using Gecko SDK Suite v2.6, but will be similar in Linux/Cygwin.

```
$ git clone https://github.com/kryoung-silabs/host-thermometer-client.git
$ git clone https://github.com/SiliconLabs/gecko_sdk.git
$ cd host-thermometer-client
$ make SDK_DIR=../gecko_sdk
```

### To Run

1. Program your NCP image "bt_ncp" into your target. Instructions on how to implement this, both on custom hardware and on Silicon Labs wireless starter kit (WSTK) radio boards are provided in [AN1259: Using the Silicon Labs Bluetooth(R) Stack v3.x and Higher in Network Co-Processor Mode](https://www.silabs.com/documents/public/application-notes/an1259-bt-ncp-mode-sdk-v3x.pdf).
2. Prepare one or more devices running the "Bluetooth - SoC Thermometer" firmware or equivalent device implementing Health Thermometer service. Silicon Labs provides pre-built and customizable versions of this firmware as the "SOC - Thermometer" example project that will run on Silicon Labs wireless starter kit (WSTK) radio boards. Instructions on how to build and run SiLabs Bluetooth example projects (including "Bluetooth - SoC Thermometer" is described at [this link](https://docs.silabs.com/bluetooth/7.1.0/bluetooth-getting-started-demos-examples/).
3. Connect your EFR32 running the serial NCP firmware ("bt_ncp") to the host via USB, uart, etc.
4. Run the host application, pointing to the correct serial port. The command line is:
```
Usage: thermometer-client -u <serial port>
```

Here's an example using Raspberry Pi with the target NCP running on a WSTK radio board and connected to the Raspberry Pi via USB virtual COM port:

```
$ ./exe/thermometer-client -u /dev/ttyACM0
[I] Opened port on posix.
[I] soc_thermometer_client initialized.
[I] Resetting NCP target (0)...
[I] Bluetooth stack booted: v7.1.0-b236
[I] Bluetooth stack booted: v7.1.0-b236
[I] Bluetooth public device address: 68:0A:E2:AA:77:38
[I] Starting initial discovery
```

If you have one or more soc-thermometer servers advertising, you will see a table with the RSSI and temperature reading from each.

```
[I] ADDR   TEMP   RSSI |ADDR   TEMP   RSSI |ADDR   TEMP   RSSI |ADDR   TEMP   RSSI |
[I] effc  30.25C  -9dBm|775f  29.46C -31dBm|---- ------- ------|---- ------- ------|
```

## Deployment

For a commercially deployed system (i.e. embedded gateway, etc.), use the supplied makefile and source files from the Gecko SDK to cross-compile for the desired platform.

## Support

I am a Field Applications Engineer for Silicon Labs, not a full time software developer, so I've created this application in my "spare time" to provide an example for Silicon Labs customers to use to bring up their hardware, do some testing, and perhaps form as the basis to extend with additional functionality. If needed, I can provide limited support for this specific software via email <<kris.young@silabs.com>>. For support on building NCP firmware images, bringing up NCP firmware, and building target firmware images using examples under Simplicity Studio, please obtain support through the [official Silicon Labs support portal](http://silabs.com/support).


## Authors

* **Kris Young** - *Initial work* - [Kris Young](https://github.com/kryoung-silabs) <<kris.young@silabs.com>>

## License

This AS-IS example project is licensed under the standard Silicon Labs software license. See the [LICENSE.md](LICENSE.md) file for details
