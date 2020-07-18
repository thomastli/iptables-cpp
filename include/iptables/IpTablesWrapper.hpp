#ifndef IP_TABLES_WRAPPER_HPP
#define IP_TABLES_WRAPPER_HPP

#include "iptables/Rule.hpp"
#include "iptables/RuleMap.hpp"

namespace iptables {
class IpTablesWrapper {
 public:
  /**
   * @brief Construct a new Ip Tables Wrapper object
   *
   */
  IpTablesWrapper();

  /**
   * @brief Destroy the Ip Tables Wrapper object
   *
   */
  ~IpTablesWrapper();

  /**
   * @brief List all ip rules in the ip tables map
   *
   */
  void listRulesFromIpTable();

  /**
   * @brief Add an Rule to the ip tables map
   *
   * @param rule    Rule object
   */
  void addRuleToIpTable(Rule& rule);

  /**
   * @brief Delete an Rule from the ip tables map
   *
   * @param rule    Rule object
   */
  void deleteRuleFromIpTable(Rule& rule);

  /**
   * @brief Modify an existing Rule from the ip tables map
   *
   * @param rule    Rule object
   */
  void modifyRuleFromIpTable(Rule& rule);

 private:
  RuleMap ruleMap;
};
}  // namespace iptables
#endif  // !IP_TABLES_WRAPPER_HPP