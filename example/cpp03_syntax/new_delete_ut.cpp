#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace new_delete_sample {

class Person {
public:
    Person(char const* family_name = "", char const* first_name = "", uint32_t height_cm = 1, uint32_t weight_kg = 1);
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
};

Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
    : family_name_(family_name),
      first_name_(first_name),
      full_name_(make_full_name(family_name, first_name)),
      height_cm_(height_cm),
      weight_kg_(weight_kg)
{
    assert(family_name_ && first_name_);
    assert(height_cm_ != 0);
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

TEST(cpp03, new_delete)
{
    // @@@ sample begin 0:0

    int*    p      = new int;                                // int型のメモリを確保(未初期化)
    int*    q      = new int(42);                            // int型のメモリを確保し、42で初期化
    Person* person = new Person("yamada", "taro", 173, 75);  // コンストラクタを呼び出す

    ASSERT_EQ(*q, 42);
    ASSERT_STREQ(person->get_full_name(), "yamada taro");

    delete p;       // pが指すメモリを解放
    delete q;       // qが指すメモリを解放
    delete person;  // personのデストラクタを呼び出してからメモリを解放
    // @@@ sample end
}

TEST(cpp03, new_delete_array)
{
    // @@@ sample begin 1:0

    // 配列の生成
    int*    array   = new int[10];    // 10個のint型配列を確保
    Person* persons = new Person[5];  // 5個のPersonオブジェクトの配列を確保

    // 配列の解放
    delete[] array;    // 配列全体を解放
    delete[] persons;  // 各要素のデストラクタを呼び出してから配列を解放
    // @@@ sample end
}
}  // namespace new_delete_sample
