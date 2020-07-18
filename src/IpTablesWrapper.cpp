#include "iptables/IpTablesWrapper.hpp"

#include <string.h>

using namespace iptables;

void IpTablesWrapper::initializeIpTablesModule() {
  this->xtcHandle = iptc_init(tableName.c_str());
}

void IpTablesWrapper::cleanupIpTablesModule() {
  iptc_free(this->xtcHandle);
}

void IpTablesWrapper::appendRuleToChain(std::string& chainName, Rule& rule) {
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_append_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, xtcHandle);
  commitChangesToIpTables();
}

void IpTablesWrapper::deleteRuleFromChain(std::string& chainName, Rule& rule) {
  ipt_chainlabel chainLabel;
  unsigned char* matchMask;

  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_delete_entry(chainLabel, (struct ipt_entry*)&iptEntry, matchMask, xtcHandle);
  commitChangesToIpTables();
}

void IpTablesWrapper::insertRuleIntoChain(std::string& chainName, Rule& rule) {
  unsigned int ruleNum;
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_insert_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, ruleNum, xtcHandle);
  commitChangesToIpTables();
}

void IpTablesWrapper::replaceRuleInChain(std::string& chainName, Rule& rule) {
  unsigned int ruleNum;
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_replace_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, ruleNum, xtcHandle);
  commitChangesToIpTables();
}

void listAllRulesInChain(std::string& chainName) {}

void IpTablesWrapper::listRuleInChain(std::string& chainName, Rule& rule) {
  unsigned char* matchMask;
  struct ipt_entry iptEntry;
  generateIptEntry(rule, iptEntry);

  iptc_check_entry(chainName.c_str(), (struct ipt_entry*)&iptEntry, matchMask, xtcHandle);
  commitChangesToIpTables();
}

void IpTablesWrapper::generateIptEntry(Rule& rule, ipt_entry& iptEntry) {
  generateOffset(iptEntry);

  Address source = rule.getSourceAddress();
  generateSource(source, iptEntry);

  Address destination = rule.getSourceAddress();
  generateDestination(destination, iptEntry);
}

void IpTablesWrapper::generateOffset(ipt_entry& iptEntry) {
  iptEntry.target_offset = sizeof(xt_entry_target);
  iptEntry.next_offset = iptEntry.target_offset + sizeof(xt_entry_target);
}

void IpTablesWrapper::generateSource(Address& source, ipt_entry& iptEntry) {
  iptEntry.ip.src.s_addr;
  iptEntry.ip.smsk.s_addr;
  iptEntry.ip.invflags;
}

void IpTablesWrapper::generateDestination(Address& destination, ipt_entry& iptEntry) {
  iptEntry.ip.dst.s_addr;
  iptEntry.ip.dmsk.s_addr;
  iptEntry.ip.invflags;
}

int IpTablesWrapper::commitChangesToIpTables() {
  int errorCode = iptc_commit(xtcHandle);
  return errorCode;
}