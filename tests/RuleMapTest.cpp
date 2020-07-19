#include "iptables/Rule.hpp"
#include "iptables/RuleMap.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("RuleMapTest - add rule to rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  ruleMap.addRuleToRuleMap(rule);

  REQUIRE(ruleMap.hasRuleInMap(ruleNum));
}

SCENARIO("RuleMapTest - delete rule from rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  ruleMap.addRuleToRuleMap(rule);

  ruleMap.deleteRuleFromRuleMap(ruleNum);
  REQUIRE(!ruleMap.hasRuleInMap(ruleNum));
}

SCENARIO("RuleMapTest - retrieve rule from rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  ruleMap.addRuleToRuleMap(rule);

  REQUIRE_NOTHROW(ruleMap.retrieveRuleFromRuleMap(ruleNum));
}

SCENARIO("RuleMapTest - insert rule into rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 1;
  Rule rule = Rule();
  ruleMap.insertRuleIntoRuleMap(ruleNum, rule);

  REQUIRE(ruleMap.hasRuleInMap(ruleNum));
}