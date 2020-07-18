#include "iptables/Rule.hpp"
#include "iptables/RuleMap.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("RuleMap - add rule to ip tables map") {
  RuleMap ruleMap = RuleMap();

  unsigned int numId = 0;
  Rule rule = Rule();
  ruleMap.addRuleToRuleMap(numId, rule);

  REQUIRE(ruleMap.hasRuleInMap(numId));
}

SCENARIO("RuleMap - delete rule to ip tables map") {
  RuleMap ruleMap = RuleMap();

  unsigned int numId = 0;
  Rule rule = Rule();
  ruleMap.addRuleToRuleMap(numId, rule);

  ruleMap.deleteRuleFromRuleMap(numId);
  REQUIRE(!ruleMap.hasRuleInMap(numId));
}

SCENARIO("RuleMap - retrieve rule to ip tables map") {
  RuleMap ruleMap = RuleMap();

  unsigned int numId = 0;
  Rule rule = Rule();
  ruleMap.addRuleToRuleMap(numId, rule);

  REQUIRE_NOTHROW(ruleMap.retrieveRuleFromRuleMap(numId));
}