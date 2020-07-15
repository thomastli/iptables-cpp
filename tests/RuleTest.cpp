#include "iptables/Rule.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("RuleTest - get/set target") {
  Rule rule = Rule();

  Target target = Target::ACCEPT;
  rule.setTarget(target);

  REQUIRE(rule.getTarget() == Target::ACCEPT);
}

SCENARIO("RuleTest - get/set protocol") {
  Rule rule = Rule();

  Protocol protocol = Protocol::ALL;
  rule.setProtocol(protocol);

  REQUIRE(rule.getProtocol() == Protocol::ALL);
}