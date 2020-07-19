#ifndef IP_TABLES_WRAPPER_HPP
#define IP_TABLES_WRAPPER_HPP

#include <libiptc/libiptc.h>

#include "iptables/Chain.hpp"
#include "iptables/Rule.hpp"
#include "iptables/RuleMap.hpp"

namespace iptables {
class IptcWrapper {
 public:
  /**
   * @brief Construct a new Ip Tables Wrapper object
   *
   */
  IptcWrapper();

  /**
   * @brief Destroy the Ip Tables Wrapper object
   *
   */
  ~IptcWrapper();

  /**
   * @brief Initialize the ip tables module
   *
   * @param tableName
   */
  void initializeIptcModule();

  /**
   * @brief Cleanup the iptables module
   *
   */
  void cleanupIptcModule();

  /**
   * @brief Append chain to iptables
   *
   * @param chainName
   * @param ruleNum
   */
  void appendRuleToChain(std::string& chainName, Rule& rule);

  /**
   * @brief Delete chain from iptables
   *
   * @param chainName
   */
  void deleteRuleFromChain(std::string& chainName, Rule& rule);

  /**
   * @brief Insert chain in iptables
   *
   * @param chainName
   */
  void insertRuleIntoChain(std::string& chainName, Rule& rule);

  /**
   * @brief Replace chain in iptables
   *
   * @param chainName
   */
  void replaceRuleInChain(std::string& chainName, Rule& rule);

  /**
   * @brief List all chains in iptables
   *
   */
  void listAllRulesInChain(std::string& chainName);

  /**
   * @brief List chain rule in iptables
   *
   */
  void listRuleInChain(std::string& chainName, Rule& rule);

 private:
  void generateIptEntry(Rule& rule, ipt_entry& iptEntry);
  void generateOffset(ipt_entry& iptEntry);
  void generateSource(Address& source, ipt_entry& iptEntry);
  void generateDestination(Address& destionation, ipt_entry& iptEntry);
  int commitChangesToIpTables();

  std::string tableName;
  xtc_handle* xtcHandle;
  RuleMap ruleMap;
};
}  // namespace iptables
#endif  // !IP_TABLES_WRAPPER_HPP