#include <iostream>
#include "ScenarioParser.h"

struct Scenario {
  std::string name;
  std::string command;
  std::string dataToChange;
};

ScenarioParser::ScenarioParser(std::string filename) {
  if (filename != "") {
      _filename = filename;
      std::cout << "The name of the file: " << filename << "\n";
  }

  std::ifstream f(_filename);
  if (!f.is_open()) {
    std::cerr << "Could not open the file: " << _filename << "\n";
  }
}