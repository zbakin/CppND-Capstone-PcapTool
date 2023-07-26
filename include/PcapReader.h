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
    PcapReader(const std::string& filename) : /*m_PcapHandle(nullptr),*/ m_PcapName(filename) {}
  
    ~PcapReader() {
//         if (m_PcapHandle != nullptr) {
//             // close the file handle
//             m_PcapHandle->close();
//             m_PcapHandle = nullptr;
//         }
    }
//     Packet readPacketById();
//     std::vector<std::unique<Packet>> readPackets();
    void readPackets();
private:
    std::string m_PcapName;
//     std::unique_ptr<pcpp::IFileReaderDevice> m_PcapHandle;
    std::vector<std::unique_ptr<pcpp::Packet>> m_Packets;
};

#endif /* PCAP_READER */