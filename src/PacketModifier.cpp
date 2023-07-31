#include "PacketModifier.h"

void PacketModifier::changeSourceIp() {
    // let's get the IPv4 layer
    pcpp::IPv4Layer* ipLayer = m_Packet.getLayerOfType<pcpp::IPv4Layer>();
    // change source IP address
    ipLayer->setSrcIPv4Address(pcpp::IPv4Address("1.2.3.4"));
    // change IP ID
    ipLayer->getIPv4Header()->ipId = pcpp::hostToNet16(4000);
    // change TTL value
    ipLayer->getIPv4Header()->timeToLive = 12;
}