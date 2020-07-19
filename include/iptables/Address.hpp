#ifndef IP_ADDRESS_HPP
#define IP_ADDRESS_HPP

#include <string>
#include <vector>

namespace iptables {
class Address {
 public:
  /**
   * @brief Construct a new Ip Address object
   *
   */
  Address() {}

  /**
   * @brief Destroy the Ip Address object
   *
   */
  ~Address() {}

  /**
   * @brief Checks to see if an ip address set
   *
   * @return true   If the ipAddress is set
   * @return false  Otherwise
   */
  bool hasIpAddress();

  /**
   * @brief Checks to see if a hostname is set
   *
   * @return true   If the ip address is set
   * @return false  Otherwise
   */
  bool hasHostName();

  /**
   * @brief Checks to see if a subnet mask is set
   *
   * @return true
   * @return false
   */
  bool hasSubnetMask();

  /**
   * @brief Get the ip address
   *
   * @return std::vector<unsigned int>  The ip address
   */
  std::vector<unsigned int> getIpAddress();

  /**
   * @brief Get the host name
   *
   * @return std::string  The host name
   */
  std::string getHostName();

  /**
   * @brief Get the subnet mask
   *
   * @return int The subnet mask
   */
  int getSubnetMask();

  /**
   * @brief Set the ip address
   *
   * @param ipAddress The ip address
   */
  void setIpAddress(std::vector<unsigned int>& ipAddress);

  /**
   * @brief Set the host name
   *
   * @param hostName  The host name
   */
  void setHostName(std::string& hostName);

  /**
   * @brief Set the subnet mask
   *
   * @param subnetMask  The subnet mask
   */
  void setSubnetMask(int subnetMask);

  /**
   * @brief Parse an ip address from std::string
   *
   * @param address The ip address, as a string
   */
  void parseIpAddressFromString(std::string& address);

  std::string formatIpAddressToString();

  int formatIpAddressAsInteger();

 private:
  std::vector<unsigned int> ipAddress;
  std::string hostName;
  int subnetMask = -1;
};
}  // namespace iptables
#endif  // !IP_ADDRESS_HPP