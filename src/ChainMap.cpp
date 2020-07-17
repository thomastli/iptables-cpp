#include "iptables/ChainMap.hpp"

using namespace iptables;

void ChainMap::addChainToMap(std::string& chainName, Chain& chain) {
  chainMap[chainName] = chain;
}

Chain ChainMap::retrieveChainFromMap(std::string& chainName) {
  Chain retrievedChain = chainMap[chainName];
  return retrievedChain;
}

void ChainMap::deleteChainFromMap(std::string& chainName) {
  chainMap.erase(chainName);
}

bool ChainMap::hasChainInMap(std::string& chainName) {
  bool result = false;

  std::map<std::string, Chain>::iterator itr = chainMap.find(chainName);
  if (itr != chainMap.end()) {
    result = true;
  }

  return result;
}