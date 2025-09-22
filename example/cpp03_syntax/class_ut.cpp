#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cassert>
#include <cstdint>

#include "gtest_wrapper.h"

namespace c_style {
// @@@ sample begin 0:0

struct Person {
    char const* family_name;
    char const* first_name;
    uint32_t    height_cm;  // 身長 (cm単位と仮定)
    uint32_t    weight_kg;  // 体重 (kg単位と仮定)
};

uint32_t calc_bmi(struct Person const* person)
{
    if ((person != NULL) && (person->height_cm == 0)) {
        return 0;
    }

    // BMI = 体重(kg) / (身長(m))^2
    // 身長をcmからmに変換: height_cm / 100
    // BMI = weight_kg / ((height_cm / 100.0)^2)
    // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

    uint32_t bmi = (person->weight_kg * 10000) / (person->height_cm * person->height_cm);

    return bmi;
}
// @@@ sample end
TEST(cpp03, class_exp)
{
    // @@@ sample begin 0:1

    struct Person person = {
        "yamada",  // 姓
        "taro",    // 名
        173,       // 身長cm
        75,        // 体重kg
    };

    uint32_t bmi = calc_bmi(&person);
    // @@@ sample end

    ASSERT_EQ(25, bmi);
}

char const* make_fullname(struct Person const* person)
{
    assert(person);

    size_t family_len = strlen(person->family_name);
    size_t first_len  = strlen(person->first_name);

    char* result = (char*)malloc(family_len + 1 + first_len + 1);  // 姓と名の間に1スペース入れる

    if (!result) {
        return NULL;
    }

    strcpy(result, person->family_name);
    result[family_len] = ' ';
    strcpy(result + family_len + 1, person->first_name);

    return result;
}

TEST(cpp03, class_exp2)
{
#if !defined(__clang_analyzer__)
    // @@@ sample begin 0:2

    struct Person person = {
        "yamada",  // 姓
        "taro",    // 名
        173,       // 身長cm
        75,        // 体重kg
    };

    char const* fullname = make_fullname(&person);
    // @@@ sample end

    ASSERT_STREQ("yamada taro", fullname);

    free((void*)fullname);
#endif
}
}  // namespace c_style

namespace cpp_style_1 {
// @@@ sample begin 1:0

struct Person {
    char const* family_name;
    char const* first_name;
    uint32_t    height_cm;   // 身長 (cm単位と仮定)
    uint32_t    weight_kg;   // 体重 (kg単位と仮定)
    uint32_t    calc_bmi();  // メンバ関数
};

uint32_t Person::calc_bmi()  // Personのcalc_bmi()の定義
{
    // BMI = 体重(kg) / (身長(m))^2
    // 身長をcmからmに変換: height_cm / 100
    // BMI = weight_kg / ((height_cm / 100.0)^2)
    // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

    uint32_t bmi = weight_kg * 10000 / (height_cm * height_cm);

    return bmi;
}
// @@@ sample end

TEST(cpp03, class_exp)
{
    // clang-format off
    // @@@ sample begin 1:1

    Person person = { // Cとは異なり、インスタンスの宣言にはstructの記述は不要
        "yamada",  // 姓
        "taro",    // 名
        173,       // 身長cm
        75,        // 体重kg
    };

    uint32_t bmi = person.calc_bmi();
    // @@@ sample end
    // clang-format on

    ASSERT_EQ(25, bmi);
}
}  // namespace cpp_style_1

namespace cpp_style_2 {
// @@@ sample begin 2:0

struct Person {
    Person(char const* family_name, char const* first_name, uint32_t height_cm,
           uint32_t weight_kg);  // コンストラクタ

    char const* family_name;
    char const* first_name;
    uint32_t    height_cm;   // 身長 (cm単位と仮定)
    uint32_t    weight_kg;   // 体重 (kg単位と仮定)
    uint32_t    calc_bmi();  // メンバ関数
};

// コンストラクタの定義
Person::Person(char const* family_name, char const* first_name, uint32_t height_cm,
               uint32_t weight_kg)
    : family_name(family_name),
      first_name(first_name),
      height_cm(height_cm),
      weight_kg(weight_kg)  // メンバ変数初期化リスト
{
    // メンバ変数の初期化などの処理はここに通常の関数の中に入れることができる
    assert(family_name && first_name);  // 本来ならエクセプションの送出すべきだが
    assert(height_cm != 0);             // 本来ならエクセプションの送出すべきだが
}

// @@@ sample end

TEST(cpp03, class_exp)
{
    // @@@ sample begin 2:1

    Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

    ASSERT_EQ(person.height_cm, 173);
    ASSERT_EQ(person.weight_kg, 75);
    ASSERT_STREQ(person.family_name, "yamada");  // 文字列として同値
    ASSERT_STREQ(person.first_name, "taro");     // 文字列として同値
                                                 // @@@ sample end
}

uint32_t Person::calc_bmi()  // Personのcalc_bmi()の定義
{
    // BMI = 体重(kg) / (身長(m))^2
    // 身長をcmからmに変換: height_cm / 100
    // BMI = weight_kg / ((height_cm / 100.0)^2)
    // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

    uint32_t bmi = weight_kg * 10000 / (height_cm * height_cm);

    return bmi;
}
}  // namespace cpp_style_2
namespace cpp_style_3 {
// @@@ sample begin 3:0

struct Person {
    Person(char const* family_name, char const* first_name, uint32_t height_cm,
           uint32_t weight_kg);  // コンストラクタ

    char const* family_name;
    char const* first_name;  // 新規メンバ
    char const* full_name;

    uint32_t height_cm;   // 身長 (cm単位と仮定)
    uint32_t weight_kg;   // 体重 (kg単位と仮定)
    uint32_t calc_bmi();  // メンバ関数

    char const* get_first_name();
};

// コンストラクタの定義
Person::Person(char const* family_name, char const* first_name, uint32_t height_cm,
               uint32_t weight_kg)
    // clang-format off
    : family_name(family_name), first_name(first_name),
      full_name(NULL),          // 新規に追加されたメンバをNULLで初期化
      height_cm(height_cm), weight_kg(weight_kg)  // clang-format on
{
    // @@@ ignore begin
    // メンバ変数の初期化などの処理はここに通常の関数の中に入れることができる
    assert(family_name && first_name);  // 本来ならエクセプションの送出すべきだが
    assert(height_cm != 0);             // 本来ならエクセプションの送出すべきだが
    // @@@ ignore end
}

char const* Person::get_first_name()  // フルネームを返す新規メンバ関数。
{
    if (full_name) {
        return NULL;
    }

    size_t family_len = strlen(family_name);
    size_t first_len  = strlen(first_name);

    char* result = (char*)malloc(family_len + 1 + first_len + 1);  // 姓と名の間に1スペース入れる

    if (!result) {
        return NULL;
    }

    strcpy(result, family_name);
    result[family_len] = ' ';
    strcpy(result + family_len + 1, first_name);

    return result;
}
// @@@ sample end

TEST(cpp03, class_exp)
{
#if !defined(__clang_analyzer__)
    // @@@ sample begin 3:1

    Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

    char const* full_name = person.get_first_name();

    ASSERT_STREQ(full_name, "yamada taro");  // 文字列として同値
    // @@@ sample end

    free((char*)full_name);
#endif
}

uint32_t Person::calc_bmi()  // Personのcalc_bmi()の定義
{
    // BMI = 体重(kg) / (身長(m))^2
    // 身長をcmからmに変換: height_cm / 100
    // BMI = weight_kg / ((height_cm / 100.0)^2)
    // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

    uint32_t bmi = weight_kg * 10000 / (height_cm * height_cm);

    return bmi;
}
}  // namespace cpp_style_3
