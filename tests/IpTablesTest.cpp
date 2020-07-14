#include "iptables/IpRule.hpp"
#include "iptables/IpTablesMap.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("IpTablesMap - add rule to ip tables map") {
  IpTablesMap ipTablesMap = IpTablesMap();

  WHEN("I add an ip rule to the map") {
    IpRule ipRule = IpRule();
    ipTablesMap.addRuleToIpTablesMap();
    THEN("I expect the ip rule is in the map") {}
  }
}

SCENARIO("IpTablesMap - delete rule to ip tables map") {
  IpTablesMap ipTablesMap = IpTablesMap();

  WHEN("I have an existing value in the map") {
    IpRule ipRule = IpRule();
    ipTablesMap.addRuleToIpTablesMap(ipRule);

    AND_WHEN("I delete a rule from the map") {
      ipTablesMap.deleteRuleFromIpTablesMap(ipRule);

      THEN("I expect the rule to no longer be in the map") {}
    }
  }
}

SCENARIO("IpTablesMap - modify existing rule in ip tables map") {
  IpTablesMap ipTablesMap = IpTablesMap();

  WHEN("I have an existing value in the map") {
    IpRule ipRule = IpRule();
    ipTablesMap.addRuleToIpTablesMap(ipRule);

    AND_WHEN("I modify an existing rule") {
      IpRule newIpRule = IpRule();
      ipTablesMap.modifyRuleFromIpTables(newIpRule);

      THEN("I expect the rule to have its contents modified") {}
    }
  }
}