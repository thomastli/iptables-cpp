#include "iptables/Chain.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("ChainTest -  add rule to chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(rule);

  REQUIRE(chain.hasRuleInChain(ruleNum));
}

SCENARIO("ChainTest - retrieve rule from chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(rule);

  REQUIRE_NOTHROW(chain.retrieveRuleFromChain(ruleNum));
}
SCENARIO("ChainTest - insert rule into chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 1;
  Rule rule = Rule();
  chain.insertRuleIntoChain(ruleNum, rule);

  REQUIRE(chain.hasRuleInChain(ruleNum));
}

SCENARIO("ChainTest - delete rule from chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(rule);

  chain.deleteRuleFromChain(ruleNum);
  REQUIRE(!chain.hasRuleInChain(ruleNum));
}