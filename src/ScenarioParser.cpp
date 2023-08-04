#include <iostream>
#include "ScenarioParser.h"

void ScenarioParser::parse() {
    if (m_Filename == "") {
        std::cerr << "PARSER ERROR: configuration file is not provided." << "\n";
        return;
    }
    std::ifstream filestream(m_Filename);
    if (filestream.is_open()) {
        std::string line;
        std::string id, pcapName, packetNum, command, value;
        while(std::getline(filestream, line)) {
          std::istringstream line_stream(line);
          std::unique_ptr<Scenario> scenarioHolder = std::make_unique<Scenario>();
          // Use structured bindings to directly assign values
          if (std::getline(line_stream, id, ',') && std::getline(line_stream, pcapName, ',') &&
              std::getline(line_stream, packetNum, ',') && std::getline(line_stream, command, ',') &&
              std::getline(line_stream, value, ',')) {
              scenarioHolder->setId(std::stoi(id));
              scenarioHolder->setPcapName(pcapName);
              scenarioHolder->setPacketNum(std::stoi(packetNum));
              scenarioHolder->setCommand(command);
              scenarioHolder->setValue(value);
              m_ScenarioList.emplace_back(std::move(scenarioHolder));
          }
        }
        // release the file
        filestream.close();
    }
}

void ScenarioParser::showAllScenarios() {
    if (m_ScenarioList.empty()) {
        std::cout << "No Parsed Scenarios available\n";
        return;
    }
    std::cout << "************** List of Parsed Scenarios **************\n";
    for(const auto &scenario : m_ScenarioList) {
      std::cout << "ID: " << scenario->getId() << "  pcapName: " << scenario->getPcapName() << "   packetNum: " << scenario->getPacketNum() << "  command: " << scenario->getCommand() << "  value: " << scenario->getValue() << "\n";
  }
}

const std::vector<std::unique_ptr<Scenario>>& ScenarioParser::getScenarios() const {
    return m_ScenarioList;
}

void ScenarioParser::setConfigFile(const std::string& filename) {
    if (filename == "") {
        std::cerr << "SET CONFIG FILE ERROR: configuration file is not provided" << "\n";
        return;
    }
    m_Filename = filename;
}

std::string ScenarioParser::getConfigFile() { return m_Filename; }


