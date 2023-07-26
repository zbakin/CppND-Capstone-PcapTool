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

class PcapModifier {
public:
    PcapModifier(const std::string& filename) : pcapHandle(nullptr) {}
    ~PcapModifier() {}
private:
};

#endif /* PCAP_MODIFIER */