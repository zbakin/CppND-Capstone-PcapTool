#!/bin/bash
export WORKSPACE=/home/workspace
apt install libpcap-dev flex libbison-dev
cd $WORKSPACE
git clone https://github.com/microsoft/vcpkg
cd $WORKSPACE/vcpkg
./bootstrap-vcpkg.sh
./vcpkg install pcapplusplus
cd $WORKSPACE/PcapPlusPlus/
git checkout v22.11
./configure-linux.sh --default
make libs
make install