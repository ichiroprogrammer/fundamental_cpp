#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace public_derived {

// @@@ sample begin 0:0

class Base {
public:
    int public_value_;

protected:
    int protected_value_;

private:
    int private_value_;
};

class Derived : public Base {
public:
    void access()
    {
        public_value_    = 10;  // OK: publicメンバにアクセス可能
        protected_value_ = 20;  // OK: protectedメンバにアクセス可能
        /*
        private_value_ = 30;      NG: privateメンバにはアクセス不可 */
    }
};
// @@@ sample end

TEST(cpp03, public_derived)
{
    // @@@ sample begin 0:1

    Derived d;
    d.public_value_ = 100;  // OK: 外部からpublicメンバにアクセス可能
    /*
    d.protected_value_ = 200;  NG: 外部からprotectedメンバにはアクセス不可 */
    //  @@@ sample end

    // @@@ sample begin 0:2

    Base* b_ptr = &d;  // DerivedはBaseの一種であるめ、これが認められる
    Base& b_ref = d;   // DerivedはBaseの一種であるめ、これも認められる
    //  @@@ sample end

    IGNORE_UNUSED_VAR(d, b_ptr, b_ref);
}
}  // namespace public_derived
namespace protected_derived {

// @@@ sample begin 1:0
class Base {
public:
    int public_value_;

protected:
    int protected_value_;
};

class Derived : protected Base {
public:
    void access()
    {
        public_value_    = 10;  // OK: protectedメンバとしてアクセス可能
        protected_value_ = 20;  // OK: protectedメンバとしてアクセス可能
    }
};
//  @@@ sample end
TEST(cpp03, protected_derived)
{
    // @@@ sample begin 1:1

    Derived d;
    /*
    d.public_value_ = 100;    外部からはアクセス不可 */

    /*
    Base* b_ptr = &d;  public継承とは異なり、これは認められない
    Base& b_ref = d;   public継承とは異なり、これも認められない */
    //  @@@ sample end
    IGNORE_UNUSED_VAR(d);
}
}  // namespace protected_derived

namespace private_derived {

// @@@ sample begin 2:0

class Base {
public:
    int  public_value_;
    void show() { printf("Base::show()\n"); }

protected:
    int protected_value_;
};

class Derived : private Base {
public:
    void access()
    {
        public_value_    = 10;  // OK: privateメンバとしてアクセス可能
        protected_value_ = 20;  // OK: privateメンバとしてアクセス可能
        show();                 // OK: privateメンバとしてアクセス可能
    }
};

class MoreDerived : public Derived {
public:
    void access()
    {
        // public_value_ = 30;   // NG: Baseのメンバにはアクセス不可
    }
};

//  @@@ sample end
TEST(cpp03, private_derived)
{
    // @@@ sample begin 2:1
    Derived d;

    /*
    d.public_value_ = 100;      外部からはアクセス不可
    d.show();                   外部からはアクセス不可  */

    /*
    Base* b_ptr = &d;  public継承とは異なり、これは認められない
    Base& b_ref = d;   public継承とは異なり、これも認められない */
    //  @@@ sample end
    IGNORE_UNUSED_VAR(d);
}
}  // namespace private_derived
