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