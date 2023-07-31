#ifndef PCAP_MODIFIER
#define PCAP_MODIFIER

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

class PacketModifier {
public:
    PacketModifier(const pcpp::Packet &packet) : m_Packet(packet) {}
    ~PacketModifier() {}

    void changeSourceIp();
    void updateDestinationIp();

private:
    pcpp::Packet m_Packet;
};

#endif /* PCAP_MODIFIER */