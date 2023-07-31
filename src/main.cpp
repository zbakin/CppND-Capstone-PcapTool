#include <iostream>
#include <cstdlib>
#include "ScenarioParser.h"
#include "PcapReader.h"

int main(int argc, char *argv[]){
    // Check for arguments
    if (argc < 3) {
      std::cout << "Usage:\n       ./PcapTool [scenario file name] [packet number]\n";
      return 0;
    }
    const size_t packetNum = atoi(argv[2]);
    /*
     ****
     ************* PARSING OF SCENARIO FILE ****************
     ****
    */

    std::string filepath = "/home/workspace/CppND-Capstone-PcapTool/scenarios/";
    std::string argv1(argv[1]);
    filepath = filepath.append(argv1);

    ScenarioParser parser(filepath);
    parser.parse();
    parser.showAllScenarios();
    const auto& parsedScenarios = parser.getScenarios();
  
    /*
     ****
     ************* Looping through vector of Scenarios ****************
     ****
    */
    for (const auto& scenario : parsedScenarios) {
      std::cout << scenario->getId() << "\n";
      std::string pcapLocation = "/home/workspace/CppND-Capstone-PcapTool/pcaps/" + scenario->getPcapName();
      PcapReader p_reader(pcapLocation);
      p_reader.readPackets();
//       std::unique_ptr<pcpp::Packet> pac1 = std::move(p_reader.getPackets()[packetNum]);
//       pcpp::EthLayer* ethernetLayer = pac1.get()->getLayerOfType<pcpp::EthLayer>();
//       // change the source dest MAC address
//       std::cout << "Ethernet: " << ethernetLayer->getDestMac() << "\n";
    }
//     pcpp::IFileReaderDevice* reader = pcpp::IFileReaderDevice::getReader("1_http_packet.pcap");
    
//     	// verify that a reader interface was indeed created
// 	if (reader == NULL)
// 	{
// 		std::cerr << "Cannot determine reader for file type" << std::endl;
// 		return 1;
// 	}

// 	// open the reader for reading
// 	if (!reader->open())
// 	{
// 		std::cerr << "Cannot open input.pcap for reading" << std::endl;
// 		return 1;
// 	}

// 	// read the first (and only) packet from the file
// 	pcpp::RawPacket rawPacket;
// 	if (!reader->getNextPacket(rawPacket))
// 	{
// 		std::cerr << "Couldn't read the first packet in the file" << std::endl;
// 		return 1;
// 	}

// 	// close the file reader, we don't need it anymore
// 	reader->close();

// 	// parse the raw packet into a parsed packet
// 	pcpp::Packet parsedPacket(&rawPacket);

  
  
//     // now let's get the Ethernet layer
//     pcpp::EthLayer* ethernetLayer = parsedPacket.getLayerOfType<pcpp::EthLayer>();
//     // change the source dest MAC address
//     ethernetLayer->setDestMac(pcpp::MacAddress("aa:bb:cc:dd:ee:ff"));

// //     // let's get the IPv4 layer
//    //  pcpp::IPv4Layer* ipLayer = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();
//     ////  change source IP address
//     ipLay// er->setSrcIPv4Address(pcpp::IPv4Address("1.2.3.4"));
//     // chang// e IP ID
//     ipLayer->ge// tIPv4Header()->ipId = pcpp::hostToNet16(4000);
//     // change TTL // value
//     ipLayer->getIPv4H// eader()->timeToLive = 12;

//     // let's get the TCP layer
//     pcpp::TcpLayer* tcpLayer = parsedPacket.getLayerOfType<pcpp::TcpLayer>();
//     // change source port
//     tcpLayer->getTcpHeader()->portSrc = pcpp::hostToNet16(12345);
//     // add URG flag
//     tcpLayer->getTcpHeader()->urgFlag = 1;
//     // add MSS TCP option
//     tcpLayer->addTcpOptionAfter(pcpp::TcpOptionBuilder(pcpp::TCPOPT_MSS, (uint16_t)1460));

//     // let's get the HTTP layer
//     pcpp::HttpRequestLayer* httpRequestLayer = parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();
//     // change the request method from GET to TRACE
//     httpRequestLayer->getFirstLine()->setMethod(pcpp::HttpRequestLayer::HttpTRACE);
//     // change host to www.google.com
//     httpRequestLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->setFieldValue("www.google.com");
//     // change referer value to www.aol.com
//     httpRequestLayer->getFieldByName(PCPP_HTTP_REFERER_FIELD)->setFieldValue("www.aol.com");
//     // remove cookie field
//     httpRequestLayer->removeField(PCPP_HTTP_COOKIE_FIELD);
//     // add x-forwarded-for field
//     pcpp::HeaderField* xForwardedForField = httpRequestLayer->insertField(httpRequestLayer->getFieldByName(PCPP_HTTP_HOST_FIELD), "X-Forwarded-For", "1.1.1.1");
//     // add cache-control field
//     httpRequestLayer->insertField(xForwardedForField, "Cache-Control", "max-age=0");

//     // create a new vlan layer
//     pcpp::VlanLayer newVlanLayer(123, false, 1, PCPP_ETHERTYPE_IP);

//     // add the vlan layer to the packet after the existing Ethernet layer
//     parsedPacket.insertLayer(ethernetLayer, &newVlanLayer);

//     // compute all calculated fields
//     parsedPacket.computeCalculateFields();

//     // write the modified packet to a pcap file
//     pcpp::PcapFileWriterDevice writer("1_modified_packet.pcap");
//     writer.open();
//     writer.writePacket(*(parsedPacket.getRawPacket()));
//     writer.close();

    return 0;
}
