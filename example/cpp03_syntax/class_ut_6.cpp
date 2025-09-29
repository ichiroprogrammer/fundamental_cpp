#include <cassert>
#include <cstdint>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace {
SUPPRESS_WARN_BEGIN
SUPPRESS_WARN_GCC_NOT_EFF_CPP;
// @@@ sample begin 0:0

class Person {
public:
    Person(char const* family_name, char const* first_name, uint32_t height_cm,
           uint32_t weight_kg);  // コンストラクタ

    uint32_t    calc_bmi();  // メンバ関数
    char const* get_full_name();

    ~Person();  // デストラクタ

    // make_full_nameをPerson内のstatic関数に変更した
    static char* make_full_name(char const* family_name, char const* first_name);

private:  // メンバ変数への外部からのアクセスを禁止する
    char const* family_name;
    char const* first_name;
    char*       full_name;

    uint32_t height_cm;  // 身長 (cm単位と仮定)
    uint32_t weight_kg;  // 体重 (kg単位と仮定)
};

Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
    // clang-format off
    : family_name(family_name), first_name(first_name), full_name(NULL),
      height_cm(height_cm), weight_kg(weight_kg)  // clang-format on
{
    // コンストラクタの中身は省略
    // @@@ ignore begin
    // メンバ変数の初期化などの処理はここに通常の関数の中に入れることができる
    assert(family_name && first_name);  // 本来ならエクセプションの送出すべきだが
    assert(height_cm != 0);             // 本来ならエクセプションの送出すべきだが
    // @@@ ignore end
}

char* Person::make_full_name(char const* family_name, char const* first_name)
{
    // 関数の中身は変わっていないので省略
    // @@@ ignore begin
    if (!family_name || !first_name) {
        return NULL;
    }

    size_t family_len = strlen(family_name);
    size_t first_len  = strlen(first_name);

    char* full_name = (char*)malloc(family_len + 1 + first_len + 1);  // 姓と名の間に1スペース入れる

    if (!full_name) {
        return NULL;
    }

    strcpy(full_name, family_name);
    full_name[family_len] = ' ';
    strcpy(full_name + family_len + 1, first_name);

    return full_name;
    // @@@ ignore end
}

char const* Person::get_full_name()
{
    if (full_name) {  // すでにfull_nameの生成済
        return full_name;
    }

    // return full_name = make_full_name(family_name, first_name);

    // 上記でも問題なくmake_full_nameを呼び出せるが、Personのメンバ関数であることを強調したい場合、
    // 以下のように書いてもよい
    return full_name = Person::make_full_name(family_name, first_name);
}

Person::~Person()  // デストラクタの定義。
{
    if (full_name) {
        free((void*)full_name);
    }
}
// @@@ sample end

uint32_t Person::calc_bmi()  // Personのcalc_bmi()の定義
{
    // BMI = 体重(kg) / (身長(m))^2
    // 身長をcmからmに変換: height_cm / 100
    // BMI = weight_kg / ((height_cm / 100.0)^2)
    // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

    uint32_t bmi = weight_kg * 10000 / (height_cm * height_cm);

    return bmi;
}

TEST(cpp03, class_exp5)
{
#if !defined(__clang_analyzer__)

    // @@@ sample begin 0:1

    char* full_name = Person::make_full_name("yamada", "taro");
    //                      ^^^^^ static関数の呼び出しはクラス名修飾が必要

    ASSERT_STREQ(full_name, "yamada taro");  // 文字列として同値
    free((void*)full_name);
    // @@@ sample end
#endif

    {
        Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

        char const* full_name = person.get_full_name();

        ASSERT_STREQ(full_name, "yamada taro");  // 文字列として同値
        person.calc_bmi();
    }
}
SUPPRESS_WARN_END;
}  // namespace
namespace cpp_style_6 {
SUPPRESS_WARN_BEGIN
SUPPRESS_WARN_GCC_NOT_EFF_CPP;
SUPPRESS_WARN_CLANG_UNUSED_PRIVATE_FIELD;
// @@@ sample begin 1:0

class Person {
public:
    static int instance_counter;

    Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ
    ~Person();  // デストラクタ

    uint32_t    calc_bmi();                            // メンバ関数
    char const* get_full_name() { return full_name; }  // クラス内部でのメンバ関数定義

private:  // メンバ変数への外部からのアクセスを禁止する
    static char* make_full_name(char const* family_name, char const* first_name);

    char const* family_name;
    char const* first_name;
    char*       full_name;  // 新規メンバ

    uint32_t height_cm;  // 身長 (cm単位と仮定)
    uint32_t weight_kg;  // 体重 (kg単位と仮定)
};

int Person::instance_counter = 0;  // これが無いとリンクエラーになる
                                   // ここでは0に初期化するが、デフォルト初期でも問題ない

Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
    // clang-format off
    : family_name(family_name), first_name(first_name),
      full_name(make_full_name(family_name, first_name)),
      height_cm(height_cm), weight_kg(weight_kg)  // clang-format on
{
    // コンストラクタの中身は省略
    // @@@ ignore begin
    // メンバ変数の初期化などの処理はここに通常の関数の中に入れることができる
    assert(family_name && first_name);  // 本来ならエクセプションの送出すべきだが
    assert(height_cm != 0);             // 本来ならエクセプションの送出すべきだが
    assert(full_name != NULL);          // 本来ならエクセプションの送出すべきだが
                                        //
    ++instance_counter;  // コンストラクタが呼ばれたため、インスタンスの数が一つ増えた
    // @@@ ignore end
}

char* Person::make_full_name(char const* family_name, char const* first_name)
{
    // 関数の中身は変わっていないので省略
    // @@@ ignore begin
    if (!family_name || !first_name) {
        return NULL;
    }

    size_t family_len = strlen(family_name);
    size_t first_len  = strlen(first_name);

    char* full_name = (char*)malloc(family_len + 1 + first_len + 1);  // 姓と名の間に1スペース入れる

    if (!full_name) {
        return NULL;
    }

    strcpy(full_name, family_name);
    full_name[family_len] = ' ';
    strcpy(full_name + family_len + 1, first_name);

    return full_name;
    // @@@ ignore end
}

Person::~Person()  // デストラクタの定義。
{
    if (full_name) {
        free((void*)full_name);
    }

    --instance_counter;  // デストラクタが呼ばれたのでインスタンスの数が一つ減った
}
// @@@ sample end

uint32_t Person::calc_bmi()  // Personのcalc_bmi()の定義
{
    // BMI = 体重(kg) / (身長(m))^2
    // 身長をcmからmに変換: height_cm / 100
    // BMI = weight_kg / ((height_cm / 100.0)^2)
    // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

    uint32_t bmi = weight_kg * 10000 / (height_cm * height_cm);

    return bmi;
}
TEST(cpp03, class_exp6)
{
    // @@@ sample begin 1:1

    ASSERT_EQ(Person::instance_counter, 0);  // staticな変数はデフォルト初期化される

    Person taro("yamada", "taro", 173, 75);             // オブジェクトの生成
    ASSERT_STREQ(taro.get_full_name(), "yamada taro");  // 文字列として同値
    ASSERT_EQ(Person::instance_counter, 1);

    {
        Person jiro("yamada", "jiro", 170, 70);  // オブジェクトの生成
        {
            Person saburo("yamada", "saburo", 183, 80);  // オブジェクトの生成
            ASSERT_EQ(Person::instance_counter, 3);
        }  // この行でsaburoは解放される

        ASSERT_EQ(Person::instance_counter, 2);
    }  // この行でjiroは解放される

    ASSERT_EQ(Person::instance_counter, 1);  // jiro、saburoが解放された
    // @@@ sample end
}
SUPPRESS_WARN_END;
}  // namespace cpp_style_6
