#include <cstring>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace friend_declaration {

class A;
class Friend_A1 {};
class Friend_A2 {};

// @@@ sample begin 0:0

class A {
private:
    int data;

    friend class Friend_A1;  // クラスのフレンド宣言
    friend Friend_A2;        // C++11以降はclassキーワードを省略可能

    friend void func(A& obj)  // 関数のフレンド宣言
                              // フレンド関数はクラス内部でも外部でも定義可能
    {
        obj.data = 0;  // フレンド宣言の効果でAのprivateにアクセスできる
    }
};
//  @@@ sample end

TEST(cpp03, friend_declaration)
{
    // @@@ sample begin 0:1

    //  @@@ sample end

    // IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}
}  // namespace friend_declaration
