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

template <class StringType>
inline bool ends_with(const StringType &s, const StringType &value) {
  if (value.size() <= s.size()) {
    typename StringType::const_reverse_iterator value_iter = value.rbegin();
    typename StringType::const_reverse_iterator s_iter = s.rbegin();

    while (value_iter != value.rend()) {
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

template <class StringType>
inline StringType replace(const StringType &s, const StringType &old_value,
                          const StringType &new_value) {
  typename StringType::size_type pos1 = 0;
  typename StringType::size_type pos2;

  StringType result;
  pos2 = s.find(old_value, pos1);

  while (pos2 != StringType::npos) {
    result += s.substr(pos1, pos2 - pos1);
    pos1 = pos2 + old_value.size();
    result += new_value;
    pos2 = s.find(old_value, pos1);
  }

  result += s.substr(pos1);
  return result;
}

template <class StringType>
inline StringType concat(const std::vector<StringType> &values) {
  size_t n = 0;
  for (const auto &value : values) {
    n += value.size();
  }
  StringType result;
  result.reserve(n);
  for (const auto &value : values) {
    for (const auto &character : value) {
      result.push_back(character);
    }
  }
  return result;
}

template <class StringType>
inline StringType join(const StringType &separator,
                       const std::vector<StringType> &values) {
  if (values.empty()) {
    return StringType();
  } else {
    size_t n = 0;
    for (const auto &value : values) {
      n += value.size();
    }
    n += (values.size() - 1) * separator.size();

    StringType result;
    result.reserve(n);
    result += values.front();
    for (size_t i = 1; i < values.size(); i++) {
      result += separator;
      result += values.at(i);
    }
    return result;
  }
}

}; /* namespace string_op */

#endif /* STRING_OP_HPP */