#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <map>
#include <string>

#include "iptables/Rule.hpp"

namespace iptables {
class Chain {
 public:
  /**
   * @brief Construct a new Chain object
   *
   */
  Chain() {}

  /**
   * @brief Destroy the Chain object
   *
   */
  ~Chain() {}

  /**
   * @brief Add a rule to the chain
   *
   * @param ruleNum The rule number
   * @param rule    The rule object
   */
  void addRuleToChain(unsigned int ruleNum, Rule& rule);

  /**
   * @brief Modify rule in the chain
   *
   * @param ruleNum The rule number
   * @param rule    The rule object
   */
  void modifyRuleInChain(unsigned int ruleNum, Rule& rule);

  /**
   * @brief Retrieve rule from the chain
   *
   * @param ruleNum The rule number
   * @return Rule   The rule object
   */
  Rule retrieveRuleFromChain(unsigned int ruleNum);

  /**
   * @brief Delete rule from the chain
   *
   * @param ruleNum The rule number
   */
  void deleteRuleFromChain(unsigned int ruleNum);

 private:
  std::map<unsigned int, Rule> ruleMap;
};
}  // namespace iptables
#endif  // !CHAIN_HPP