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
   * @brief Add a rule to the rule map
   *
   * @param rule  The rule object
   */
  void addRuleToRuleMap(Rule& rule);

  /**
   * @brief Insert rule into rule map
   *
   * @param ruleNum The rule number
   * @param rule    The rule object
   */
  void insertRuleIntoRuleMap(unsigned int ruleNum, Rule& rule);

  /**
   * @brief Retrieve a rule from rule map
   *
   * @param ruleNum   The rule number
   * @return Rule   The rule object
   */
  Rule retrieveRuleFromRuleMap(unsigned int ruleNum);

  /**
   * @brief Delete a rule from rule map
   *
   * @param ruleNum   The rule number
   */
  void deleteRuleFromRuleMap(unsigned int ruleNum);

  /**
   * @brief Has a rule in the rule map
   *
   * @param int     The rule number
   * @return true   If present in the map
   * @return false  Otherwise
   */
  bool hasRuleInMap(unsigned int ruleNum);

 private:
  std::vector<Rule> ruleMap;
};
}  // namespace iptables
#endif  // !IP_TABLES_MAP_HPP