#include "iptables/IpTablesHandler.hpp"

#include <fstream>
#include <iostream>

#include "iptables/Constants.hpp"

static const std::string IP_TABLES_RULES_FILE = "/etc/iptables/iptables.rules";
using namespace iptables;

void IpTablesHandler::appendRuleToChain(std::string& chainName, Rule& rule) {
  Chain chain = Chain();

  if (chainMap->hasChainInMap(chainName)) {
    chain = chainMap->retrieveChainFromMap(chainName);
  }

  chain.addRuleToChain(rule);
  chainMap->addChainToMap(chainName, chain);

  std::string command = CommandConstants::APPEND_COMMAND;
  std::string entry = formatEntryForIpTables(rule);
  std::string output = command + " " + chainName + " " + entry;

  commitEntryToIpTables(output);
}

void IpTablesHandler::deleteRuleFromChain(std::string& chainName, Rule& rule) {
  if (chainMap->hasChainInMap(chainName)) {
    chainMap->deleteChainFromMap(chainName);

    std::string command = CommandConstants::DELETE_COMMAND;
    std::string entry = formatEntryForIpTables(rule);
    std::string output = command + " " + chainName + " " + entry;

    commitEntryToIpTables(output);
  }
}

void IpTablesHandler::insertRuleIntoChain(std::string& chainName, Rule& rule) {
  Chain chain = Chain();

  if (chainMap->hasChainInMap(chainName)) {
    chain = chainMap->retrieveChainFromMap(chainName);
  }

  chainMap->addChainToMap(chainName, chain);

  std::string command = CommandConstants::INSERT_COMMAND;
  std::string entry = formatEntryForIpTables(rule);
  std::string output = command + " " + chainName + " " + entry;

  commitEntryToIpTables(output);
}

void IpTablesHandler::listAllRulesInChain(std::string& chainName) {
  std::string command = CommandConstants::LIST_COMMAND;
}

void IpTablesHandler::listRuleInChain(std::string& chainName, Rule& rule) {
  std::string command = CommandConstants::LIST_COMMAND;
  std::string entry = formatEntryForIpTables(rule);
  std::string output = command + " " + chainName + " " + entry;
}

std::string IpTablesHandler::formatEntryForIpTables(Rule& rule) {
  std::string entry;

  if (rule.hasTarget()) {
    std::string targetOption = OptionsConstants::JUMP_OPTION;
    entry += targetOption + " " + rule.parseTargetToString() + " ";
  }
  if (rule.hasProtocol()) {
    std::string protocolOption = OptionsConstants::PROTOCOL_OPTION;
    entry += protocolOption + " " + rule.parseProtocolToString() + " ";
  }
  if (rule.hasInValue()) {
    std::string inputOption = OptionsConstants::INPUT_OPTION;
    entry += inputOption + " " + rule.getInValue() + " ";
  }
  if (rule.hasOutValue()) {
    std::string outputOption = OptionsConstants::OUTPUT_OPTION;
    entry += outputOption + " " + rule.getOutValue() + " ";
  }
  if (rule.hasSource()) {
    std::string sourceOption = OptionsConstants::SOURCE_OPTION;
    Address address = rule.getSourceAddress();
    entry += sourceOption + " " + address.formatIpAddressToString() + " ";
  }
  if (rule.hasDestination()) {
    std::string destinationOption = OptionsConstants::DESTINATION_OPTION;
    Address address = rule.getDestinationAddress();
    entry += destinationOption + " " + address.formatIpAddressToString();
  }

  return entry;
}

void IpTablesHandler::commitEntryToIpTables(std::string& entry) {
  std::ofstream rulesFile;
  rulesFile.open(IP_TABLES_RULES_FILE);
  rulesFile << entry << std::endl;
  rulesFile.close();
}