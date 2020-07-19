#include "iptables/RuleMap.hpp"

using namespace iptables;

void RuleMap::addRuleToRuleMap(Rule& rule) {
  ruleMap.push_back(rule);
}

void RuleMap::insertRuleIntoRuleMap(unsigned int ruleId, Rule& rule) {
  ruleMap[ruleId] = rule;
}

Rule RuleMap::retrieveRuleFromRuleMap(unsigned int numId) {
  Rule retrievedRule = ruleMap[numId];
  return retrievedRule;
}

void RuleMap::deleteRuleFromRuleMap(unsigned int numId) {
  std::vector<Rule>::iterator itr = ruleMap.begin();
  itr += numId;
  ruleMap.erase(itr);
}

bool RuleMap::hasRuleInMap(unsigned int numId) {
  bool result = false;

  std::vector<Rule>::iterator itr = ruleMap.begin();
  itr += numId;

  if (itr != ruleMap.end()) {
    result = true;
  }

  return result;
}