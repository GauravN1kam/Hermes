#include "../include/json_parser.hpp"
#include <map>

using JsonObject = std::map<std::string, JsonValue>;
using JsonArray = std::vector<JsonValue>;

struct JsonValue {
  enum class Type { Null, Boolean, Number, String, Array, Object };

  Type type;
  std::variant<std::nullptr_t, bool, double, std::string, JsonArray, JsonObject>
      value;
};
