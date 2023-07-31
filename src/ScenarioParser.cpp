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
    std::string word, word2, word3, word4;
    while(std::getline(filestream, line)) {
      std::istringstream line_stream(line);
      std::unique_ptr<Scenario> scenarioHolder = std::make_unique<Scenario>();
      // Use structured bindings to directly assign values
      if (std::getline(line_stream, word, ',') && std::getline(line_stream, word2, ',') &&
          std::getline(line_stream, word3, ',') && std::getline(line_stream, word4, ',')) {
          scenarioHolder->setId(std::stoi(word));
          scenarioHolder->setPcapName(word2);
          scenarioHolder->setCommand(word3);
          scenarioHolder->setValue(word4);
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
    std::cout << "ID: " << scenario->getId() << "  pcapName: " << scenario->getPcapName() << "  command: " << scenario->getCommand() << "  value: " << scenario->getValue() << "\n";
  }
}


const std::vector<std::unique_ptr<Scenario>> &ScenarioParser::getScenarios() const{
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


