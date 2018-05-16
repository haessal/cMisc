#!/bin/bash -xe

# Install Google test
git clone --depth=1 -b release-1.8.0 https://github.com/google/googletest.git /usr/src/gtest
cd /usr/src/gtest/
cmake .
make
make install

# Install gcovr
pip install gcovr
