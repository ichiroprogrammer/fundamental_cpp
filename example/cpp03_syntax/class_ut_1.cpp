#include <cassert>
#include <cstdint>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace {
// @@@ sample begin 0:0

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

TEST(cpp03, class_exp1)
{
    // clang-format off
    // @@@ sample begin 0:1

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
}  // namespace
