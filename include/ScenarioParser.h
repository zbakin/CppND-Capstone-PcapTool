#ifndef SCENARIO_PARSER
#define SCENARIO_PARSER

#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include "Scenario.h"


class ScenarioParser : public Scenario {
public:
  ScenarioParser() : m_Filename("") {}
  ScenarioParser(const std::string& filename) : m_Filename(filename) {
    // Report if the file doesn't exist
    std::ifstream f(m_Filename.c_str());
    if (!f.good()) {
        std::cerr << "File: " << m_Filename << " is not present\n";
    }
  }
  // TODO: copy constructor
  // ScenarioParser(const &ScenarioParser otherReader) {}

  // TODO: copy assignment operator
  // operator=(const ScenarioParser otherReader) {} 
  // TODO: destructor
  //~ScenarioParser();

  // TODO: maybe add move constructor
  // TODO: maybe add move assignment operator
  void parse();

  // Printing methods
  void showAllScenarios();

  // getters
  const std::vector<std::unique_ptr<Scenario>>& getScenarios() const;
  std::string getConfigFile();

  // setters
  void setConfigFile(const std::string& filename);
private:
  std::string m_Filename;
  std::vector<std::unique_ptr<Scenario>> m_ScenarioList;
};

#endif /* SCENARIO_PARSER */