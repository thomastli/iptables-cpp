#include "iptables/Address.hpp"

#include <iostream>
#include <regex>
#include <sstream>

static const char IP_ADDRESS_DELIMITER = '.';
static const std::string IP_REGEX_PATTERN = "localhost|[0-9]+\\.[0-9]+\\.[0-9]+\\.[0-9]+";

using namespace iptables;

bool Address::hasHostName() {
  bool result = false;
  if (!hostName.empty()) {
    result = true;
  }
  return result;
}

bool Address::hasIpAddress() {
  bool result = false;
  if (!ipAddress.empty()) {
    result = true;
  }
  return result;
}

bool Address::hasSubnetMask() {
  bool result = false;
  if (subnetMask >= 0) {
    result = true;
  }
  return result;
}

std::string Address::getHostName() {
  return this->hostName;
}

std::vector<unsigned int> Address::getIpAddress() {
  return this->ipAddress;
}

int Address::getSubnetMask() {
  return this->subnetMask;
}

void Address::setHostName(std::string& hostName) {
  this->hostName = hostName;
}

void Address::setIpAddress(std::vector<unsigned int>& ipAddress) {
  this->ipAddress = ipAddress;
}

void Address::setSubnetMask(int subnetMask) {
  this->subnetMask = subnetMask;
}

void Address::parseIpAddressFromString(std::string& address) {
  std::stringstream sstream(address);

  std::string substr;
  while (std::getline(sstream, substr, '.')) {
    unsigned int value = stoi(substr);
    this->ipAddress.push_back(value);
  }
}

std::string Address::formatIpAddressToString() {
  std::string ipAddressAsString = "";

  ipAddressAsString += std::to_string(ipAddress[0]);

  for (int i = 1; i < ipAddress.size(); i++) {
    ipAddressAsString += "." + std::to_string(ipAddress[i]);
  }

  return ipAddressAsString;
}

bool isValidIpAddress(std::string& address) {
  bool result = false;

  std::regex ipRegex = std::regex(IP_REGEX_PATTERN, std::regex_constants::ECMAScript);
  result = std::regex_match(address, ipRegex);

  return result;
}
