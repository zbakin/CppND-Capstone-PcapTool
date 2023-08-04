#include <iostream>
#include <cstdlib>
#include "ScenarioParser.h"
#include "PcapReader.h"
#include "ScenarioProcessor.h"

int main(int argc, char *argv[]){
    // Check for arguments
    if (argc < 2) {
      std::cout << "Usage:\n       ./PcapTool [scenario file name]\n";
      return 0;
    }
    /*
     ****
     ************* PARSING OF SCENARIO FILE ****************
     ****
    */
    std::string scenarioFilepath = argv[1];

    ScenarioProcessor sProcessor(scenarioFilepath);
  
    /*
     ****
     ************* Looping through vector of Scenarios ****************
     ****
    */
    sProcessor.processScenarios();
    return 0;
}
