#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace default_arg {

// @@@ sample begin 0:0

int func(int arg = 1)  // デフォルト引数
{
    return arg;
}
// @@@ sample end

TEST(cpp03, default_arg)
{
    // @@@ sample begin 0:1

    ASSERT_EQ(1, func());   // funcはデフォルト引数を持つため、引数なしで呼び出せる
    ASSERT_EQ(2, func(2));  // 引数を指定しても良いで呼び出せる
    // @@@ sample end
    // IGNORE_UNUSED_VAR(r2);
}
}  // namespace default_arg

namespace default_arg_with_static {

// @@@ sample begin 1:0

static int default_arg = 1;

int func(int arg = default_arg)  // デフォルト引数はリテラルでなくても良い
{
    return arg;
}
// @@@ sample end

TEST(cpp03, default_arg)
{
    // @@@ sample begin 1:1

    ASSERT_EQ(1, func());  // funcはdefault_argをデフォルト引数とするため、引数なしで呼び出せる

    default_arg = 2;
    ASSERT_EQ(2, func());  // funcはdefault_argをデフォルト引数とするため、引数なしで呼び出せるが、
                           // default_argの変更の影響を受ける
    // @@@ sample end
    // IGNORE_UNUSED_VAR(r2);
}
}  // namespace default_arg_with_static

namespace default_arg2 {

// @@@ sample begin 2:0

// 正しい：右側から順にデフォルト値を指定
int func1(int a, int b, int c = 30) { return a + b + c; }
int func2(int a, int b = 20, int c = 30) { return a + b + c; }
int func3(int a = 10, int b = 20, int c = 30) { return a + b + c; }

/* エラー：途中の引数だけにデフォルト値は指定できない
void func(int a, int b = 20, int c);        // コンパイルエラー
void func(int a = 10, int b, int c = 30);   // コンパイルエラー
*/
// @@@ sample end

TEST(cpp03, default_arg2)
{
    // @@@ sample begin 2:1

    ASSERT_EQ(30, func1(0, 0));
    ASSERT_EQ(50, func2(0));
    ASSERT_EQ(60, func3());
    // @@@ sample end
    // IGNORE_UNUSED_VAR(r2);
}
}  // namespace default_arg2
