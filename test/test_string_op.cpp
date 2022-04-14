#include <catch2/catch.hpp>
#include "string_op.hpp"

using std::string;
using std::vector;

TEST_CASE("Test String Operations", "[string_op]") {
  SECTION("Test Split") {
    REQUIRE(string_op::split<string>("abc,def,ghi", ",") ==
            vector<string>{"abc", "def", "ghi"});
  }
}