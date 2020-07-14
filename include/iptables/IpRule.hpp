#ifndef IP_RULE_HPP
#define IP_RULE_HPP

#include <string>

enum class Target {ACCEPT, DECLINE};
enum class Protocol {TCP, UDP, ALL};

namespace iptables
{
/**
 * @brief An individual rule from the iptables map
 * 
 */
class IpRule
{
public:
    /**
     * @brief Construct a new Ip Rule object
     * 
     */
    IpRule() {}

    IpRule(unsigned int num, Target& target, Protocol& protocol, std::string& opt, std::string& in, std::string& out, std::string );
    
    /**
     * @brief Destroy the Ip Rule object
     * 
     */
    ~IpRule() {}

    /**
     * @brief Get the num id from the IpRule object
     * 
     * @return unsigned int The num id
     */
    unsigned int getNumId();

    /**
     * @brief Get the target from the IpRule object
     * 
     * @return Target   The target object
     */
    Target getTarget();

    /**
     * @brief Get the protocol from the IpRule object
     * 
     * @return Protocol  The proctocol name 
     */
    Protocol getProtocol();

    /**
     * @brief Get the opt value from the IpRule object
     * 
     * @return std::string  The opt value
     */
    std::string getOptValue();

    /**
     * @brief Get the in value from the IpRule object
     * 
     * @return std::string  The in value
     */
    std::string getInValue();

    /**
     * @brief Get the out value from the IpRule object
     * 
     * @return std:;string  The out value
     */
    std::string getOutValue();

    /**
     * @brief Get the source address from the IpRule obejct
     * 
     * @return std::string  The source address
     */
    std::string getSourceAddress();

    /**
     * @brief Get the destination address from the IpRule object
     * 
     * @return std::string  The destination address
     */
    std::string getDestinationAddress();

    /**
     * @brief Set the num for the IpRule object
     * 
     * @param numId     The num id
     */
    void setNumId(unsigned int numId);

    /**
     * @brief Set the target for the IpRule object
     * 
     * @param target    The target object
     */
    void setTarget(Target& target);

    /**
     * @brief Set the protocol for the IpRule object
     * 
     * @param protocol  The protocol object
     */
    void setProtocol(Protocol& protocol);

    /**
     * @brief Set the opt value for the IpRule object
     * 
     * @param opt   The opt value
     */
    void setOptValue(std::string& opt);

    /**
     * @brief Set the in value for the IpRule object
     * 
     * @param in    Set the in value
     */
    void setInValue(std::string& in);

    /**
     * @brief Set the out value for the IpRule object
     * 
     * @param out   Set the out value
     */
    void setOutValue(std::string& out);

    /**
     * @brief Set the source address for the IpRule object
     * 
     * @param source 
     */
    void setSourceAddress(std::string& source);

    /**
     * @brief Set the destination address for the IpRule object
     * 
     * @param destination 
     */
    void setDestinationAddress(std::string& destination);

private:
    unsigned int num;
    Target target;
    Protocol protocol;
    std::string opt;
    std::string in;
    std::string out;
    std::string source;
    std::string destination;
};
}
#endif // !IP_RULE_HPP