#include "iptables/ChainMap.hpp"
#include "tests/catch.hpp"

using namespace iptables;

TEST_CASE("ChainMapTest -  add chain to the map") {
  ChainMap chainMap = ChainMap();

  std::string chainName = "INPUT";
  Chain chain = Chain();
  chainMap.addChainToMap(chainName, chain);

  REQUIRE(chainMap.hasChainInMap(chainName));
}

TEST_CASE("ChainMapTest - delete chain to the map") {
  ChainMap chainMap = ChainMap();

  std::string chainName = "CUSTOM";
  Chain chain = Chain();
  chainMap.addChainToMap(chainName, chain);

  chainMap.deleteChainFromMap(chainName);

  REQUIRE(!chainMap.hasChainInMap(chainName));
}

TEST_CASE("ChainMapTest - retrieve chain from the map") {
  ChainMap chainMap = ChainMap();

  std::string chainName = "INPUT";
  Chain chain = Chain();
  chainMap.addChainToMap(chainName, chain);

  Chain retrievedChain = chainMap.retrieveChainFromMap(chainName);
}

TEST_CASE("ChainMapTest - has chain in map") {
  ChainMap chainMap = ChainMap();

  std::string chainName = "INPUT";

  SECTION("If chain does not exist in the map") {
    REQUIRE_FALSE(chainMap.hasChainInMap(chainName));
  }

  SECTION("If chain does exist in the map") {
    Chain chain = Chain();
    chainMap.addChainToMap(chainName, chain);
    REQUIRE(chainMap.hasChainInMap(chainName));
  }
}