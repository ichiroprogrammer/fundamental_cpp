#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace c_style_operator_overloaod_exp {

// @@@ sample begin 0:0

// C言語的なアプローチ
typedef struct Rational {
    int num; /* 分子 */
    int den; /* 分母 */
} Rational;

Rational rational_add(struct Rational a, struct Rational b)
{
    Rational result;
    result.num = a.num * b.den + b.num * a.den;
    result.den = a.den * b.den;
    return result;
}
// @@@ sample end

TEST(cpp03, c_style_operator_overloaod)
{
    // @@@ sample begin 0:1

    Rational r0 = {2, 3};
    Rational r1 = {2, 4};

    Rational r2 = rational_add(r0, r1);
    // @@@ sample end
    IGNORE_UNUSED_VAR(r2);
}
}  // namespace c_style_operator_overloaod_exp

namespace operator_overload_by_member {

// @@@ sample begin 1:0

// C++での演算子オーバーロード
class Rational {
public:
    int num;  // 分子
    int den;  // 分母

    Rational operator+(Rational const& other) const
    {
        Rational result;
        result.num = num * other.den + other.num * den;
        result.den = den * other.den;
        return result;
    }
};

// @@@ sample end

TEST(cpp03, operator_overload_by_member)
{
    // @@@ sample begin 1:1

    Rational r0(2, 3);
    Rational r1(2, 4);

    // 使用例
    Rational r2 = r0 + r1;
    // @@@ sample end
    IGNORE_UNUSED_VAR(r2);
}
}  // namespace operator_overload_by_member

namespace operator_overload_by_member2 {

// @@@ sample begin 2:0

class Rational {
public:
    // @@@ sample end
    // @@@ sample begin 2:1
    Rational(int n = 0, int d = 1) : num_(n), den_(d) { reduce(); /* reduce()は約分を行う*/ }
    //                     ^^^^ デフォルト引数
    // @@@ sample end
    // @@@ sample begin 2:2

    int getNum() const { return num_; }
    int getDen() const { return den_; }

    // clang-format off
    // 単項マイナス演算子
    Rational operator-() const { return Rational(-num_, den_); }

    // 加算演算子
    Rational operator+(Rational const& other) const { return Rational(num_ * other.den_ + other.num_ * den_, den_ * other.den_); }

    // 減算演算子
    Rational operator-(Rational const& other) const { return Rational(num_ * other.den_ - other.num_ * den_, den_ * other.den_); }
    // clang-format on

    // 乗算演算子
    Rational operator*(Rational const& other) const { return Rational(num_ * other.num_, den_ * other.den_); }

    // 除算演算子
    Rational operator/(Rational const& other) const { return Rational(num_ * other.den_, den_ * other.num_); }

    // 複合代入演算子
    Rational& operator+=(Rational const& other)
    {
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        reduce();  // reduce()は約分を行う
        return *this;
    }

    // 前置インクリメント演算子
    Rational& operator++()
    {
        num_ += den_;
        return *this;
    }

    // 後置インクリメント演算子（ダミーのint引数で区別）
    Rational operator++(int)
    {
        Rational temp = *this;
        num_ += den_;
        return temp;
    }

private:
    int num_;  // 分子
    int den_;  // 分母

    void reduce()  // 約分
    {
        // @@@ ignore begin
        int g = gcd(num_, den_);
        num_ /= g;
        den_ /= g;
        // 分母を正に保つ
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
        // @@@ ignore end
    }

    // @@@ ignore begin
    static int gcd(int a, int b)  // 最大公約数を求める（約分用）
    {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int t = b;
            b     = a % b;
            a     = t;
        }
        return a;
    }
    // @@@ ignore end

    friend bool operator==(Rational const& lhs, Rational const& rhs);
};

bool operator==(Rational const& lhs, Rational const& rhs)  // 通常、等値比較演算子は非メンバ関数として定義する
{
    return (lhs.num_ == rhs.num_) && (lhs.den_ == rhs.den_);
}
// @@@ sample end

TEST(cpp03, operator_overload_by_member2)
{
    // @@@ sample begin 2:3

    Rational r1(2);  // デフォルト引数によりRational(2, 1)と書かずにRational(2)と簡素に記述できる
    Rational r2(1, 3);  // 1/3を宣言するため、デフォルト引数不使用
    // @@@ sample end
    // @@@ sample begin 2:4

    Rational r3 = r1 + r2;  // 2/1 + 1/3 = 7/3

    Rational exp0(7, 3);
    ASSERT_TRUE(r3 == exp0);  //                    operator==(Rational const& lhs, Rational const& rhs)の呼び出し

    Rational r4 = r1 * r2;  // 2/1 * 1/3 = 2/3      operator*(Rational const& other)の呼び出し
    ASSERT_TRUE(r4 == Rational(2, 3));

    Rational r5 = -r1;                // -2/1        operator+(Rational const& other)の呼び出し
    ASSERT_TRUE(r5 == Rational(-2));  //             デフォルト引数によりRational(-12)と簡素に記述できる

    r1 += r2;  // r1 = 5/6                          operator/(Rational const& other)の呼び出し
    ASSERT_TRUE(r1 == Rational(7, 3));

    ++r1;  // r1 = 11/6                             operator++(int)の呼び出し
    ASSERT_TRUE(r1 == Rational(10, 3));
    // @@@ sample end
    IGNORE_UNUSED_VAR(r4, r5);
}
}  // namespace operator_overload_by_member2
