#include "iptables/IpTablesHandler.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("IpTablesHandler - append rule to chain") {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  Rule appendRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::TCP;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);
  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  appendRule.setTarget(target);
  appendRule.setProtocol(protocol);
  appendRule.setSourceAddress(source);
  appendRule.setDestinationAddress(destination);

  std::string inputChain = "INPUT";
  REQUIRE_NOTHROW(ipTablesHandler.appendRuleToChain(inputChain, appendRule));

  ipTablesHandler.shutdown();
}

SCENARIO("IpTablesHandler - insert rule into chain") {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  Rule insertRule = Rule();
  Target target = Target::ACCEPT;
  Protocol protocol = Protocol::ALL;

  std::string sourceAddr = "8.8.8.8";
  Address source = Address();
  source.parseIpAddressFromString(sourceAddr);

  std::string destAddr = "127.0.0.1";
  Address destination = Address();
  destination.parseIpAddressFromString(destAddr);

  insertRule.setTarget(target);
  insertRule.setProtocol(protocol);
  insertRule.setSourceAddress(source);
  insertRule.setDestinationAddress(destination);

  std::string chainName = "INPUT";
  unsigned int ruleNum = 1;
  REQUIRE_NOTHROW(ipTablesHandler.insertRuleIntoChain(chainName, ruleNum, insertRule));

  ipTablesHandler.shutdown();
}

SCENARIO("IpTablesHandler - delete rule from chain") {
  IpTablesHandler ipTablesHandler = IpTablesHandler();
  ipTablesHandler.initialize();

  GIVEN("I append a rule to the chain") {
    Rule appendRule = Rule();
    Target target = Target::ACCEPT;
    Protocol protocol = Protocol::ALL;

    std::string sourceAddr = "8.8.8.8";
    Address source = Address();
    source.parseIpAddressFromString(sourceAddr);
    std::string destAddr = "127.0.0.1";
    Address destination = Address();
    destination.parseIpAddressFromString(destAddr);

    appendRule.setTarget(target);
    appendRule.setProtocol(protocol);
    appendRule.setSourceAddress(source);
    appendRule.setDestinationAddress(destination);

    std::string inputChain = "INPUT";
    ipTablesHandler.appendRuleToChain(inputChain, appendRule);
  }

  WHEN("I delete the same rule in the chain") {
    Rule deleteRule = Rule();
    Target target = Target::ACCEPT;
    Protocol protocol = Protocol::ALL;

    std::string sourceAddr = "8.8.8.8";
    Address source = Address();
    source.parseIpAddressFromString(sourceAddr);

    std::string destAddr = "127.0.0.1";
    Address destination = Address();
    destination.parseIpAddressFromString(destAddr);

    deleteRule.setTarget(target);
    deleteRule.setProtocol(protocol);
    deleteRule.setSourceAddress(source);
    deleteRule.setDestinationAddress(destination);

    std::string chainName = "INPUT";
    unsigned int ruleNum = 0;

    THEN("I expect to be able to delete the rule successfully") {
      ipTablesHandler.deleteRuleFromChain(chainName, deleteRule);
    }
  }

  ipTablesHandler.shutdown();
}