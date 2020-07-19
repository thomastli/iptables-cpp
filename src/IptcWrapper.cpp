#include "iptables/IptcWrapper.hpp"

#include <string.h>

using namespace iptables;

void IptcWrapper::initializeIptcModule() {
  this->xtcHandle = iptc_init(tableName.c_str());
}

void IptcWrapper::cleanupIptcModule() {
  iptc_free(this->xtcHandle);
}

void IptcWrapper::appendRuleToChain(std::string& chainName, Rule& rule) {
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_append_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, xtcHandle);
  commitChangesToIpTables();
}

void IptcWrapper::deleteRuleFromChain(std::string& chainName, Rule& rule) {
  unsigned char* matchMask;

  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_delete_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, matchMask, xtcHandle);
  commitChangesToIpTables();
}

void IptcWrapper::insertRuleIntoChain(std::string& chainName, Rule& rule) {
  unsigned int ruleNum;
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_insert_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, ruleNum, xtcHandle);
  commitChangesToIpTables();
}

void IptcWrapper::replaceRuleInChain(std::string& chainName, Rule& rule) {
  unsigned int ruleNum;
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_replace_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, ruleNum, xtcHandle);
  commitChangesToIpTables();
}

void listAllRulesInChain(std::string& chainName) {}

void IptcWrapper::listRuleInChain(std::string& chainName, Rule& rule) {
  unsigned char* matchMask;
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_check_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, matchMask, xtcHandle);
  commitChangesToIpTables();
}

void IptcWrapper::generateIptEntry(Rule& rule, ipt_entry& iptEntry) {
  generateOffset(iptEntry);

  Address source = rule.getSourceAddress();
  generateSource(source, iptEntry);

  Address destination = rule.getSourceAddress();
  generateDestination(destination, iptEntry);
}

void IptcWrapper::generateOffset(ipt_entry& iptEntry) {
  iptEntry.target_offset = sizeof(xt_entry_target);
  iptEntry.next_offset = iptEntry.target_offset + sizeof(xt_entry_target);
}

void IptcWrapper::generateSource(Address& source, ipt_entry& iptEntry) {
  iptEntry.ip.src.s_addr = source.formatIpAddressAsInteger();
  iptEntry.ip.smsk.s_addr = source.getSubnetMask();
  iptEntry.ip.invflags;
}

void IptcWrapper::generateDestination(Address& destination, ipt_entry& iptEntry) {
  iptEntry.ip.dst.s_addr = destination.formatIpAddressAsInteger();
  iptEntry.ip.dmsk.s_addr = destination.getSubnetMask();
  iptEntry.ip.invflags;
}

int IptcWrapper::commitChangesToIpTables() {
  int errorCode = iptc_commit(xtcHandle);
  return errorCode;
}