#!/bin/bash
set -e

cd "$(dirname "$0")/.."

rm -rf cmake-build-debug
cd engine
conan install . --output-folder=../cmake-build-debug --build=missing -s build_type=Debug
cd ..

cmake -B cmake-build-debug -S . -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake-build-debug/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug 