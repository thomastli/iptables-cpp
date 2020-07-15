#include "iptables/IpRule.hpp"
#include "iptables/RuleMap.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("RuleMap - add rule to ip tables map") {
  RuleMap ruleMap = RuleMap();

  WHEN("I add an ip rule to the map") {
    unsigned int numId = 0;
    IpRule ipRule = IpRule();
    ruleMap.addRuleToRuleMap(numId, ipRule);
    THEN("I expect the ip rule is in the map") {}
  }
}

SCENARIO("RuleMap - delete rule to ip tables map") {
  RuleMap ruleMap = RuleMap();

  WHEN("I have an existing value in the map") {
    unsigned int numId = 0;
    IpRule ipRule = IpRule();
    ruleMap.addRuleToRuleMap(numId, ipRule);

    AND_WHEN("I delete a rule from the map") {
      ruleMap.deleteRuleFromRuleMap(numId);

      THEN("I expect the rule to no longer be in the map") {}
    }
  }
}