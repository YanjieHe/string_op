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
    REQUIRE(string_op::starts_with<string>("", "") == true);
  }

  SECTION("Test Ends With") {
    REQUIRE(string_op::ends_with<string>("watermelon", "melon") == true);
    REQUIRE(string_op::ends_with<string>("watermelon", "water") == false);
    REQUIRE(string_op::ends_with<string>("", "") == true);
  }

  SECTION("Test Replace") {
    REQUIRE(string_op::replace<string>("A[OLD]B[OLD]C[OLD]", "[OLD]",
                                       "[NEW]") == "A[NEW]B[NEW]C[NEW]");
  }

  SECTION("Test Concat") {
    REQUIRE(string_op::concat<string>({"ABC", "DEF", "GHI"}) == "ABCDEFGHI");
  }

  SECTION("Test Join") {
    REQUIRE(string_op::join<string>("||", {"ABC", "DEF", "GHI"}) ==
            "ABC||DEF||GHI");
    REQUIRE(string_op::join<string>("", {"ABC", "DEF", "GHI"}) == "ABCDEFGHI");
    REQUIRE(string_op::join<string>("||", {}) == "");
    REQUIRE(string_op::join<string>("||", {"ABC"}) == "ABC");
  }
}