
#include "ScenarioProcessor.h"

void ScenarioProcessor::processScenarios() {
    std::cout << "\n\n************* PROCESSING SCENARIOS *****************\n\n";
    for(const auto& scenario : m_Parser->getScenarios()) {
         std::cout << "RUNNING SCENARIO NUMBER " << scenario->getId() << "\n";
         m_PcapReader = std::make_unique<PcapReader>(scenario->getPcapName());
         m_PcapReader->readPackets();
         m_PacketsToProcess = m_PcapReader->getPackets();
         std::cout << "Packets read: " << m_PacketsToProcess.size() << "\n"; 
         m_ProcessedPackets = m_PacketsToProcess;
         pcpp::Packet& packetToChange = m_ProcessedPackets[scenario->getPacketNum()];
         if(scenario->getCommand() == "change_source_ip") {
             changeSrcIp(packetToChange, scenario->getValue());
         } else if(scenario->getCommand() == "change_destination_ip") {
             changeDstIp(packetToChange, scenario->getValue());
         }
         // Here we can add more command variations with else if
         else {
             std::cerr << "Unknown command provided in the scenario: " << scenario->getId() << "\n";
         }
         displayPacketsInfo(m_ProcessedPackets);
         std::cout << "Total packets: " << m_ProcessedPackets.size() << "\n";
    }
    // Save modified packets to a pcap file
    saveToPcap(m_ProcessedPackets);
}

void ScenarioProcessor::changeSrcIp(pcpp::Packet& packet, const std::string& value) {
    pcpp::IPv4Layer* ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
    if (ipLayer != nullptr)
    {
        // Change the source IP address
        ipLayer->setSrcIPv4Address(pcpp::IPv4Address(value));
    }
}

void ScenarioProcessor::changeDstIp(pcpp::Packet& packet, const std::string& value) {
    pcpp::IPv4Layer* ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
    if (ipLayer != nullptr)
    {
        // Change the destination IP address
        ipLayer->setDstIPv4Address(pcpp::IPv4Address(value));
    }
}

void ScenarioProcessor::displayPacketsInfo(const std::vector<pcpp::Packet>& packets) {
    unsigned int packetCount = 0;
    // Print each packet SRC and DST IPs
    for (const auto& packet : packets)
    {
        std::cout << "Packet index: " << packetCount << std::endl;
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

const std::vector<pcpp::Packet>& ScenarioProcessor::getProcessedPackets() {
    return m_ProcessedPackets;
}

void ScenarioProcessor::saveToPcap(const std::vector<pcpp::Packet>& finalPackets) {
    // write the modified packet to a pcap file
    pcpp::PcapFileWriterDevice writer("modified_packets.pcap");
    writer.open();
    for (const auto& packet : finalPackets) {
        writer.writePacket(*(packet.getRawPacket()));
    }
    writer.close();
}