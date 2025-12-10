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

// @@@ sample begin 1:0

int add(int a, int b) { return a + b; }                        // add #1
int add(int a, int b, int c) { return a + b + c; }             // add #1
int add(int a, int b, int c, int d) { return a + b + c + d; }  // add #1
// @@@ sample end

TEST(cpp03, overloaod2)
{
    // @@@ sample begin 1:1

    ASSERT_EQ(2, add(1, 1));        // add #1が呼ばれる
    ASSERT_EQ(3, add(1, 1, 1));     // add #2が呼ばれる
    ASSERT_EQ(4, add(1, 1, 1, 1));  // add #2が呼ばれる
    // @@@ sample end
}

// @@@ sample begin 2:0

int abs(int a) { return (a < 0) ? -a : a; }    // abs #1
int abs(float a) { return (a < 0) ? -a : a; }  // abs #2
// @@@ sample end

TEST(cpp03, overloaod3)
{
    // @@@ sample begin 2:1

    abs(-1);     // abs #1が呼ばれる
    abs(-3.0f);  // abs #2が呼ばれる

    /* 3.0はdoubleであるため、
    abs(-3.0);   //abs #1を呼ぶべきか、abs #2を呼ぶべきかは曖昧である
    */
    // @@@ sample end
    ASSERT_EQ(1, abs(-1));              // abs #1が呼ばれる
    ASSERT_FLOAT_EQ(3.0f, abs(-3.0f));  // abs #2が呼ばれる
}
}  // namespace overloaod_exp
