#include "iptables/Address.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("AddressTest - get/set hostname") {
  Address address = Address();

  std::string hostName = "localhost";
  address.setHostName(hostName);

  REQUIRE(address.getHostName() == "localhost");
}

SCENARIO("AddressTest - get/set ip address") {
  Address address = Address();

  std::vector<unsigned int> ipAddress = {127, 0, 0, 1};
  address.setIpAddress(ipAddress);

  std::vector<unsigned int> expectedValue = {127, 0, 0, 1};
  REQUIRE(address.getIpAddress() == expectedValue);
}

SCENARIO("AddressTest - get/set subnet mask") {
  Address address = Address();

  unsigned int subnetMask = 24;
  address.setSubnetMask(subnetMask);

  REQUIRE(address.getSubnetMask() == 24);
}

SCENARIO("AddressTest - parse ip address from string") {
  Address address = Address();

  std::string addressAsString = "127.0.0.1";
  address.parseIpAddressFromString(addressAsString);

  std::vector<unsigned int> expectedValue = {127, 0, 0, 1};

  REQUIRE(address.getIpAddress() == expectedValue);
}

SCENARIO("AddressTest - format ip address as string") {
  Address address = Address();

  std::vector<unsigned int> ipAddress = {127, 0, 0, 1};
  address.setIpAddress(ipAddress);

  std::string addressAsString = address.formatIpAddressToString();
  REQUIRE(addressAsString == "127.0.0.1");
}