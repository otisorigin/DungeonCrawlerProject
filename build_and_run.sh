#!/bin/bash
set -e

rm -rf cmake-build-debug
conan install . --output-folder=cmake-build-debug --build=missing -s build_type=Debug
cmake -S . -B cmake-build-debug -DCMAKE_TOOLCHAIN_FILE=cmake-build-debug/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug --config Debug
./cmake-build-debug/dungeon_crawler