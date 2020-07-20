#include "iptables/RuleMap.hpp"

using namespace iptables;

void RuleMap::addRuleToRuleMap(Rule& rule) {
  unsigned int end = ruleMap.size();
  ruleMap[end] = rule;
}

void RuleMap::insertRuleIntoRuleMap(unsigned int ruleId, Rule& rule) {
  ruleMap[ruleId] = rule;
}

Rule RuleMap::retrieveRuleFromRuleMap(unsigned int numId) {
  Rule rule = Rule();
  if (hasRuleInMap(numId)) {
    rule = ruleMap[numId];
  }
  return rule;
}

void RuleMap::deleteRuleFromRuleMap(unsigned int numId) {
  if (hasRuleInMap(numId)) {
    ruleMap.erase(numId);
  }
}

bool RuleMap::hasRuleInMap(unsigned int numId) {
  bool result = false;
  std::map<unsigned int, Rule>::iterator itr = ruleMap.find(numId);

  if (itr != ruleMap.end()) {
    result = true;
  }
  return result;
}

unsigned int RuleMap::size() {
  return ruleMap.size();
}