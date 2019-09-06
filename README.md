# host-thermometer-client

This is a Linux/Posix host application version of the soc-thermometer-client example in the Silicon Labs Blue Gecko Bluetooth SDK for EFR32 devices. It communicates with a serial Blue Gecko NCP device, connects using BLE to devices implementing the soc-thermometer-server, and prints the RSSI and temperature readings from each server device when they arrive.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

1. Blue Gecko SDK (installed via Simplicity Studio).
2. Linux/Posix build environment (OSX, Cygwin, Raspberry Pi, etc.).
3. Blue Gecko / Mighty Gecko device running a serial UART NCP (Network Co-Processor) firmware image.
4. soc-thermometer server firmware running on one or more devices.

### Installing

This project can be built as supplied within the Blue Gecko SDK frameworks.

#### For Cygwin/OSX/Linux with SDK installed

Clone or copy the contents of this repository into the Blue Gecko SDK, into a subfolder of app/bluetooth/examples_ncp_host. Commands shown here are from OSX but will be similar in Linux/Cygwin.

```
$ cd /Applications/SimplicityStudiov4.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.6/app/bluetooth/examples_ncp_host/
$ git clone https://github.com/kryoung-silabs/host-thermometer-client.git
$ make
```

#### For Raspberry Pi

1. On the host with SDK installed, create a compressed file archive containing the required SDK source files.

```
$ tar -cvf ble_2_12_2.tgz "protocol/bluetooth/ble_stack/inc" "protocol/bluetooth/ble_stack/src" "app/bluetooth/examples_ncp_host/common"
```

2. Extract on the Raspberry Pi, cd to the new directory, and make.

```
$ tar -xvf ble_2_12_2.tgz blue_gecko_sdk_v2p12p2
$ cd blue_gecko_sdk_v2p12p2/app/bluetooth/examples_ncp_host/
$ git clone https://github.com/kryoung-silabs/host-thermometer-client.git
$ make https://github.com/kryoung-silabs/host-thermometer-client.git
```

#### To Run
Connect your Blue Gecko serial NCP device to the Raspberry Pi and launch the app, pointing to the correct serial port (WSTK virtual COM port in this example)

```
$ ./exe/thermometer-client /dev/tty.usbmodem1411 115200 1
Starting up...
Resetting NCP target...

BLE Central started
```
If you have one or more soc-thermometer servers advertising, you will see a table with the RSSI and temperature reading from each.

```
ADDR  TEMP   RSSI |ADDR  TEMP   RSSI |ADDR  TEMP   RSSI |ADDR  TEMP   RSSI |
2a9b 29.90C -28dBm|0000  0.00C   0dBm|0000  0.00C   0dBm|0000  0.00C   0dBm|
```

4. Program and

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

For a commercial system, use the supplied makefile and source files from the Blue Gecko SDK to cross-compile for the desired platform.

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags).

## Authors

* **Kris Young** - *Initial work* - [Kris Young](https://github.com/kryoung-silabs)

## License

This AS-IS EXAMPLE project is licensed under the standard Silicon Labs software license. See the [LICENSE.md](LICENSE.md) file for details
