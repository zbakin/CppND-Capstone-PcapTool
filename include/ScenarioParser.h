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
    // copy constructor
    ScenarioParser(const ScenarioParser& otherP) : m_Filename(otherP.m_Filename) {
        // perform a deep copy of vector of unique pointers
        for (const auto& uniquePtr : otherP.m_ScenarioList) {
            m_ScenarioList.emplace_back(std::make_unique<Scenario>(*uniquePtr));
        }
    }
    // copy assignment operator
    ScenarioParser& operator=(const ScenarioParser& otherP) {
       if (this != &otherP) {
           m_Filename = otherP.m_Filename;
           // perform a deep copy of vector of unique pointers
           for (const auto& uniquePtr : otherP.m_ScenarioList) {
               m_ScenarioList.emplace_back(std::make_unique<Scenario>(*uniquePtr));
           }
       }
       return *this;
    } 
    // Parse scenarios
    void parse();

    // Print Parsed scenarios
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