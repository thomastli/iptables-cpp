#include "iptables/Rule.hpp"
#include "tests/catch.hpp"

using namespace iptables;

TEST_CASE("RuleTest - has target"){
  Rule rule = Rule();

  SECTION("When the rule has no target") {
    REQUIRE_FALSE(rule.hasTarget());
  }

  SECTION("When the rule has a target set") {
    Target target = Target::ACCEPT;
    rule.setTarget(target);
    REQUIRE(rule.hasTarget());
  }
}

TEST_CASE("RuleTest - has protocol"){
  Rule rule = Rule();

  SECTION("When the rule has no protocol") {
    REQUIRE_FALSE(rule.hasProtocol());
  }

  SECTION("When the rule has a protocol set") {
    Protocol protocol = Protocol::ALL;
    rule.setProtocol(protocol);
    REQUIRE(rule.getProtocol() == Protocol::ALL);
  }
}

TEST_CASE("RuleTest - has opt value") {
  Rule rule = Rule();

  SECTION("When the rule has no opt value") {
    REQUIRE_FALSE(rule.hasOptValue());
  }

  SECTION("When the rule has an opt value set") {
    std::string optValue = "--";
    rule.setOptValue(optValue);
    REQUIRE(rule.getOptValue() == "--");
  }
}

TEST_CASE("RuleTest - get/set target") {
  Rule rule = Rule();

  Target target = Target::ACCEPT;
  rule.setTarget(target);

  REQUIRE(rule.getTarget() == Target::ACCEPT);
}

TEST_CASE("RuleTest - get/set protocol") {
  Rule rule = Rule();

  Protocol protocol = Protocol::ALL;
  rule.setProtocol(protocol);

  REQUIRE(rule.getProtocol() == Protocol::ALL);
}

TEST_CASE("RuleTest - get/set opt value") {
  Rule rule = Rule();

  std::string optValue = "--";
  rule.setOptValue(optValue);

  REQUIRE(rule.getOptValue() == "--");
}

TEST_CASE("RuleTest - get/set in value") {
  Rule rule = Rule();

  std::string inValue = "*";
  rule.setInValue(inValue);

  REQUIRE(rule.getInValue() == "*");
}

TEST_CASE("RuleTest - get/set out value") {
  Rule rule = Rule();

  std::string outValue = "*";
  rule.setOutValue(outValue);

  REQUIRE(rule.getOutValue() == "*");
}

TEST_CASE("RuleTest - get/set source address") {
  Rule rule = Rule();

  Address address = Address();
  rule.setSourceAddress(address);

  REQUIRE_NOTHROW(rule.getSourceAddress());
}

TEST_CASE("RuleTest - get/set destination address") {
  Rule rule = Rule();

  Address address = Address();
  rule.setDestinationAddress(address);

  REQUIRE_NOTHROW(rule.getDestinationAddress());
}

TEST_CASE("RuleTest - parse protocol to string") {
  Rule rule = Rule();

  SECTION("When the protocol is TCP") {
    Protocol protocol = Protocol::TCP;
    rule.setProtocol(protocol);
    REQUIRE(rule.parseProtocolToString() == "TCP");
  }

  SECTION("When the protocol is UDP") {
    Protocol protocol = Protocol::UDP;
    rule.setProtocol(protocol);
    REQUIRE(rule.parseProtocolToString() == "UDP");
  }

  SECTION("When the protocol is ICMP") {
    Protocol protocol = Protocol::ICMP;
    rule.setProtocol(protocol);
    REQUIRE(rule.parseProtocolToString() == "ICMP");
  }

  SECTION("When the protocol is ALL") {
    Protocol protocol = Protocol::ALL;
    rule.setProtocol(protocol);
    REQUIRE(rule.parseProtocolToString() == "ALL");
  }
}

TEST_CASE("RuleTest - parse target to string") {
  Rule rule = Rule();

  SECTION("When the target is ACCEPT") {
    Target target = Target::ACCEPT;
    rule.setTarget(target);
    REQUIRE(rule.parseTargetToString() == "ACCEPT");
  }

  SECTION("When the target is DROP") {
    Target target = Target::DROP;
    rule.setTarget(target);
    REQUIRE(rule.parseTargetToString() == "DROP");
  }

  SECTION("When the target is REJECT") {
    Target target = Target::REJECT;
    rule.setTarget(target);
    REQUIRE(rule.parseTargetToString() == "REJECT");
  }
}