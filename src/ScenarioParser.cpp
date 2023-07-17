#include <iostream>
#include "ScenarioParser.h"

struct Scenario {
  std::string name;
  std::string command;
  std::string dataToChange;
};

ScenarioParser::ScenarioParser(std::string filename) {
  _filename = filename;
  std::cout << "The name of the file: " << filename << "\n";
}
