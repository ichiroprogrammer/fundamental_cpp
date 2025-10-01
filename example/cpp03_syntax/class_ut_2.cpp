#include <cassert>
#include <cstdint>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace {
// @@@ sample begin 0:0

struct Person {
    Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

    char const* family_name;
    char const* first_name;
    uint32_t    height_cm;       // 身長 (cm単位と仮定)
    uint32_t    weight_kg;       // 体重 (kg単位と仮定)
    uint32_t    calc_bmi(void);  // メンバ関数
};

// コンストラクタの定義
Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
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

TEST(cpp03, class_exp2)
{
    // @@@ sample begin 0:1

    Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

    ASSERT_EQ(person.height_cm, 173);
    ASSERT_EQ(person.weight_kg, 75);
    ASSERT_STREQ(person.family_name, "yamada");  // 文字列として同値
    ASSERT_STREQ(person.first_name, "taro");     // 文字列として同値
    // @@@ sample end

    person.calc_bmi();
}

uint32_t Person::calc_bmi(void)  // Personのcalc_bmiの定義
{
    // BMI = 体重(kg) / (身長(m))^2
    // 身長をcmからmに変換: height_cm / 100
    // BMI = weight_kg / ((height_cm / 100.0)^2)
    // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

    uint32_t bmi = weight_kg * 10000 / (height_cm * height_cm);

    return bmi;
}
}  // namespace
