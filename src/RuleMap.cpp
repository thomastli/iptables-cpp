#include "iptables/RuleMap.hpp"

using namespace iptables;

void RuleMap::addRuleToRuleMap(unsigned int numId, Rule& rule) {
  ruleMap[numId] = rule;
}

Rule RuleMap::retrieveRuleFromRuleMap(unsigned int numId) {
  Rule retrievedRule = ruleMap[numId];
  return retrievedRule;
}

void RuleMap::deleteRuleFromRuleMap(unsigned int numId) {
  ruleMap.erase(numId);
}

bool RuleMap::hasRuleInMap(unsigned int numId) {
  bool result = false;

  std::map<unsigned int, Rule>::iterator itr = ruleMap.find(numId);
  if (itr != ruleMap.end()) {
    result = true;
  }

  return result;
}