#ifndef RULE_HPP
#define RULE_HPP

#include <string>

#include "iptables/IpAddress.hpp"

enum class Target { ACCEPT, DECLINE };
enum class Protocol { TCP, UDP, ALL };

namespace iptables {
/**
 * @brief An individual rule from the iptables map
 *
 */
class Rule {
 public:
  /**
   * @brief Construct a new Ip Rule object
   *
   */
  Rule() {}

  /**
   * @brief Destroy the Ip Rule object
   *
   */
  ~Rule() {}

  /**
   * @brief Get the target from the Rule object
   *
   * @return Target   The target object
   */
  Target getTarget();

  /**
   * @brief Get the protocol from the Rule object
   *
   * @return Protocol  The proctocol name
   */
  Protocol getProtocol();

  /**
   * @brief Get the opt value from the Rule object
   *
   * @return std::string  The opt value
   */
  std::string getOptValue();

  /**
   * @brief Get the in value from the Rule object
   *
   * @return std::string  The in value
   */
  std::string getInValue();

  /**
   * @brief Get the out value from the Rule object
   *
   * @return std:;string  The out value
   */
  std::string getOutValue();

  /**
   * @brief Get the source address from the Rule obejct
   *
   * @return IpAddress  The source address
   */
  IpAddress getSourceAddress();

  /**
   * @brief Get the destination address from the Rule object
   *
   * @return IpAddress  The destination address
   */
  IpAddress getDestinationAddress();

  /**
   * @brief Set the target for the Rule object
   *
   * @param target    The target object
   */
  void setTarget(Target& target);

  /**
   * @brief Set the protocol for the Rule object
   *
   * @param protocol  The protocol object
   */
  void setProtocol(Protocol& protocol);

  /**
   * @brief Set the opt value for the Rule object
   *
   * @param opt   The opt value
   */
  void setOptValue(std::string& opt);

  /**
   * @brief Set the in value for the Rule object
   *
   * @param in    Set the in value
   */
  void setInValue(std::string& in);

  /**
   * @brief Set the out value for the Rule object
   *
   * @param out   Set the out value
   */
  void setOutValue(std::string& out);

  /**
   * @brief Set the source address for the Rule object
   *
   * @param source
   */
  void setSourceAddress(IpAddress& source);

  /**
   * @brief Set the destination address for the Rule object
   *
   * @param destination
   */
  void setDestinationAddress(IpAddress& destination);

 private:
  Target target;
  Protocol protocol;
  std::string opt;
  std::string in;
  std::string out;
  IpAddress source;
  IpAddress destination;
};
}  // namespace iptables
#endif  // !RULE_HPP