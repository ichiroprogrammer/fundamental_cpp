#include <cassert>
#include <cstdint>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

#if !defined(__clang_analyzer__)
// Personのcopyコンストラクタ/copy代入演算子の実装が行われるまで、clang analyzerは駆けない
namespace cpp_style_7 {
bool full_name_freed = false;  // ダブルデリートを避けるための手段
SUPPRESS_WARN_BEGIN
SUPPRESS_WARN_GCC_NOT_EFF_CPP;
SUPPRESS_WARN_CLANG_UNUSED_PRIVATE_FIELD;
// @@@ sample begin 0:0

class Person {
public:
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

Person::~Person()  // デストラクタの定義
{
    // clang-format off
    if(full_name_freed) { return; }                    // @@@ delete
    if(!full_name_freed) { full_name_freed = true; }   // @@@ delete
    // clang-format on
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
TEST(cpp03, class_exp6)
{
    // @@@ sample begin 0:1

    {
        Person person0("yamada", "taro", 173, 75);  // オブジェクトの生成

        ASSERT_STREQ(person0.get_full_name(), "yamada taro");  // 文字列として同値
        Person person1 = person0; // person0.full_nameがperson1.full_nameに単純コピー

        ASSERT_EQ(person0.calc_bmi(), person1.calc_bmi());
        ASSERT_STREQ(person0.get_full_name(), person1.get_full_name());
    }   // この行でperson1.~Person()が呼び出され、free(person1.full_name)が実行され、
        // 一つ上の行でperson0.~Person()が呼び出され、free(person0.full_name)が実行される
        // このため、full_nameは二重解放される
    // @@@ sample end
}
SUPPRESS_WARN_END;
}  // namespace cpp_style_7
#endif
