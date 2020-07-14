#include "include/catch.hpp"
#include "iptables/IpRule.hpp"

using namespace iptables;

SCENARIO("IpRuleTest - get/set num id") {
  IpRule ipRule = IpRule();

  unsigned int numId = 0;
  ipRule.setNumId(numId);

  REQUIRE(ipRule.getNumId() == 0);
}

SCENARIO("IpRuleTest - get/set target") {
  IpRule ipRule = IpRule();

  Target target = Target::ACCEPT;
  ipRule.setTarget(target);

  REQUIRE(ipRule.getTarget() == Target::ACCEPT);
}

SCENARIO("IpRuleTest - get/set protocol") {
  IpRule ipRule = IpRule();

  Protocol protocol = Protocol::ALL;
  ipRule.setProtocol(protocol);

  REQUIRE(ipRule.getProtocol() == Protocol::ALL);
}