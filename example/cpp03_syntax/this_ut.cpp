#include "gtest_wrapper.h"

#include "suppress_warning.h"

void func0() {}
namespace this_example {

// @@@ sample begin 0:0

class A {
public:
    A()
    {
        /* thisの型はA* constであるため、代入はコンパイルエラー
        this = 0; */
    }

    A* this_ptr() { return this; }

    void func0() {}
    void func1()
    {
        extern void func0();

        func0();        // メンバ関数func0の呼び出し
        ::func0();      // クラスAの外部の関数func0の呼び出し
        this->func0();  // クラスAの外部の関数func0の呼び出しではなく、メンバ関数func0の呼び出しであることの明記
    }
};
// @@@ sample end
TEST(cpp03, this_example)
{
    // clang-format off
    // @@@ sample begin 0:1

    A a;

    A* a_ptr = &a;

    ASSERT_EQ(a_ptr, a.this_ptr());  // this_ptrはthisを返す。 thisがオブジェクトのポインタを指すことのテスト
    // @@@ sample end
    // clang-format on
}
}  // namespace this_example
