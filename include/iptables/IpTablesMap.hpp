#ifndef IP_TABLE_MAP_HPP
#define IP_TABLE_MAP_HPP

#include <map>

#include "iptables/IpRule.hpp"

namespace iptables 
{
/**
 * @brief Class to represent iptables as a map
 * 
 */
class IpTablesMap
{
public:
    /**
     * @brief Construct a new Ip Tables object
     * 
     */
    IpTablesMap() {}
    
    /**
     * @brief Destroy the Ip Tables object
     * 
     */
    ~IpTablesMap() {}

    /**
     * @brief List all ip rules in the ip tables map
     * 
     */
    void listIpTablesRulesFromMap();

    /**
     * @brief Add an IpRule to the ip tables map
     * 
     * @param ipRule    IpRule object
     */
    void addRuleToIpTablesMap(IpRule& ipRule);

    /**
     * @brief Delete an IpRule from the ip tables map
     * 
     * @param ipRule    IpRule object
     */
    void deleteRuleFromIpTablesMap(IpRule& ipRule);

    /**
     * @brief Modify an existing IpRule from the ip tables map
     * 
     * @param ipRule    IpRule object
     */
    void modifyRuleFromIpTables(IpRule& ipRule);

private:
    std::map<unsigned int, IpRule> ipTablesMap;
};
}
#endif // !IP_TABLES_MAP_HPP