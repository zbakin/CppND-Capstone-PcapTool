#!/bin/bash
export WORKSPACE=/home/workspace

################ INSTALL DEPENDANCY LIBRARIES #####################
apt install libpcap-dev flex libbison-dev tcpdump

################### INSTALL VCPKG and PCAPPLUSPLUS ###############
cd $WORKSPACE/PcapPlusPlus/
make install
