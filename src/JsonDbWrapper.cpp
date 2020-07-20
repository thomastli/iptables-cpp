#include "iptables/JsonDbWrapper.hpp"

#include "iptables/Address.hpp"
#include "iptables/Chain.hpp"
#include "iptables/Constants.hpp"
#include "iptables/Rule.hpp"

using namespace iptables;

Json::Value JsonDbWrapper::backupToJsonDatabase(std::vector<std::string>& chainList) {
  Json::Value backupDb;

  for (std::string chainName : chainList) {
    Chain chain = chainMap->retrieveChainFromMap(chainName);
    int size = chain.getSizeOfRuleMap();

    // Rule number starts at 1
    for (int i = 1; i < size; i++) {
      Rule rule = chain.retrieveRuleFromChain(i);
      Json::Value value = generateJsonValueFromRule(chainName, rule);

      std::string index = std::to_string(i);
      backupDb[index] = value;
    }
  }

  return backupDb;
}

void JsonDbWrapper::restoreFromJsonDatabase(Json::Value& restoreDb) {
  Json::Value restoreDb;

  for (Json::Value entry : restoreDb) {
    std::string chainName = entry[DatabaseConstants::CHAIN_NAME_KEY].asString();
    unsigned int ruleNumber = entry[DatabaseConstants::RULE_NUMBER_KEY].asInt();

    Rule rule = generateRuleFromJsonValue(entry);
    Chain chain = Chain();
    chain.addRuleToChain(rule);

    chainMap->addChainToMap(chainName, chain);
  }
}

Json::Value JsonDbWrapper::generateJsonValueFromRule(std::string chainName, Rule& rule) {
  Json::Value entry;

  Address source = rule.getSourceAddress();
  std::string sourceAddress = source.formatIpAddressToString();
  Address destination = rule.getDestinationAddress();
  std::string destinationAddress = destination.formatIpAddressToString();

  entry[DatabaseConstants::CHAIN_NAME_KEY] = chainName;
  entry[DatabaseConstants::TARGET_KEY] = rule.parseTargetToString();
  entry[DatabaseConstants::PROTOCOL_KEY] = rule.parseProtocolToString();
  entry[DatabaseConstants::INPUT_KEY] = rule.getInValue();
  entry[DatabaseConstants::OUTPUT_KEY] = rule.getOutValue();
  entry[DatabaseConstants::SOURCE_KEY] = sourceAddress;
  entry[DatabaseConstants::DESTINATION_KEY] = destinationAddress;

  return entry;
}

Rule JsonDbWrapper::generateRuleFromJsonValue(Json::Value& entry) {
  Rule rule = Rule();

  std::string proto = entry[DatabaseConstants::PROTOCOL_KEY].asString();
  std::string tar = entry[DatabaseConstants::TARGET_KEY].asString();
  std::string input = entry[DatabaseConstants::INPUT_KEY].asString();
  std::string output = entry[DatabaseConstants::OUTPUT_KEY].asString();
  std::string sourceAddress = entry[DatabaseConstants::SOURCE_KEY].asString();
  std::string destinationAddress = entry[DatabaseConstants::DESTINATION_KEY].asString();

  Protocol protocol = parseProtocolFromString(proto);
  Target target = parseTargetFromString(tar);
  Address source = Address();
  source.parseIpAddressFromString(sourceAddress);
  Address destination = Address();
  destination.parseIpAddressFromString(destinationAddress);

  rule.setTarget(target);
  rule.setProtocol(protocol);
  rule.setInValue(input);
  rule.setOutValue(output);
  rule.setSourceAddress(source);
  rule.setDestinationAddress(destination);

  return rule;
}

Protocol JsonDbWrapper::parseProtocolFromString(std::string& proto) {
  Protocol protocol;
  if (proto == "TCP") {
    protocol = Protocol::TCP;
  } else if (proto == "UDP") {
    protocol = Protocol::UDP;
  } else if (proto == "ICMP") {
    protocol = Protocol::ICMP;
  } else if (proto == "ALL") {
    protocol = Protocol::ALL;
  } else {
    protocol = Protocol::NONE;
  }
  return protocol;
}

Target JsonDbWrapper::parseTargetFromString(std::string& tar) {
  Target target;
  if (tar == "ACCEPT") {
    target = Target::ACCEPT;
  } else if (tar == "DROP") {
    target = Target::DROP;
  } else if (tar == "REJECT") {
    target = Target::REJECT;
  } else {
    target = Target::NONE;
  }
  return target;
}