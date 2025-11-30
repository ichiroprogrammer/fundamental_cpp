#include <memory.h>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace std_string {

// @@@ sample begin 0:0

//  @@@ sample end

TEST(cpp03, std_string)
{
    // @@@ sample begin 0:1

    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string str3 = str1 + " " + str2;  // 文字列の連結

    ASSERT_TRUE(strcmp(str3.c_str(), "Hello World") == 0);
    //  @@@ sample end

    // IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}
}  // namespace std_string
