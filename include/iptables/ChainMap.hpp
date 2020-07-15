#ifndef CHAIN_MAP_HPP
#define CHAIN_MAP_HPP

#include "iptables/Chain.hpp"

namespace iptables {
class ChainMap {
 public:
  /**
   * @brief Construct a new Chain Map object
   *
   */
  ChainMap() {}

  /**
   * @brief Destroy the Chain Map object
   *
   */
  ~ChainMap() {}

  /**
   * @brief Add chain from map
   *
   * @param chain
   */
  void addChainToMap(std::string& chainName, Chain& chain);

  /**
   * @brief Retrieve chain from the map
   *
   * @param chainName   The chain name
   * @return Chain      The chain object
   */
  Chain retrieveChainFromMap(std::string& chainName);

  /**
   * @brief Delete chain from map
   *
   * @param chainName
   */
  void deleteChainFromMap(std::string& chainName);

 private:
  std::map<std::string, Chain> chainMap;
};
}  // namespace iptables
#endif  // !CHAIN_MAP_HPP