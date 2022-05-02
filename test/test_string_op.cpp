#include <catch2/catch.hpp>
#include "string_op.hpp"

using std::string;
using std::vector;

TEST_CASE("Test String Operations", "[string_op]") {
  SECTION("Test Split") {
    REQUIRE(string_op::split<string>("abc,def,ghi", ",") ==
            vector<string>{"abc", "def", "ghi"});
    REQUIRE(string_op::split<string>("abc", ",") == vector<string>{"abc"});
    REQUIRE(string_op::split<string>(",ONE,,TWO,,,THREE", ",") ==
            vector<string>{"", "ONE", "", "TWO", "", "", "THREE"});
    REQUIRE(string_op::split<string>("abc", "") == vector<string>{"abc"});
    REQUIRE(string_op::split<string>("", ",") == vector<string>{""});
  }

  SECTION("Test Starts With") {
    REQUIRE(string_op::starts_with<string>("apple", "app") == true);
    REQUIRE(string_op::starts_with<string>("app", "apple") == false);
  }

  SECTION("Test Ends With") {
    REQUIRE(string_op::ends_with<string>("watermelon", "melon") == true);
    REQUIRE(string_op::ends_with<string>("watermelon", "water") == false);
  }
}