#!/bin/bash
# this script is meant to be run from the top level project directory
RUN_TYPE=$1 # refers to either release or debug
RUN_TARGET=$2 # refers to the executable to be run (bin, test)

if [ "$RUN_TYPE" = "release" ] && [ "$RUN_TARGET" = "bin" ]; then
    ./build/release/src/cpp-template
elif [ "$RUN_TYPE" = "release" ] && [ "$RUN_TARGET" = "test" ]; then
    ./build/release/tests/run_tests
elif [ "$RUN_TYPE" = "debug" ] && [ "$RUN_TARGET" = "bin" ]; then
    gdb ./build/debug/src/cpp-template
elif [ "$RUN_TYPE" = "debug" ] && [ "$RUN_TARGET" = "test" ]; then
    gdb ./build/debug/tests/run_tests
else
    echo "Error: Invalid arguments."
fi