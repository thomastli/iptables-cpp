#include "iptables/Rule.hpp"
#include "iptables/RuleMap.hpp"
#include "tests/catch.hpp"

using namespace iptables;

TEST_CASE("RuleMapTest - add rule to rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 0;
  Rule rule = Rule();
  ruleMap.addRuleToRuleMap(rule);

  REQUIRE(ruleMap.hasRuleInMap(ruleNum));
}

TEST_CASE("RuleMapTest - delete rule from rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 0;

  SECTION("If the rule does not exist in the rule map") {
      REQUIRE_NOTHROW(ruleMap.deleteRuleFromRuleMap(ruleNum));
  }

  SECTION("If the rule does exist in the rule map") {
      Rule rule = Rule();
      ruleMap.addRuleToRuleMap(rule);

      ruleMap.deleteRuleFromRuleMap(ruleNum);
      REQUIRE(!ruleMap.hasRuleInMap(ruleNum));
  }
}

TEST_CASE("RuleMapTest - retrieve rule from rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 0;

  SECTION("If rule does not exist in the rule map") {
    Rule rule = ruleMap.retrieveRuleFromRuleMap(ruleNum);
    REQUIRE(ruleMap.size() == 0);
  }

  SECTION("If rule does exist in the rule map") {
    Rule rule = Rule();
    ruleMap.addRuleToRuleMap(rule);

    REQUIRE_NOTHROW(ruleMap.retrieveRuleFromRuleMap(ruleNum));
  }
}

TEST_CASE("RuleMapTest - insert rule into rule map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 1;
  Rule rule = Rule();
  ruleMap.insertRuleIntoRuleMap(ruleNum, rule);

  REQUIRE(ruleMap.hasRuleInMap(ruleNum));
}

TEST_CASE("RuleMapTest - has rule in map") {
  RuleMap ruleMap = RuleMap();

  unsigned int ruleNum = 0;

  SECTION("When the rule is not in the map") {
    REQUIRE_FALSE(ruleMap.hasRuleInMap(ruleNum));
  }

  SECTION("When the rule is in the map") {
    unsigned int ruleNum = 0;
    Rule rule = Rule();
    ruleMap.addRuleToRuleMap(rule);
    REQUIRE(ruleMap.hasRuleInMap(ruleNum));
  }
}

TEST_CASE("RuleMapTest - size") {
  RuleMap ruleMap = RuleMap();

  SECTION("When the rule map is empty") {
    REQUIRE(ruleMap.size() == 0);
  }

  SECTION("When the rule map has contents") {
    unsigned int ruleNum = 0;
    Rule rule = Rule();
    ruleMap.addRuleToRuleMap(rule);

    REQUIRE(ruleMap.size() == 1);
  }
}