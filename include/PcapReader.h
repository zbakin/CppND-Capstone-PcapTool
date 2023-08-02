#ifndef PCAP_READER
#define PCAP_READER

#include <pcap.h>
#include <iostream>

#include "SystemUtils.h"
#include "Packet.h"
#include "EthLayer.h"
#include "VlanLayer.h"
#include "IPv4Layer.h"
#include "TcpLayer.h"
#include "HttpLayer.h"
#include "UdpLayer.h"
#include "DnsLayer.h"
#include "PcapFileDevice.h"

class PcapReader {
public:
    PcapReader(const std::string& filename) : m_PcapName(filename) {}
    ~PcapReader() {}

    void readPackets();
  
    // getters
    std::vector<pcpp::Packet> getPackets();
    void printPackets();
private:
    std::string m_PcapName;
    std::vector<pcpp::Packet> m_Packets;
};

#endif /* PCAP_READER */