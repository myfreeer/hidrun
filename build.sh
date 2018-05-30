#!/bin/bash
MACHINE="$(gcc -dumpmachine)"
echo Building "${MACHINE}"...
mkdir -p "build_${MACHINE}"
cd "build_${MACHINE}"
cmake -GNinja ..
ninja
