#include "iptables/Chain.hpp"

using namespace iptables;

void Chain::addRuleToChain(unsigned int ruleNum, Rule& rule) {
  ruleMap.addRuleToRuleMap(ruleNum, rule);
}

void Chain::deleteRuleFromChain(unsigned int ruleNum) {
  ruleMap.deleteRuleFromRuleMap(ruleNum);
}

Rule Chain::retrieveRuleFromChain(unsigned int ruleNum) {
  Rule retrievedRule = ruleMap.retrieveRuleFromRuleMap(ruleNum);
  return retrievedRule;
}

bool Chain::hasRuleInChain(unsigned int ruleNum) {
  return ruleMap.hasRuleInMap(ruleNum);
}