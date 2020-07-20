#ifndef JSON_DB_WRAPPER_HPP
#define JSON_DB_WRAPPER_hpp

#include <json/json.h>

#include "iptables/ChainMap.hpp"

namespace iptables {
class JsonDbWrapper {
 public:
  /**
   * @brief Construct a new Json Db Wrapper object
   *
   */
  JsonDbWrapper() {}

  /**
   * @brief Construct a new Json Db Wrapper object
   *
   * @param chainMap
   */
  JsonDbWrapper(ChainMap* chainMap) : chainMap(chainMap) {}

  /**
   * @brief Destroy the Json Db Wrapper object
   *
   */
  ~JsonDbWrapper() {}

  /**
   * @brief Backup to a JSON database
   *
   * @param chainNames      The list of chain names
   * @return Json::Value    The Json::Value database
   */
  Json::Value backupToJsonDatabase(std::vector<std::string>& chainNames);

  /**
   * @brief Restore from a JSON database
   *
   * @param restoreDB   The Json::Value database
   */
  void restoreFromJsonDatabase(Json::Value& restoreDb);

  /**
   * @brief Generate Json value from rule object
   *
   * @param chainName     The chain name
   * @param rule          The rule object
   * @return Json::Value  Json::Value object
   */
  Json::Value generateJsonValueFromRule(std::string chainName, Rule& rule);

  /**
   * @brief Generate rule from Json value
   *
   * @param entry The Json::Value object
   * @return Rule The rule object
   */
  Rule generateRuleFromJsonValue(Json::Value& entry);

  /**
   * @brief Parse protocol from a std::string
   *
   * @param proto       The protocol, as a std::string
   * @return Protocol   The protocol object
   */
  Protocol parseProtocolFromString(std::string& proto);

  /**
   * @brief Parse target from a std::string
   *
   * @param tar       The target, as a std::string
   * @return Target   The target object
   */
  Target parseTargetFromString(std::string& tar);

 private:
  ChainMap* chainMap;
};
}  // namespace iptables
#endif  // !JSON_DB_WRAPPER_HPP