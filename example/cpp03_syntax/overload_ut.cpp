#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace overloaod_exp {
// @@@ sample begin 0:0

int    max(int a, int b) { return (a > b) ? a : b; }        // max #1
double max(double a, double b) { return (a > b) ? a : b; }  // max #2
long   max(long a, long b) { return (a > b) ? a : b; }      // max #3
// @@@ sample end

TEST(cpp03, overloaod)
{
    // @@@ sample begin 0:1

    ASSERT_EQ(20, max(10, 20));        // max #1が呼ばれる
    ASSERT_EQ(3.14, max(3.14, 2.71));  // max #2が呼ばれる
    ASSERT_EQ(200, max(100L, 200L));   // max #3が呼ばれる
    // @@@ sample end
}
}  // namespace overloaod_exp
