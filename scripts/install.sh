#!/bin/bash
export WORKSPACE=/home/workspace

################ INSTALL DEPENDANCY LIBRARIES #####################
apt install libpcap-dev flex libbison-dev tcpdump
# apt install wireshark

########################## SET UP GIT ############################
git config --global user.email "zhanibek.bakin@gmail.com"
git config --global user.name "Zhanibek Bakin"


################### INSTALL VCPKG and PCAPPLUSPLUS ###############
# cd $WORKSPACE
# git clone https://github.com/microsoft/vcpkg
# cd $WORKSPACE/vcpkg
# ./bootstrap-vcpkg.sh
# ./vcpkg install pcapplusplus
# cd $WORKSPACE
# git clone https://github.com/seladb/PcapPlusPlus.git
cd $WORKSPACE/PcapPlusPlus/
# git checkout v22.11
# ./configure-linux.sh --default
# make libs
make install
