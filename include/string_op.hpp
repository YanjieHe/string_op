#ifndef STRING_OP_HPP
#define STRING_OP_HPP
#include <vector>
#include <string>

namespace string_op {

template <class StringType>
inline std::vector<StringType> split(const StringType &s,
                                     const StringType &separator) {
  if (separator.empty()) {
    return {s};
  } else {
    typename StringType::size_type pos1 = 0;
    typename StringType::size_type pos2;

    std::vector<StringType> result;
    pos2 = s.find(separator, pos1);

    while (pos2 != StringType::npos) {
      result.push_back(s.substr(pos1, pos2 - pos1));
      pos1 = pos2 + separator.size();
      pos2 = s.find(separator, pos1);
    }

    result.push_back(s.substr(pos1));
    return result;
  }
}

template <class StringType>
inline bool starts_with(const StringType &s, const StringType &value) {
  if (value.size() <= s.size()) {
    typename StringType::const_iterator value_iter = value.begin();
    typename StringType::const_iterator s_iter = s.begin();

    while (value_iter != value.end()) {
      if (*s_iter != *value_iter) {
        return false;
      } else {
        s_iter++;
        value_iter++;
      }
    }

    return true;
  } else {
    return false;
  }
}

}; /* namespace string_op */

#endif /* STRING_OP_HPP */