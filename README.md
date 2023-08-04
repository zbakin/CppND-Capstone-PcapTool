# CPPND: Capstone project for C++ Nanodegree program - PcapTool

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The Capstone Project gives a chance to integrate what's been learned throughout this program.

In this project, a custom C++ application was created, following the principles that have been learned throughout this Nanodegree Program.

PcapTool - application which allows users to update pcap file, based on specific commands. Pcap file is a file, that is captured via tcpdump or similar tools, and contains structured information about comminication between IP protocol supported devices.

## Design and implementation
Classes Scenario, ScenarioParser, ScenarioProcessor, PcapReader were implemented to capture both the scenario file and pcap file, in order to do manipulations on pcap file. 

Libraries which simplified the implementation are: libpcap and pcapplusplus. Both of the libraries are available open source and do not need a license.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* libpcap >= 1.7.4-2
* PcapPlusPlus >= v22.11
* vcpkg

## Basic Build Instructions from clean installation

1. Clone this repo.
2. From the top level directory run: `./scripts/clean_install.sh` to install dependancies such as libpcap and PcapPlusPlus libraries. Make sure to wait until the end of installation - about 10 min.
3. Make a build directory in the top level directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`

## Basic Build Instructions from my Udacity workspace

1. `cd CppND-Capstone-PcapTool`
2. `./scripts/install.sh` to install dependancies such as libpcap and PcapPlusPlus libraries. 
3. `cd build`
4. `cmake .. && make`

## Run app

1. `./PcapTool <path to scenario file>`.
For example, `./PcapTool ../scenarios/scenario1.csv`. 

## Project Submission Rubric

1. The project demonstrates an understanding of C++ functions and control structures. This is demonstrated throughout the project on all classes.
2. The project reads data from a file and process the data, or the program writes data to a file. This can be found in files src/ScenarioParser.cpp:9 and src/ScenarioProcessor.cpp:64
3. The project uses Object Oriented Programming techniques. There are classes such as Scenario, ScenarioParser, ScenarioProcessor, PcapReader. They have private attributes and public methods.
4. Classes use appropriate access specifiers for class members.
