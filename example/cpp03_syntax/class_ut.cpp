#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdint>

#include "gtest_wrapper.h"

namespace c_style{
// @@@ sample begin 0:0

struct Person {
    char const* family_name;
    char const* first_name;
    uint32_t height_cm;        // 身長 (cm単位と仮定)
    uint32_t weight_kg;        // 体重 (kg単位と仮定)
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
        "yamada",       // 姓
        "taro",         // 名
        173,            // 身長cm
        75,             // 体重kg
    };

    uint32_t bmi =calc_bmi(&person);
    // @@@ sample end

    ASSERT_EQ(25, bmi);
}

char const* make_fullname(struct Person const* person)
{
    assert(person);

    size_t family_len = strlen(person->family_name);
    size_t first_len = strlen(person->first_name);

    char* result = (char *)malloc(family_len + 1 + first_len + 1); // 姓と名の間に1スペース入れる

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
    // @@@ sample begin 0:2

    struct Person person = {
        "yamada",       // 姓
        "taro",         // 名
        173,            // 身長cm
        75,             // 体重kg
    };

    char const* fullname = make_fullname(&person);
    // @@@ sample end

    ASSERT_STREQ("yamada taro", fullname);
}
}

namespace cpp_style{
// @@@ sample begin 1:0

struct Person {
    char const* family_name;
    char const* first_name;
    uint32_t height_cm;        // 身長 (cm単位と仮定)
    uint32_t weight_kg;        // 体重 (kg単位と仮定)
    uint32_t calc_bmi();       // メンバ関数
};

uint32_t Person::calc_bmi() // Personのcalc_bmi()の定義
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
    // @@@ sample begin 1:1

    Person person = {   // Cとは異なり、インスタンスの宣言にはstructの記述は不要
        "yamada",       // 姓
        "taro",         // 名
        173,            // 身長cm
        75,             // 体重kg
    };

    uint32_t bmi =person.calc_bmi();
    // @@@ sample end

    ASSERT_EQ(25, bmi);
}
}
