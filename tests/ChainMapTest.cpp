#include "iptables/ChainMap.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("ChainMapTest -  add chain to the map") {
  ChainMap chainMap = ChainMap();

  std::string chainName = "INPUT";
  Chain chain = Chain();
  chainMap.addChainToMap(chainName, chain);

  Chain retrievedChain = chainMap.retrieveChainFromMap(chainName);
}

SCENARIO("ChainMapTest - delete chain to the map") {
  ChainMap chainMap = ChainMap();

  std::string chainName = "CUSTOM";
  Chain chain = Chain();
  chainMap.addChainToMap(chainName, chain);

  chainMap.deleteChainFromMap(chainName);
}

SCENARIO("ChainMapTest - retrieve chain from the map") {
  ChainMap chainMap = ChainMap();

  std::string chainName = "INPUT";
  Chain chain = Chain();
  chainMap.addChainToMap(chainName, chain);

  Chain retrievedChain = chainMap.retrieveChainFromMap(chainName);
})