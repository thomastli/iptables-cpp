#include "iptables/IpTablesMap.hpp"

using namespace iptables;

void IpTablesMap::listIpTablesRulesFromMap() {}

void IpTablesMap::addRuleToIpTablesMap(IpRule& ipRule) {
  unsigned int numId = ipRule.getNumId();
  ipTablesMap[numId] = ipRule;
}

void IpTablesMap::deleteRuleFromIpTablesMap(IpRule& ipRule) {
  unsigned int numId = ipRule.getNumId();
  ipTablesMap.erase(numId);
}

void IpTablesMap::modifyRuleFromIpTables(IpRule& ipRule) {
  unsigned int numId = ipRule.getNumId();
  ipTablesMap[numId] = ipRule;
}
