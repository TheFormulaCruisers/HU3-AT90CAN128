# C3



## Operation



## Build

The _tools_ folder contains an ATMEL Studio project that may be used to build the test program located in _tests_. The project is setup to link to the original files in _inc_ and _src_, thus avoiding unnecessary copies. Its build-in compiler includes _inc_ as well (_Properties > Toolchain > Directories_). Macros are defined at _Properties > Toolchain > Symbols_.

A makefile is provided, but is not setup to generate a programmable image. By using _make_, one may easily check whether the program compiles correctly and without warnings using a terminal or command-prompt.

## Devices

Device | Status
--- | ---
AT90CAN128 | Work in progress
