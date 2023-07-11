#include "iptables/IpTablesHandler.hpp"

#include <json/json.h>

#include <fstream>
#include <iostream>

#include "iptables/Constants.hpp"

static const std::string IP_TABLES_RULES_FILE = "iptables.rules";
using namespace iptables;

void IpTablesHandler::initialize() {
  chainMap = new ChainMap();
  writeHeaderToRulesFile();
}

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

void IpTablesHandler::insertRuleIntoChain(std::string& chainName, unsigned int ruleNum, Rule& rule) {
  Chain chain = Chain();
  if (chainMap->hasChainInMap(chainName)) {
    chain = chainMap->retrieveChainFromMap(chainName);
  }

  chain.insertRuleIntoChain(ruleNum, rule);
  chainMap->addChainToMap(chainName, chain);

  std::string command = CommandConstants::INSERT_COMMAND;
  std::string entry = formatEntryForIpTables(rule);
  std::string output = command + " " + chainName + " " + entry;

  commitEntryToIpTables(output);
}

void IpTablesHandler::replaceRuleInChain(std::string& chainName, unsigned int ruleNum, Rule& rule) {
  Chain chain = Chain();
  if (chainMap->hasChainInMap(chainName)) {
    chain = chainMap->retrieveChainFromMap(chainName);
  }

  chain.insertRuleIntoChain(ruleNum, rule);
  chainMap->addChainToMap(chainName, chain);

  std::string command = CommandConstants::REPLACE_COMMAND;
  std::string entry = formatEntryForIpTables(rule);
  std::string output = command + " " + chainName + " " + std::to_string(ruleNum) + " " + entry;

  commitEntryToIpTables(output);
}

void IpTablesHandler::shutdown() {
  writeFooterToRulesFile();
  restoreRulesFromFile();
  delete chainMap;
}

void IpTablesHandler::writeHeaderToRulesFile() {
  std::ofstream rulesFile;
  rulesFile.open(IP_TABLES_RULES_FILE, std::ios_base::out);

  rulesFile << FileConstants::FILTER << std::endl;
  rulesFile << FileConstants::INPUT_DROP << std::endl;
  rulesFile << FileConstants::FORWARD_DROP << std::endl;
  rulesFile << FileConstants::OUTPUT_DROP << std::endl;

  rulesFile.close();
}

void IpTablesHandler::writeFooterToRulesFile() {
  std::ofstream rulesFile;
  rulesFile.open(IP_TABLES_RULES_FILE, std::ios_base::app);
  rulesFile << CommandConstants::COMMIT_COMMAND << std::endl;
  rulesFile.close();
}

std::string IpTablesHandler::formatEntryForIpTables(Rule& rule) {
  std::string entry;

  if (rule.hasProtocol()) {
    std::string protocolOption = OptionsConstants::PROTOCOL_OPTION;
    entry += protocolOption + " " + rule.parseProtocolToString() + " ";
  }
  if (rule.hasTarget()) {
    std::string targetOption = OptionsConstants::JUMP_OPTION;
    entry += targetOption + " " + rule.parseTargetToString() + " ";
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
    entry += destinationOption + " " + address.formatIpAddressToString() + " ";
  }

  return entry;
}

void IpTablesHandler::commitEntryToIpTables(std::string& entry) {
  std::ofstream rulesFile;
  rulesFile.open(IP_TABLES_RULES_FILE, std::ios_base::app);
  rulesFile << entry << std::endl;
  rulesFile.close();
}

void IpTablesHandler::restoreRulesFromFile() {
  std::string ipTablesRestore = CommandConstants::IP_TABLES_RESTORE;
  std::string command = ipTablesRestore + " " + IP_TABLES_RULES_FILE;
  system(command.c_str());
}