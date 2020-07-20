#ifndef RULE_HPP
#define RULE_HPP

#include <string>

#include "iptables/Address.hpp"

enum class Target { NONE, ACCEPT, DROP, REJECT };
enum class Protocol { NONE, TCP, UDP, ICMP, ALL };

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
   * @brief Check if rule has target
   *
   * @return true   If target found
   * @return false  Otherwise
   */
  bool hasTarget();

  /**
   * @brief Check if rule has protocol
   *
   * @return true   If protocol found
   * @return false  Otherwise
   */
  bool hasProtocol();

  /**
   * @brief Check if rule has opt value
   *
   * @return true   If opt value found
   * @return false  Otherwise
   */
  bool hasOptValue();

  /**
   * @brief Check if rule has input value
   *
   * @return true   If input value found
   * @return false  Otherwise
   */
  bool hasInValue();

  /**
   * @brief Check if rule has output value
   *
   * @return true   If output value found
   * @return false  Otherwise
   */
  bool hasOutValue();

  /**
   * @brief Check if rule has source
   *
   * @return true   If source found
   * @return false  Otherwise
   */
  bool hasSource();

  /**
   * @brief Check if rule has destination
   *
   * @return true   If destination found
   * @return false  Otherwise
   */
  bool hasDestination();

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
   * @return Address  The source address
   */
  Address getSourceAddress();

  /**
   * @brief Get the destination address from the Rule object
   *
   * @return Address  The destination address
   */
  Address getDestinationAddress();

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
  void setSourceAddress(Address& source);

  /**
   * @brief Set the destination address for the Rule object
   *
   * @param destination
   */
  void setDestinationAddress(Address& destination);

  /**
   * @brief Parse target to std::string object
   *
   * @return std::string  The target value
   */
  std::string parseTargetToString();

  /**
   * @brief Parse protocol to std::string object
   *
   * @return std::string  The protocol value
   */
  std::string parseProtocolToString();

 private:
  Target target;
  Protocol protocol;
  std::string opt;
  std::string in;
  std::string out;
  Address source;
  Address destination;
};
}  // namespace iptables
#endif  // !RULE_HPP