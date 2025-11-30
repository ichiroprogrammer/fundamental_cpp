#include <cassert>
#include <cstdint>
#include <cstring>

#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace cpp_style_9 {
// @@@ sample begin 0:0

class Person {
public:
    Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);
    Person(Person const& rhs);
    Person& operator=(Person const& rhs);
    ~Person();

    uint32_t    calc_bmi() const;
    char const* get_full_name() const { return full_name_; }

private:
    static char* make_full_name(char const* family_name, char const* first_name);

    char const* family_name_;  // Trailing Underscoreを使用
    char const* first_name_;
    char const* full_name_;

    uint32_t height_cm_;
    uint32_t weight_kg_;

    friend bool operator==(Person const& lhs, Person const& rhs);  // 等値比較演算子のフレンド宣言
                                                                   // operator!=はフレンド宣言は不要
};

bool operator==(Person const& lhs, Person const& rhs)  // 等値比較演算子の定義
{
    return std::strcmp(lhs.family_name_, rhs.family_name_) == 0 && std::strcmp(lhs.first_name_, rhs.first_name_) == 0
           && lhs.height_cm_ == rhs.height_cm_ && lhs.weight_kg_ == rhs.weight_kg_;
}

bool operator!=(Person const& lhs, Person const& rhs) { return !(lhs == rhs); }

// 他の関数の実装は省略
// ...
// @@@ sample end

Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
    : family_name_(family_name),
      first_name_(first_name),
      full_name_(make_full_name(family_name, first_name)),
      height_cm_(height_cm),
      weight_kg_(weight_kg)
{
    if ((family_name == NULL) || (first_name == NULL)) {
        throw std::invalid_argument("name must be not NULL");  // エラーの通知
    }
    if (height_cm == 0) {
        throw std::logic_error("height_cm must be not zero");  // エラーの通知
    }
}

Person::Person(Person const& rhs)
    : family_name_(rhs.family_name_),
      first_name_(rhs.first_name_),
      full_name_(make_full_name(rhs.family_name_, rhs.first_name_)),
      height_cm_(rhs.height_cm_),
      weight_kg_(rhs.weight_kg_)
{
}

Person& Person::operator=(Person const& rhs)
{
    if (this == &rhs) {
        return *this;
    }

    family_name_ = rhs.family_name_;
    first_name_  = rhs.first_name_;

    delete[] full_name_;
    full_name_ = make_full_name(rhs.family_name_, rhs.first_name_);

    height_cm_ = rhs.height_cm_;
    weight_kg_ = rhs.weight_kg_;

    return *this;
}

Person::~Person() { delete[] full_name_; }

uint32_t Person::calc_bmi() const
{
    if (height_cm_ == 0) {
        return 0;
    }
    return (weight_kg_ * 10000) / (height_cm_ * height_cm_);
}

char* Person::make_full_name(char const* family_name, char const* first_name)
{
    if (!family_name || !first_name) {
        return NULL;
    }

    size_t family_len = strlen(family_name);
    size_t first_len  = strlen(first_name);

    char* full_name = new char[family_len + 1 + first_len + 1];

    strcpy(full_name, family_name);
    full_name[family_len] = ' ';
    strcpy(full_name + family_len + 1, first_name);

    return full_name;
}

TEST(cpp03, class_exp9)
{
    SUPPRESS_WARN_BEGIN;
    SUPPRESS_WARN_CLANG_SELF_ASSIGN_OVERLOADED;

    // @@@ sample begin 0:1

    Person person0("yamada", "taro", 173, 75);  // オブジェクトの生成
    Person person1("sato", "jiro", 173, 70);    // オブジェクトの生成

    ASSERT_STREQ(person0.get_full_name(), "yamada taro");  // 文字列として同値
    ASSERT_STREQ(person1.get_full_name(), "sato jiro");    // 文字列として同値
    ASSERT_EQ(25, person0.calc_bmi());

    ASSERT_TRUE(person0 == person0);  // 等値比較演算子のテスト(同一オブジェクトでのテスト)
    ASSERT_TRUE(person0 != person1);  // 等値比較演算子のテスト(!= テストも兼ねる)
    // 通常、上記2テストは以下のように書く
    ASSERT_EQ(person0, person0);
    ASSERT_NE(person0, person1);

    person0 = person1;            // コピー代入
    ASSERT_EQ(person0, person1);  // 等値比較演算子とコピー代入演算子のテスト
    // @@@ sample end

    {
        Person person0("yamada", "taro", 173, 75);  // オブジェクトの生成

        ASSERT_STREQ(person0.get_full_name(), "yamada taro");  // 文字列として同値
        Person person1 = person0;                              // コピーコンストラクタ

        ASSERT_EQ(person0.calc_bmi(), person1.calc_bmi());

        //  full_nameが単純にコピーされただけならば、
        //  person0.get_full_name() == person1.get_full_name()が成立するはずである
        ASSERT_NE(person0.get_full_name(), person1.get_full_name());
        ASSERT_STREQ(person0.get_full_name(), person1.get_full_name());

        Person person2("asada", "jiro", 170, 70);

        ASSERT_EQ(24, person2.calc_bmi());
        ASSERT_STREQ(person2.get_full_name(), "asada jiro");

        person0 = person0;  // 自己代入は何もしない
        person0 = person2;

        ASSERT_EQ(person0.calc_bmi(), person2.calc_bmi());
        ASSERT_STREQ(person0.get_full_name(), person2.get_full_name());
    }  // この行で新規に確保したメモリは正確に解放される

    SUPPRESS_WARN_END;

    {
        Person person0("yamada", "taro", 173, 75);  // オブジェクトの生成

        ASSERT_STREQ(person0.get_full_name(), "yamada taro");  // 文字列として同値
        Person person1 = person0;                              // コピーコンストラクタ

        ASSERT_EQ(person0.calc_bmi(), person1.calc_bmi());

        //  full_nameが単純にコピーされただけならば、
        //  person0.get_full_name() == person1.get_full_name()が成立するはずである
        ASSERT_NE(person0.get_full_name(), person1.get_full_name());
        ASSERT_STREQ(person0.get_full_name(), person1.get_full_name());

        Person person2("asada", "jiro", 170, 70);

        ASSERT_EQ(24, person2.calc_bmi());
        ASSERT_STREQ(person2.get_full_name(), "asada jiro");

        person1 = person0 = person2;

        ASSERT_EQ(person0.calc_bmi(), person2.calc_bmi());
        ASSERT_STREQ(person0.get_full_name(), person2.get_full_name());
        ASSERT_EQ(person0.calc_bmi(), person1.calc_bmi());
        ASSERT_STREQ(person0.get_full_name(), person1.get_full_name());
    }
}
}  // namespace cpp_style_9
