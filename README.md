# CPPND: Capstone project for C++ Nanodegree program - PcapTool

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The Capstone Project gives a chance to integrate what's been learned throughout this program.

In this project, a custom C++ application was created, following the principles that have been learned throughout this Nanodegree Program.

PcapTool - application which allows users to update pcap file, based on specific commands. Pcap file is a file, that is captured via tcpdump or similar tools, and contains structured information about comminication between IP protocol supported devices.

## Design and implementation
Classes Scenario, ScenarioParser, ScenarioProcessor, PcapReader were implemented to capture both the scenario file and pcap file, in order to do manipulations on pcap file. 

Libraries which simplified the implementation are: libpcap and pcapplusplus. Both of the libraries are available open source and do not need a license.

## Use cases for PcapTool

1. Network Traffic Analysis: By modifying pcap files, one can manipulate the captured network traffic to simulate different scenarios or test the behavior of network applications.

2. Security Research: PcapTool could service in security research to analyze network traffic for detecting and investigating security threats. By modifying pcap files, it's possible to simulate different attack scenarios, test the effectiveness of security measures, or create custom datasets for machine learning-based security analysis.

3. Protocol Development and Testing: when developing or testing network protocols, modifying pcap files can be useful for simulating specific network conditions or generating custom test scenarios. This allows evaluating the behavior of a protocol implementation under different network conditions.

4. Traffic Generation: By tweaking pcap files, one can generate custom network traffic patterns for various purposes, such as load testing network infrastructure, evaluating the performance of network devices, or simulating specific application behaviors.

5. Trading Analysis: Pcap application can also be used to analyze network traffic related to trading activities. By capturing and analyzing network packets, financial institutions can gain insights into the performance and latency of trading systems, identify any issues that may impact trade execution, and optimize trading strategies.

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

## Install on Mac
Install libpcap
`brew install libpcap`
Build PcapPlusPlus from sources
`https://pcapplusplus.github.io/docs/install/macos`

## Install on Windows
`https://pcapplusplus.github.io/docs/v21.11/install/vs`
`https://pcapplusplus.github.io/docs/next/install/mingw`

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

## Scenario usage

`Scenario Index`,`Pcap file location and name`,`Packet number of interest`,`Command`,`Value`

Examples:
`01,../pcaps/many-protocols.pcap,4709,change_source_ip,8.8.8.8`
`02,../pcaps/modified_packets.pcap,4709,display_packet_info,0`
`03,../pcaps/modified_packets.pcap,35,display_packet_info,0`

Commands available:
`change_source_ip` - change source ip of IPv4 packet
`change_destination_ip` - change destination ip of IPv4 packet
`display_packet_info` - display IPv4 information


## Outputs to expect

Once you build and run the application, the output would be modified_packets.cpp file and console output
would show scenarios ran:

```
****************** RUNNING SCENARIO NUMBER 2 *********************


In total read 4709 packets.

**Successfully changed the destination ip of IP packet to : 2.3.4.5

Packet were saved to modified_packets.pcap!

****************** RUNNING SCENARIO NUMBER 3 *********************


In total read 4709 packets.


PRINTING PACKET 35
Source IP address: 1.1.1.1
Destination IP address: 2.3.4.5
IP ID: 0x646a
TTL: 128
```

## Future work

This project is highly modular and commands can easily be added in ScenarioProcessor.cpp.
Future possible command - `change_src_mac_address`, `change_dst_mac_address`, `change_payload_data` etc...

## Project Submission Rubric

1. The project demonstrates an understanding of C++ functions and control structures. This is demonstrated throughout the project on all classes.
2. The project reads data from a file and process the data, or the program writes data to a file. This can be found in files src/ScenarioParser.cpp:9 and src/ScenarioProcessor.cpp:64
3. The project uses Object Oriented Programming techniques. There are classes such as Scenario, ScenarioParser, ScenarioProcessor, PcapReader. 
4. Classes use appropriate access specifiers for class members. All classes in this tool have private attributes and public methods.
5. The project makes use of references in function declarations. For example, look at ScenarioParser.cpp:48 and ScenarioParser.h:22
6. The project uses smart pointers instead of raw pointers. The project does not use raw pointers. The project uses a smart pointer: unique_ptr. Check - ScenarioParser.h:58.



### Appendix

Useful links:
https://pcapplusplus.github.io/docs/install
