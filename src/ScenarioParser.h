#ifndef SCENARIO_PARSER
#define SCENARIO_PARSER

class ScenarioParser {
public:
  ScenarioParser(std::string filename);
  // TODO: copy constructor
  // ScenarioParser(const &ScenarioParser otherReader) {}
  
  // TODO: copy assignment operator
  // operator=(const ScenarioParser otherReader) {} 
  // TODO: destructor
  //~ScenarioParser();
  
  // TODO: maybe add move constructor
  // TODO: maybe add move assignment operator
    
private:
  std::string _filename;
  // TODO: add a list/array of structures to keep the scenario data
};

#endif /* SCENARIO_PARSER */