#include "PcapReader.h"
#include "Packet.h"

void PcapReader::readPackets() {

    pcpp::IFileReaderDevice* pcapHandle = pcpp::IFileReaderDevice::getReader(m_PcapName);
  
    // verify that pcapHandle was created
    if (pcapHandle == nullptr)
    {
        std::cerr << "Failed to generate pcapHandle for file: " << m_PcapName << "\n";
    }
    
    // open the handle for reading
    if (!pcapHandle->open())
    {
        std::cerr << "Cannot open file: " << m_PcapName << " for reading" << "\n";
    }
     
    // read packets from the file
    pcpp::RawPacket rawPacket;
    while(pcapHandle->getNextPacket(rawPacket))
    {
        // parse the raw packet into a parsed packet
        std::unique_ptr<pcpp::Packet> parsedPacket = std::make_unique<pcpp::Packet>(&rawPacket);
        m_Packets.emplace_back(std::move(parsedPacket));
        // TODO: do something with the packet/s
    }
}

