#!/bin/bash

BUILD=$(cat build.txt)
BUILD=$((BUILD + 1))

echo $BUILD > build.txt

echo "#define TINOS_BUILD $BUILD" > ./kernel/lib/build.h

# build step here
# make / gcc / etc.
make BUILD_NUMBER=$BUILD


echo "Built TINOS build $BUILD"