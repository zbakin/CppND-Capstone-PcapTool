#include "PcapReader.h"
#include "Packet.h"

void PcapReader::readPackets() {

    pcpp::IFileReaderDevice* pcapHandle = pcpp::IFileReaderDevice::getReader(m_PcapName);
  
    // verify that pcapHandle was created
    if (pcapHandle == nullptr)
    {
        std::cerr << "Failed to generate pcapHandle for file: " << m_PcapName << "\n";
        return;
    }
    
    // open the handle for reading
    if (!pcapHandle->open())
    {
        std::cerr << "Cannot open file: " << m_PcapName << " for reading" << "\n";
        return;
    }
    std::vector<pcpp::Packet> udpPackets;
    // read packets from the file
    pcpp::RawPacket rawPacket;
    while(pcapHandle->getNextPacket(rawPacket))
    {
        // parse the raw packet into a parsed packet
//         std::unique_ptr<pcpp::Packet> parsedPacket = std::make_unique<pcpp::Packet>(&rawPacket);
        pcpp::Packet parsedPacket(&rawPacket);
        // Check if the packet has a UDP layer
        if (parsedPacket.isPacketOfType(pcpp::UDP))
        {
//             m_Packets.emplace_back(std::move(parsedPacket));
            udpPackets.emplace_back(parsedPacket);
        }

        // do something with the packet/s
        for (const auto& packet : udpPackets)
        {
            pcpp::UdpLayer* udpLayer = packet.getLayerOfType<pcpp::UdpLayer>();
            if (udpLayer != nullptr)
            {
                std::cout << "Source Port: " << udpLayer->getUdpHeader()->portSrc << std::endl;
                std::cout << "Destination Port: " << udpLayer->getUdpHeader()->portDst << std::endl;
                std::cout << "Payload Length: " << udpLayer->getUdpHeader()->length << std::endl;
                std::cout << "Payload Data: " << udpLayer->getLayerPayload() << std::endl;
                std::cout << std::endl;
            }
            break;
        }
    }

    pcapHandle->close();
}

std::vector<std::unique_ptr<pcpp::Packet>> PcapReader::getPackets() {
    return std::move(m_Packets);
}

