#!/bin/sh

install -d build
cd build
rm -rf *
cmake ..
make