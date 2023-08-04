
#include "ScenarioProcessor.h"

void ScenarioProcessor::processScenarios() {
    std::cout << "\n\n****************** PROCESSING SCENARIOS ****************************\n\n";
    for(const auto& scenario : m_Parser->getScenarios()) {
         std::cout << "****************** RUNNING SCENARIO NUMBER " << scenario->getId() << " *********************\n";
         m_PcapReader = std::make_unique<PcapReader>(scenario->getPcapName());
         m_PcapReader->readPackets();
         m_PacketsToProcess = m_PcapReader->getPackets();
         m_ProcessedPackets = m_PacketsToProcess;
         pcpp::Packet& packet = m_ProcessedPackets[scenario->getPacketNum() - 1];
         if(scenario->getCommand() == "change_source_ip") {
             changeSrcIp(packet, scenario->getValue());
             // Save modified packets to a pcap file
             saveToPcap(m_ProcessedPackets);
         } else if(scenario->getCommand() == "change_destination_ip") {
             changeDstIp(packet, scenario->getValue());
             // Save modified packets to a pcap file
             saveToPcap(m_ProcessedPackets);
         } else if(scenario->getCommand() == "display_packet_info") {
             displayPacketInfo(packet, scenario->getPacketNum());
         }
         // Here we can add more command variations with else if
         else {
             std::cerr << "Unknown command provided in the scenario: " << scenario->getId() << "\n";
         }
    }
}

void ScenarioProcessor::changeSrcIp(pcpp::Packet& packet, const std::string& value) {
    pcpp::IPv4Layer* ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
    if (ipLayer != nullptr)
    {
        // Change the source IP address
        ipLayer->setSrcIPv4Address(pcpp::IPv4Address(value));
        std::cout << "**Successfully changed the source ip of IP packet to : " << value << "\n";
    }
}

void ScenarioProcessor::changeDstIp(pcpp::Packet& packet, const std::string& value) {
    pcpp::IPv4Layer* ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
    if (ipLayer != nullptr)
    {
        // Change the destination IP address
        ipLayer->setDstIPv4Address(pcpp::IPv4Address(value));
        std::cout << "**Successfully changed the destination ip of IP packet to : " << value << "\n";
    }
}

void ScenarioProcessor::displayPacketsInfo(const std::vector<pcpp::Packet>& packets) {
    std::cout << "\n\n***********PRINTING ALL PACKETS***************" << "\n";
    unsigned int packetCount = 1;
    // Print each packet SRC and DST IPs
    for (const auto& packet : packets)
    {
        std::cout << "\nPacket index: " << packetCount;
        pcpp::IPv4Layer* ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
        if (ipLayer != nullptr) {
            std::cout << std::endl
            << "Source IP address: " << ipLayer->getSrcIPAddress() << std::endl
            << "Destination IP address: " << ipLayer->getDstIPAddress() << std::endl
            << "IP ID: 0x" << std::hex << pcpp::netToHost16(ipLayer->getIPv4Header()->ipId) << std::endl
            << "TTL: " << std::dec << (int)ipLayer->getIPv4Header()->timeToLive << std::endl;
        }
        ++packetCount;
    }
}

void ScenarioProcessor::displayPacketInfo(const pcpp::Packet& packet, int packetNum) {
    std::cout << "\nPRINTING PACKET " << packetNum;
    pcpp::IPv4Layer* ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
    if (ipLayer != nullptr) {
        std::cout << std::endl
        << "Source IP address: " << ipLayer->getSrcIPAddress() << std::endl
        << "Destination IP address: " << ipLayer->getDstIPAddress() << std::endl
        << "IP ID: 0x" << std::hex << pcpp::netToHost16(ipLayer->getIPv4Header()->ipId) << std::endl
        << "TTL: " << std::dec << (int)ipLayer->getIPv4Header()->timeToLive << std::endl;
    }
}

const std::vector<pcpp::Packet>& ScenarioProcessor::getProcessedPackets() {
    return m_ProcessedPackets;
}

void ScenarioProcessor::saveToPcap(const std::vector<pcpp::Packet>& finalPackets) {
    // write the modified packet to a pcap file
    pcpp::PcapFileWriterDevice writer("../pcaps/modified_packets.pcap");
    writer.open();
    for (const auto& packet : finalPackets) {
        writer.writePacket(*(packet.getRawPacket()));
    }
    writer.close();
    std::cout << "\nPacket were saved to modified_packets.pcap!\n\n";
}