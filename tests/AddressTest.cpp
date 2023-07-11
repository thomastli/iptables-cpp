#include "iptables/Address.hpp"
#include "tests/catch.hpp"

using namespace iptables;

TEST_CASE("AddressTest - hasHostName") {
  Address address = Address();

  SECTION("When host name is empty") {
    REQUIRE_FALSE(address.hasHostName());
  }

  SECTION("When host name is set") {
    std::string hostName = "localhost";
    address.setHostName(hostName);
    REQUIRE(address.hasHostName());
  }
}

TEST_CASE("AddressTest - hasIpAddress") {
  Address address = Address();

  SECTION("When the IP address is empty") {
    REQUIRE_FALSE(address.hasIpAddress());
  }

  SECTION("When the IP address is set") {
    std::vector<unsigned int> ipAddress = {127, 0, 0, 1};
    address.setIpAddress(ipAddress);
    REQUIRE(address.hasIpAddress());
  }
}

TEST_CASE("AddressTest - hasSubnetMask") {
  Address address = Address();

  SECTION("When the subnet mask is empty") {
    REQUIRE_FALSE(address.hasSubnetMask());
  }

  SECTION("When the subnet mask is set") {
    unsigned int subnetMask = 24;
    address.setSubnetMask(subnetMask);
    REQUIRE(address.hasSubnetMask());
  }
}

TEST_CASE("AddressTest - get/set hostname") {
  Address address = Address();

  std::string hostName = "localhost";
  address.setHostName(hostName);

  REQUIRE(address.getHostName() == "localhost");
}

TEST_CASE("AddressTest - get/set ip address") {
  Address address = Address();

  std::vector<unsigned int> ipAddress = {127, 0, 0, 1};
  address.setIpAddress(ipAddress);

  std::vector<unsigned int> expectedValue = {127, 0, 0, 1};
  REQUIRE(address.getIpAddress() == expectedValue);
}

TEST_CASE("AddressTest - get/set subnet mask") {
  Address address = Address();

  unsigned int subnetMask = 24;
  address.setSubnetMask(subnetMask);

  REQUIRE(address.getSubnetMask() == 24);
}

TEST_CASE("AddressTest - parse ip address from string") {
  Address address = Address();

  std::string addressAsString = "127.0.0.1";
  address.parseIpAddressFromString(addressAsString);

  std::vector<unsigned int> expectedValue = {127, 0, 0, 1};

  REQUIRE(address.getIpAddress() == expectedValue);
}

TEST_CASE("AddressTest - format ip address as string") {
  Address address = Address();

  std::vector<unsigned int> ipAddress = {127, 0, 0, 1};
  address.setIpAddress(ipAddress);

  std::string addressAsString = address.formatIpAddressToString();
  REQUIRE(addressAsString == "127.0.0.1");
}

TEST_CASE("AddressTest - format ip address as integer") {
  Address address = Address();

  std::vector<unsigned int> ipAddress = {127, 0, 0, 1};
  address.setIpAddress(ipAddress);

  int addressAsInteger = address.formatIpAddressAsInteger();
  REQUIRE(addressAsInteger == 2130706433);
}