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

SCENARIO("RuleTest - get/set opt value") {
  Rule rule = Rule();

  std::string optValue = "--";
  rule.setOptValue(optValue);

  REQUIRE(rule.getOptValue() == "--");
}

SCENARIO("RuleTest - get/set in value") {
  Rule rule = Rule();

  std::string inValue = "*";
  rule.setInValue(inValue);

  REQUIRE(rule.getInValue() == "*");
}

SCENARIO("RuleTest - get/set out value") {
  Rule rule = Rule();

  std::string outValue = "*";
  rule.setOutValue(outValue);

  REQUIRE(rule.getOutValue() == "*");
}

SCENARIO("RuleTest - get/set source address") {
  Rule rule = Rule();

  Address address = Address();
  rule.setSourceAddress(address);

  REQUIRE_NOTHROW(rule.getSourceAddress());
}

SCENARIO("RuleTest - get/set destination address") {
  Rule rule = Rule();

  Address address = Address();
  rule.setDestinationAddress(address);

  REQUIRE_NOTHROW(rule.getDestinationAddress());
}
