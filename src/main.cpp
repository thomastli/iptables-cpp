#include "iptables/IpTablesHandler.hpp"
#include "iptables/Rule.hpp"

using namespace iptables;

int main() {
  IpTablesHandler ipTablesHandler = IpTablesHandler();

  appendFirstRule(ipTablesHandler);
  appendSecondRule(ipTablesHandler);
  insertRule(ipTablesHandler);
  replaceRule(ipTablesHandler);
}

void appendFirstRule(IpTablesHandler& ipTablesHandler) {
  Rule appendRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::TCP;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);
  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  source.parseIpAddressFromString(destAddr);

  appendRule.setTarget(target);
  appendRule.setProtocol(protocol);
  appendRule.setSourceAddress(source);
  appendRule.setDestinationAddress(destination);

  std::string inputChain = "INPUT";
  ipTablesHandler.appendRuleToChain(inputChain, appendRule);
}

void appendSecondRule(IpTablesHandler& ipTablesHandler) {
  Rule appendRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::TCP;

  std::string sourceAddr = "127.0.0.1";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "8.8.8.8";
  Address destination = Address();
  source.parseIpAddressFromString(destAddr);

  appendRule.setTarget(target);
  appendRule.setProtocol(protocol);
  appendRule.setSourceAddress(source);
  appendRule.setDestinationAddress(destination);

  std::string chainName = "OUTPUT";
  ipTablesHandler.appendRuleToChain(chainName, appendRule);
}

void insertRule(IpTablesHandler& ipTablesHandler) {}

void replaceRule(IpTablesHandler& ipTablesHandler) {
  Rule replaceRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  source.parseIpAddressFromString(destAddr);

  replaceRule.setTarget(target);
  replaceRule.setProtocol(protocol);
  replaceRule.setSourceAddress(source);
  replaceRule.setDestinationAddress(destination);

  std::string chainName = "INPUT";
  ipTablesHandler.replaceRuleInChain(chainName, replaceRule);
}

void deleteRule(IpTablesHandler& ipTablesHandler) {}