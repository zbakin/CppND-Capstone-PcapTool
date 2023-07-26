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
    std::string word;
    while(std::getline(filestream, line)) {
      std::istringstream line_stream(line);
      std::unique_ptr<Scenario> scenarioHolder = std::make_unique<Scenario>();
      std::getline(line_stream, word, ',');
      scenarioHolder->setId(std::stoi(word));
      std::getline(line_stream, word, ',');
      scenarioHolder->setPcapName(word);
      std::getline(line_stream, word, ',');
      scenarioHolder->setCommand(word);
      std::getline(line_stream, word, ',');
      scenarioHolder->setValue(word);
      m_ScenarioList.emplace_back(std::move(scenarioHolder));
    }
    // release the file
    filestream.close();
  }
}

void ScenarioParser::showAllScenarios() {
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

