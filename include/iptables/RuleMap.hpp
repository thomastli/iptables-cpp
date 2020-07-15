#ifndef RULE_MAP_HPP
#define RULE_MAP_HPP

#include <map>

#include "iptables/Rule.hpp"

namespace iptables {
/**
 * @brief Class to represent iptables as a map
 *
 */
class RuleMap {
 public:
  /**
   * @brief Construct a new Ip Tables object
   *
   */
  RuleMap() {}

  /**
   * @brief Destroy the Ip Tables object
   *
   */
  ~RuleMap() {}

  /**
   * @brief Add an rule to the rule map
   *
   * @param rule  The rule object
   */
  void addRuleToRuleMap(unsigned int numId, Rule& rule);

  /**
   * @brief Retrieve ip rule from rule map
   *
   * @param numId   The number id
   * @return Rule   The rule object
   */
  Rule retrieveRuleFromRuleMap(unsigned int numId);

  /**
   * @brief Delete anrule from rule map
   *
   * @param numId   The number id
   */
  void deleteRuleFromRuleMap(unsigned int numId);

 private:
  std::map<unsigned int, Rule> ruleMap;
};
}  // namespace iptables
#endif  // !IP_TABLES_MAP_HPP