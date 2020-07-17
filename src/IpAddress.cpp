#include <regex>

#include "iptables/IpAddress.hpp"

static constexpr char* IP_REGEX_PATTERN = "localhost|[0-9]+\\.[0-9]+\\.[0-9]+\\.[0-9]+[/0-9]*";

using namespace iptables;

void IpAddress::parseIpAddressFromString(std::string& address) {}

bool isValidIpAddress(std::string& address) {
  bool result = false;

  std::regex ipRegex = std::regex(IP_REGEX_PATTERN, std::regex_constants::ECMAScript);
  result = std::regex_match(address, ipRegex);

  return result;
}
