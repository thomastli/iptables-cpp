#ifndef IP_ADDRESS_HPP
#define IP_ADDRESS_HPP

#include <string>
#include <vector>

namespace iptables {
class IpAddress {
 public:
  /**
   * @brief Construct a new Ip Address object
   *
   */
  IpAddress() {}

  /**
   * @brief Destroy the Ip Address object
   *
   */
  ~IpAddress() {}

  /**
   * @brief Parse an ip address from std::string
   *
   * @param address The ip address, as a string
   */
  void parseIpAddressFromString(std::string& address);

  /**
   * @brief Convert an IpAddress object into a std::string
   *
   * @return std::string
   */
  std::string convertIpAddressToString();

 private:
  std::vector<unsigned int> address;
  unsigned int subnetMask;
};
}  // namespace iptables
#endif  // !IP_ADDRESS_HPP