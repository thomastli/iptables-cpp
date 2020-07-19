#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace iptables {
class CommandConstants {
 public:
  static constexpr const char* APPEND_COMMAND = "-A";
  static constexpr const char* DELETE_COMMAND = "-D";
  static constexpr const char* DELETE_USER_CHAIN_COMMAND = "-X";
  static constexpr const char* FLUSH_COMMAND = "-F";
  static constexpr const char* INSERT_COMMAND = "-I";
  static constexpr const char* LIST_COMMAND = "-L";
  static constexpr const char* NEW_CHAIN_COMMAND = "-N";
  static constexpr const char* POLICY_COMMAND = "-P";
  static constexpr const char* REPLACE_COMMAND = "-R";
};

class OptionsConstants {
 public:
  static constexpr const char* DESTINATION_OPTION = "-s";
  static constexpr const char* GOTO_OPTION = "-g";
  static constexpr const char* INPUT_OPTION = "-i";
  static constexpr const char* OUTPUT_OPTION = "-o";
  static constexpr const char* JUMP_OPTION = "-j";
  static constexpr const char* MATCH_OPTION = "-m";
  static constexpr const char* PROTOCOL_OPTION = "-p";
  static constexpr const char* SOURCE_OPTION = "-s";
  static constexpr const char* TABLE_OPTION = "-t";
};
}  // namespace iptables
#endif  // ! CONSTANTS_HPP