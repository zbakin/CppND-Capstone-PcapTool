#include "PcapReader.h"
#include "Packet.h"

void PcapReader::readPackets() {
    pcpp::IFileReaderDevice* pcapHandle = pcpp::IFileReaderDevice::getReader(m_PcapName);
    // verify that pcapHandle was created
    if (pcapHandle == nullptr) {
        std::cerr << "Failed to generate pcapHandle for file: " << m_PcapName << "\n";
        return;
    }
    // open the handle for reading
    if (!pcapHandle->open()) {
        std::cerr << "Cannot open file: " << m_PcapName << " for reading" << "\n";
        return;
    }
    // read packets from the file
    pcpp::RawPacket rawPacket;
    while(pcapHandle->getNextPacket(rawPacket)) {
        // parse the raw packet into a parsed packet
        // TODO: change to use unique_ptr for elements in vector
        // std::unique_ptr<pcpp::Packet> parsedPacket = std::make_unique<pcpp::Packet>(&rawPacket);
        pcpp::Packet parsedPacket(&rawPacket);
        m_Packets.emplace_back(parsedPacket);
    }
    pcapHandle->close();
    std::cout << "\n\nIn total read " << m_Packets.size() << " packets.\n\n";
}

std::vector<pcpp::Packet> PcapReader::getPackets() { return m_Packets; }

