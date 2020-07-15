#include "iptables/IpAddress.hpp"
#include "tests/catch.hpp"

using namespace iptables;

SCENARIO("IpAddressTest - parse ip address from string") {
  IpAddress ipAddress = IpAddress();

  std::string address = "192.169.0.1/24";
  ipAddress.parseIpAddressFromString(address);
}

SCENARIO("IpAddressTest - convert ip address to string") {
  IpAddress ipAddress = IpAddress();
}