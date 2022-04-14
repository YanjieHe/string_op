#ifndef STRING_OP_HPP
#define STRING_OP_HPP
#include <vector>
#include <string>

namespace string_op {

template <class StringType>
inline std::vector<StringType> split(const StringType &s,
                                     const StringType &separator) {
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

}; /* namespace string_op */

#endif /* STRING_OP_HPP */