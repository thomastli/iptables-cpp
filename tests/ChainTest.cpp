#include "iptables/Chain.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("ChainTest -  add rule to chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(ruleNum, rule);
}

SCENARIO("ChainTest - retrieve rule from chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(ruleNum, rule);

  Rule retrievedRule = chain.retrieveRuleFromChain(ruleNum);
}

SCENARIO("ChainTest - delete rule from chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(ruleNum, rule);

  chain.deleteRuleFromChain(ruleNum);
}