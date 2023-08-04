#ifndef SCENARIO
#define SCENARIO
#include <string>

class Scenario {
public:
    Scenario() : m_Id(-1), m_Command(""), m_PacketNum(-1), m_PcapName(""), m_Value("") {}
    int getId();
    std::string getPcapName();
    std::string getCommand();
    int getPacketNum();
    std::string getValue();

    void setId(int id);
    void setPcapName(std::string pcapName);
    void setPacketNum(int packetNum);
    void setCommand(std::string command);
    void setValue(std::string value);

private:
    int m_Id;
    std::string m_Command;
    int m_PacketNum;
    std::string m_PcapName;
    std::string m_Value;
};

#endif /* SCENARIO */