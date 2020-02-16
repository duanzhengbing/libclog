#!/bin/bash

if [ ! -d build ]; then
    mkdir build
fi

cd build
rm -rf *
cmake -DCMAKE_INSTALL_PREFIX=/usr .. && make
make test
make install

