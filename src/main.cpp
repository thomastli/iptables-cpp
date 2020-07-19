#include "iptables/IpTablesHandler.hpp"
#include "iptables/Rule.hpp"

using namespace iptables;

void appendAcceptRule(IpTablesHandler& ipTablesHandler) {
  Rule appendRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::TCP;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);
  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  appendRule.setTarget(target);
  appendRule.setProtocol(protocol);
  appendRule.setSourceAddress(source);
  appendRule.setDestinationAddress(destination);

  std::string inputChain = "INPUT";
  ipTablesHandler.appendRuleToChain(inputChain, appendRule);
}

void appendDeclineRule(IpTablesHandler& ipTablesHandler) {
  Rule appendRule = Rule();
  Target target = Target::REJECT;
  Protocol protocol = Protocol::TCP;

  std::string sourceAddr = "127.0.0.1";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "8.8.8.8";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  appendRule.setTarget(target);
  appendRule.setProtocol(protocol);
  appendRule.setSourceAddress(source);
  appendRule.setDestinationAddress(destination);

  std::string chainName = "OUTPUT";
  ipTablesHandler.appendRuleToChain(chainName, appendRule);
}

void insertRule(IpTablesHandler& ipTablesHandler) {
  Rule insertRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  insertRule.setTarget(target);
  insertRule.setProtocol(protocol);
  insertRule.setSourceAddress(source);
  insertRule.setDestinationAddress(destination);

  std::string chainName = "INPUT";
  unsigned int ruleNum = 1;
  ipTablesHandler.insertRuleIntoChain(chainName, ruleNum, insertRule);
}

void replaceRule(IpTablesHandler& ipTablesHandler) {
  Rule replaceRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  replaceRule.setTarget(target);
  replaceRule.setProtocol(protocol);
  replaceRule.setSourceAddress(source);
  replaceRule.setDestinationAddress(destination);

  std::string chainName = "INPUT";
  unsigned int ruleNum = 0;
  ipTablesHandler.replaceRuleInChain(chainName, ruleNum, replaceRule);
}

void deleteRule(IpTablesHandler& ipTablesHandler) {
  Rule deleteRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  deleteRule.setTarget(target);
  deleteRule.setProtocol(protocol);
  deleteRule.setSourceAddress(source);
  deleteRule.setDestinationAddress(destination);

  std::string chainName = "INPUT";
  unsigned int ruleNum = 0;
  ipTablesHandler.deleteRuleFromChain(chainName, deleteRule);
}

int main() {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  appendAcceptRule(ipTablesHandler);
  appendDeclineRule(ipTablesHandler);
  insertRule(ipTablesHandler);
  replaceRule(ipTablesHandler);
  deleteRule(ipTablesHandler);

  ipTablesHandler.shutdown();
}