#include "Scenario.h"

int Scenario::getId() { return m_Id; }
std::string Scenario::getPcapName() { return m_PcapName; }
std::string Scenario::getCommand() { return m_Command; }
std::string Scenario::getValue() { return m_Value; }

void Scenario::setId(int id) { m_Id = id; }
void Scenario::setPcapName(std::string pcapName) { m_PcapName = pcapName; }
void Scenario::setCommand(std::string command) { m_Command = command; }
void Scenario::setValue(std::string pcapValue) { m_Value = pcapValue; }
