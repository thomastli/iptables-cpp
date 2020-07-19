#include "iptables/Chain.hpp"

using namespace iptables;

void Chain::addRuleToChain(Rule& rule) {
  ruleMap.addRuleToRuleMap(rule);
}

void Chain::insertRuleIntoChain(unsigned int ruleNum, Rule& rule) {
  ruleMap.insertRuleIntoRuleMap(ruleNum, rule);
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