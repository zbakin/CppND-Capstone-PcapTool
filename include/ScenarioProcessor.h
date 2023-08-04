#ifndef SCENARIO_PROCESSOR
#define SCENARIO_PROCESSOR

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include "ScenarioParser.h"
#include "PcapReader.h"


class ScenarioProcessor {
public:
  ScenarioProcessor(const std::string& filename) : m_Filename(filename)  {
      // Create Parser unique pointer object
      m_Parser = std::make_unique<ScenarioParser>(m_Filename);
      m_Parser->parse();
      m_Parser->showAllScenarios();
  }
  // getters
  const std::vector<pcpp::Packet>& getProcessedPackets();

  void processScenarios();
  // functions to manipulate packets
  void changeDstIp(pcpp::Packet& packet, const std::string& value);
  void changeSrcIp(pcpp::Packet& packet, const std::string& value);
  void displayPacketsInfo(const std::vector<pcpp::Packet>& packets);

  // method to save packets into a new pcap file
  void saveToPcap(const std::vector<pcpp::Packet>& finalPackets);
private:
//   std::unordered_map<std::string, int> m_Map;
  std::vector<pcpp::Packet> m_PacketsToProcess;
  std::vector<pcpp::Packet> m_ProcessedPackets;
  std::unique_ptr<ScenarioParser> m_Parser;
  std::unique_ptr<PcapReader> m_PcapReader;
  std::string m_Filename;
};

#endif /* SCENARIO_PROCESSOR */