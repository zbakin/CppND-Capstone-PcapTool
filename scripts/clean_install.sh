#!/bin/bash

## Validate WORKSPACE is set up
if [ ! -d "$WORKSPACE" ]; then
    echo "Error: WORKSPACE env variable is not set."
    echo "Please export WORKSPACE to point to the same level as CppND-Capstone-PcapTool... Aborting"
    exit 1
fi

################ INSTALL DEPENDANCY LIBRARIES #####################
sudo apt install libpcap-dev
sudo apt install flex
sudo apt install libbison-dev
sudo apt install tcpdump

################### INSTALL VCPKG and PCAPPLUSPLUS ###############
cd $WORKSPACE
git clone https://github.com/microsoft/vcpkg
cd $WORKSPACE/vcpkg
./bootstrap-vcpkg.sh
./vcpkg install pcapplusplus
cd $WORKSPACE
git clone https://github.com/seladb/PcapPlusPlus.git
cd $WORKSPACE/PcapPlusPlus/
git checkout v22.11
./configure-linux.sh --default
make libs
make install
