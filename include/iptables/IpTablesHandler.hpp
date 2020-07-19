#ifndef IP_TABLES_HANDLER_HPP
#define IP_TABLES_HANDLER_HPP

#include <string>

#include "iptables/ChainMap.hpp"
#include "iptables/Rule.hpp"

namespace iptables {
class IpTablesHandler {
 public:
  /**
   * @brief Construct a new Ip Tables Handler object
   *
   */
  IpTablesHandler() {}

  /**
   * @brief Destroy the Ip Tables Handler object
   *
   */
  ~IpTablesHandler() {}

  /**
   * @brief Initialize the handler
   *
   */
  void initialize();

  /**
   * @brief Shutdown the handler
   *
   */
  void shutdown();

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
  void insertRuleIntoChain(std::string& chainName, unsigned int ruleNum, Rule& rule);

  /**
   * @brief Replace chain in iptables
   *
   * @param chainName
   */
  void replaceRuleInChain(std::string& chainName, unsigned int ruleNum, Rule& rule);

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
  /**
   * @brief Format entry for ip tables
   *
   * @param rule            The rule object
   * @return std::string    Formatted string
   */
  std::string formatEntryForIpTables(Rule& rule);

  /**
   * @brief Commit entyr to ip tables
   *
   * @param entry   The entry, formatted a string
   */
  void commitEntryToIpTables(std::string& entry);

  ChainMap* chainMap;
};
}  // namespace iptables
#endif  // !IP_TABLES_HANDLER_HPP