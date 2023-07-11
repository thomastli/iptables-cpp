#include "iptables/Chain.hpp"
#include "tests/catch.hpp"

using namespace iptables;

TEST_CASE("ChainTest -  add rule to chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(rule);

  REQUIRE(chain.hasRuleInChain(ruleNum));
}

TEST_CASE("ChainTest - retrieve rule from chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(rule);

  REQUIRE_NOTHROW(chain.retrieveRuleFromChain(ruleNum));
}
TEST_CASE("ChainTest - insert rule into chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 1;
  Rule rule = Rule();
  chain.insertRuleIntoChain(ruleNum, rule);

  REQUIRE(chain.hasRuleInChain(ruleNum));
}

TEST_CASE("ChainTest - delete rule from chain") {
  Chain chain = Chain();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  chain.addRuleToChain(rule);

  chain.deleteRuleFromChain(ruleNum);
  REQUIRE(!chain.hasRuleInChain(ruleNum));
}

TEST_CASE("ChainTest - get size of rule map") {
  Chain chain = Chain();

  SECTION("When the rule map is empty") {
    REQUIRE(chain.getSizeOfRuleMap() == 0);
  }

  SECTION("When the rule map has contents") {
    unsigned int ruleNum = 1;
    Rule rule = Rule();
    chain.insertRuleIntoChain(ruleNum, rule);
    REQUIRE(chain.getSizeOfRuleMap() == 1);
  }
}