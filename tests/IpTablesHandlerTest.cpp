#include "iptables/IpTablesHandler.hpp"
#include "tests/catch.hpp"

using namespace iptables;

TEST_CASE("IpTablesHandler - append rule to chain") {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  Rule rule = Rule();
  std::string chain = "INPUT";

  SECTION("Append empty rule") {
    ipTablesHandler.appendRuleToChain(chain, rule);
  }

  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::TCP;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);
  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);
  std::string in_value = "eth0";
  std::string out_value = "lo";

  rule.setTarget(target);
  rule.setProtocol(protocol);
  rule.setSourceAddress(source);
  rule.setDestinationAddress(destination);
  rule.setInValue(in_value);
  rule.setOutValue(out_value);

  SECTION("Appending a rule to a new chain") {
    REQUIRE_NOTHROW(ipTablesHandler.appendRuleToChain(chain, rule));
  }

  SECTION("When the chain already exists") {
    Rule newRule = Rule();
    target = Target::DROP;
    protocol = Protocol::UDP;

    sourceAddr = "8.8.8.8";
    source = Address();
    source.parseIpAddressFromString(sourceAddr);
    destAddr = "127.0.0.1";
    destination = Address();
    destination.parseIpAddressFromString(destAddr);

    newRule.setTarget(target);
    newRule.setProtocol(protocol);
    newRule.setSourceAddress(source);
    newRule.setDestinationAddress(destination);

    ipTablesHandler.appendRuleToChain(chain, rule);
    REQUIRE_NOTHROW(ipTablesHandler.appendRuleToChain(chain, newRule));
  }

  ipTablesHandler.shutdown();
}

TEST_CASE("IpTablesHandler - delete rule from chain") {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  Rule rule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  rule.setTarget(target);
  rule.setProtocol(protocol);
  rule.setSourceAddress(source);
  rule.setDestinationAddress(destination);

  std::string chain = "INPUT";

  SECTION("Deleting a rule from a chain that does not exist") {
    REQUIRE_NOTHROW(ipTablesHandler.deleteRuleFromChain(chain, rule));
  }

  SECTION("Deleting a rule from a chain that does exist") {
    ipTablesHandler.appendRuleToChain(chain, rule);
    REQUIRE_NOTHROW(ipTablesHandler.deleteRuleFromChain(chain, rule));
  }

  ipTablesHandler.shutdown();
}

TEST_CASE("IpTablesHandler - insert rule into chain") {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  Rule rule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  rule.setTarget(target);
  rule.setProtocol(protocol);
  rule.setSourceAddress(source);
  rule.setDestinationAddress(destination);

  std::string chainName = "INPUT";
  unsigned int ruleNum = 1;

  SECTION("Inserting a rule into a new chain") {
    REQUIRE_NOTHROW(ipTablesHandler.insertRuleIntoChain(chainName, ruleNum, rule));
  }

  SECTION("Insert a rule into an existing chain") {
    REQUIRE_NOTHROW(ipTablesHandler.appendRuleToChain(chainName, rule));
    REQUIRE_NOTHROW(ipTablesHandler.insertRuleIntoChain(chainName, ruleNum, rule));
  }

  ipTablesHandler.shutdown();
}

TEST_CASE("IpTablesHandler - replace rule in chain") {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  Rule rule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  rule.setTarget(target);
  rule.setProtocol(protocol);
  rule.setSourceAddress(source);
  rule.setDestinationAddress(destination);

  std::string chainName = "INPUT";
  unsigned int ruleNum = 1;

  SECTION("Replace rule in new chain") {
    REQUIRE_NOTHROW(ipTablesHandler.replaceRuleInChain(chainName, ruleNum, rule));
  }

  SECTION("Replace rule in an existing chain") {
    Rule newRule = Rule();
    Target target = Target::DROP;
    Protocol protocol = Protocol::UDP;

    std::string sourceAddr = "8.8.8.8";
    Address source = Address();
    source.parseIpAddressFromString(sourceAddr);
    std::string destAddr = "127.0.0.1";
    Address destination = Address();
    destination.parseIpAddressFromString(destAddr);

    newRule.setTarget(target);
    newRule.setProtocol(protocol);
    newRule.setSourceAddress(source);
    newRule.setDestinationAddress(destination);

    REQUIRE_NOTHROW(ipTablesHandler.appendRuleToChain(chainName, rule));
    REQUIRE_NOTHROW(ipTablesHandler.replaceRuleInChain(chainName, ruleNum, newRule));
  }

  ipTablesHandler.shutdown();
}