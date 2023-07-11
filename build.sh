#!/bin/sh

# Make a build directory, if one does not already exist
install -d build
cd build

# Clear build directory of any build artifacts 
rm ./*

# Build iptables-cpp
cmake ..
make
