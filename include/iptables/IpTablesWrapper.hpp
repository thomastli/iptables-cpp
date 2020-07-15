#ifndef IP_TABLES_WRAPPER_HPP
#define IP_TABLES_WRAPPER_HPP

#include "iptables/IpRule.hpp"
#include "iptables/IpTablesMap.hpp"

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
   * @brief Add an IpRule to the ip tables map
   *
   * @param ipRule    IpRule object
   */
  void addRuleToIpTable(IpRule& ipRule);

  /**
   * @brief Delete an IpRule from the ip tables map
   *
   * @param ipRule    IpRule object
   */
  void deleteRuleFromIpTable(IpRule& ipRule);

  /**
   * @brief Modify an existing IpRule from the ip tables map
   *
   * @param ipRule    IpRule object
   */
  void modifyRuleFromIpTable(IpRule& ipRule);

 private:
  IpTablesMap ipTablesMap;
};
}  // namespace iptables
#endif  // !IP_TABLES_WRAPPER_HPP