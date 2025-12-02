#include <memory.h>

#include <fstream>
#include <sstream>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace std_libs {

TEST(cpp03, cstring)
{
    // @@@ sample begin 0:0

    char const* hello = "Hello";
    char const* world = "World";

    size_t hello_len = strlen(hello);
    size_t world_len = strlen(world);

    // Cでの文字列の結合
    char* hello_world = (char*)malloc(hello_len + 1 + world_len + 1);  // 間に1スペース入れる
    strcpy(hello_world, hello);
    hello_world[hello_len] = ' ';
    strcpy(hello_world + hello_len + 1, world);

    ASSERT_TRUE(strcmp(hello_world, "Hello World") == 0);  // 文字列の比較
    ASSERT_STREQ(hello_world, "Hello World");              // googletestでは上記はこの行と等価

    free(hello_world);  // これを忘れるとメモリリーク
    //  @@@ sample end
    // IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}

TEST(cpp03, std_string)
{
    // @@@ sample begin 0:1

    char const* hello = "Hello";
    char const* world = "World";

    // C++での文字列の結合
    std::string str1 = hello;              // str1の初期化
    std::string str2 = world;              // str2の初期化
    std::string str3 = str1 + " " + str2;  // 文字列の連結
    std::string exp  = "Hello World";

    ASSERT_TRUE(exp == str3);  // std::stringは等値比較演算子が定義されているため、文字列の比較にstrcmpは不要
    ASSERT_EQ(exp, str3);  // googletestでは上記はこの行と等価
    //  @@@ sample end

    // IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}

TEST(cpp03, DISABLED_cstram)
{
    // @@@ sample begin 1:0

    int  age = 30;
    char name[100];

    // Cでの出力
    printf("Age: %d\n", age);  // 型指定子(%d)を誤ると実行時エラー

    // Cでの入力
    scanf("%s", name);  // バッファオーバーフローのリスクあり
    //  @@@ sample end

    // IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}

TEST(cpp03, DISABLED_iostram)
{
    // @@@ sample begin 1:1

    int  age = 30;
    char name[100];

    // C++での出力
    std::cout << "Age: " << age << std::endl;  // 型は自動判別される

    // C++での入力
    std::cin >> name;  // std::stringは自動的にメモリを管理
    //  @@@ sample end
    // @@@ sample begin 1:2

    // ファイル出力の例
    std::ofstream ofs("output.txt");

    if (ofs) {
        ofs << "Name: " << name << ", Age: " << age << std::endl;
    }
    //  @@@ sample end
    // IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}

TEST(cpp03, ssstram)
{
    // @@@ sample begin 1:3

    int               age = 30;
    std::string       name("Yamada Taro");
    std::stringstream oss;  // 出力string

    // stringstreamへの出力
    oss << name << '(' << "Age:" << age << ')';  // 型は自動判別される

    std::string exp("Yamada Taro(Age:30)");

    ASSERT_EQ(exp, oss.str());  // oss.str()はossが出力された文字列を返す
    //  @@@ sample end
    // IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}
}  // namespace std_libs
