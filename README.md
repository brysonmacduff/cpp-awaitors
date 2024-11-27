## Project Information
* Author: Bryson MacDuff
* Edit Date: 2024-11-09
* Description: This is a c++ template project
## Dependencies
* GoogleTest (GTest)
    * libgtest-dev
    * libgmock-dev
* Speed Log
    * libspdlog-dev
## Build Instructions
    ./build.sh release
## Testing Instructions
    ./run.sh release test
## Run Instructions
    ./run.sh release bin
## Debug Instructions
    ./build.sh debug
    ./run.sh debug bin
* The build.sh and run.sh scripts can be used to build and run both the target executable (cpp-template) and unit test executable (run_tests) in debug mode.
* Running in debug mode uses GDB.
### Common GDB Commands
    break <file.cpp>:<line>
    run
    step
    next
## Build Debian Package
    ./build.sh debian
    sudo apt install -y ./deb/cpp-template.deb
## Additional Notes
* The build.sh and run.sh scripts automate the use of cmake, debian packing, and more.
### build.sh Commands
    ./build.sh clear
    ./build.sh release
    ./build.sh debug
    ./build.sh debian
### run.sh Commands
    ./run.sh release bin
    ./run.sh release test
    ./run.sh debug bin
    ./run.sh debug test
