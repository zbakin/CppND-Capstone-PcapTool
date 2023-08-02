
#include "ScenarioProcessor.h"

void ScenarioProcessor::processScenarios() {
    std::cout << "\n\n************* PROCESSING SCENARIOS *****************\n\n";
    for(const auto& scenario : m_Parser->getScenarios()) {
         std::cout << "RUNNING SCENARIO NUMBER " << scenario->getId() << "\n";
         m_PcapReader = std::make_unique<PcapReader>(scenario->getPcapName());
         m_PcapReader->readPackets();
         m_PacketsToProcess = m_PcapReader->getPackets();
         std::cout << "Packets read: " << m_PacketsToProcess.size() << "\n"; 
         pcpp::Packet& packetToChange = m_PacketsToProcess[scenario->getPacketNum()];
         if(scenario->getCommand() == "change_source_ip") {
             changeSrcIp(packetToChange, scenario->getValue());
         } else if(scenario->getCommand() == "change_destination_ip") {
             changeDstIp(packetToChange, scenario->getValue());
         } 
         // Here we can add more command variations with else if
         else {
             std::cerr << "Unknown command provided in the scenario: " << scenario->getId() << "\n";
         }
         std::cout << "Total packets: " << m_PacketsToProcess.size() << "\n";
      
         // Print All packets
         for (const auto& packet : m_PacketsToProcess)
         {
             pcpp::IPv4Layer* ipLayer = packet.getLayerOfType<pcpp::IPv4Layer>();
             if (ipLayer != nullptr) {
                 std::cout << "New source IP: " << ipLayer->getSrcIPv4Address() << "\n";
                 std::cout << "New destination IP: " << ipLayer->getDstIPv4Address() << "\n";
             }
         }
     }
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

void displayPacketInto(pcpp::Packet& packet) {
  
}

void ScenarioProcessor::displayPackets() {
  
}
