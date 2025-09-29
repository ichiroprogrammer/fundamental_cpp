#include <cassert>

#include "gtest_wrapper.h"

namespace {

// @@@ sample begin 0:0

struct C_Struct {  // Cの構造体
    int         x;
    int         y;
    char const* str;
};
// @@@ sample end

TEST(cpp03, c_style)
{
    // @@@ sample begin 0:1

    struct C_Struct a = {
        1,
        2,
        "a",
    };

    struct C_Struct b = {
        3,
        4,
        "b",
    };

    b = a;  // bはaの値をコピーされる
    ASSERT_EQ(a.x, b.x);
    ASSERT_EQ(a.y, b.y);
    ASSERT_EQ(a.str, b.str);  // 通常の基本型と同様に、ポインタもコピーされる

    struct C_Struct c = a;  // cはaの値で初期化される
    ASSERT_EQ(a.x, c.x);
    ASSERT_EQ(a.y, c.y);
    ASSERT_EQ(a.str, c.str);  // 通常の基本型と同様に、ポインタもコピーされる

    // @@@ sample end
}
}  // namespace
