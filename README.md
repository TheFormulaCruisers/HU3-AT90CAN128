# C3

C3 is the main controller in the HU-3. It processes all data coming from nodes and uses that data to control various components, e.g. the motor controller. It may transmit measurement data to the Raspberry Pi, using their SPI connection, for the purpose of being logged and/or displayed on the driver's dashboard. Further, it measures on board power supply currents and temperatures.

This repository contains both the main program as well as the node specific functions. External libraries, such as libcan, libadc, liblogger and libspi, are imported from different repositories as Git submodules. This approach promotes the ability to use a library in other projects, such as the [node](https://github.com/TheFormulaCruisers/HU3-Nodes) and it may improve its maintainability and documentability.

## Operation

After a power cycle, the system initializes hardware and memory and enables interrupts globally before entering the main loop. In the main loop, it handles received node messages and ADC conversions. Priority is given to node messages: the main loop processes all of them before moving on to process only one of the read-out ADC channels during a single loop.

The CAN library is intialized with the message IDs it expects to receive. They may be partial IDs (matching part of the ID using a mask). The library uses interrupts to transfer received messages to a buffer in memory. New messages are then retrieved from the buffer in the main loop, where it is handed to a function designed to process messages with that specific ID. For example, a message from the throttle pedal will be processed by a function controlling the motor speed accordingly.

Such a node specific function may log certain data using the logger library. The log uses two buffers; it logs values to one while transferring the other, exchanging them upon complete transfer with and using libspi. Since the Raspberry Pi expects incoming log data to be received in a certain order and size, liblogger defines this structure statically and only predefined values may be logged. What these values are is described in the libraries header file. When, e.g. adding values or changing their order in the log, the library itself should be altered, committed and pushed from within that repository, and then be updated over here.

The SPI library implements slave operation of the MCU-builtin SPI controller. It registers the static (not being written to) log buffer and transfers it on request of the Raspberry Pi. When full transfer of the buffer is completed, libspi calls a function that rotates - exchanges read/write buffers in - the log and registers the new log buffer.

## Macros

The following macros must be specified when compiling the source:

  * CAN_REV_2B
  * CAN_RX_MSGBUF_SIZE=14
  * CAN_TX_MSGBUF_SIZE=8
  * ADC_START_TC1_COMP

## Build

The _tools_ folder contains an ATMEL Studio project that may be used to build the test program located in _tests_. The project is setup to link to the original files in _inc_ and _src_, thus avoiding unnecessary copies. Its build-in compiler includes _inc_ as well (_Properties > Toolchain > Directories_). Macros are defined at _Properties > Toolchain > Symbols_.

A makefile is provided, but is not setup to generate a programmable image. By using _make_, one may easily check whether the program compiles correctly and without warnings using a terminal or command-prompt.

## Devices

Device | Status
--- | ---
AT90CAN128 | Work in progress