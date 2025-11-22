#include "gtest_wrapper.h"

#include "suppress_warning.h"

namespace const_member {
// @@@ sample begin 0:0

class Rectangle {
public:
    Rectangle(int w, int h) : width_(w), height_(h), area_cache_(0), cache_valid_(false) {}
    //                                   ^^^ height_の値代入は初期化リストのみで行える

    int GetWidth() const { return width_; }    // constメンバ関数: オブジェクトの状態を変更しない
    int GetHeight() const { return height_; }  // constメンバ関数: オブジェクトの状態を変更しない

    // mutableメンバは変更可能
    int GetArea() const
    {
        if (!cache_valid_) {
            area_cache_  = width_ * height_;
            cache_valid_ = true;
        }
        return area_cache_;
    }

    // 非constメンバ関数であるため、オブジェクトの状態を変更できる
    void SetWidth(int w)
    {
        width_       = w;
        cache_valid_ = false;
    }

    SUPPRESS_WARN_BEGIN;         // @@@ delete
    SUPPRESS_WARN_UNUSED_PARAM;  // @@@ delete
    void SetHeight(int h)
    {
        /* height_はconstであり変更できないため、コンパイルエラー
        height_      = h;
        */
        cache_valid_ = false;
    }
    SUPPRESS_WARN_END;  // @@@ delete

private:
    int          width_;
    int const    height_;      // height_はオブジェクトの生成後、不変
    mutable int  area_cache_;  // mutableメンバ
    mutable bool cache_valid_;
};
// @@@ sample end

TEST(cpp03, const_member)
{
    // @@@ sample begin 0:1

    Rectangle rect0(10, 30);
    rect0.SetWidth(3);
    ASSERT_EQ(90, rect0.GetArea());

    Rectangle const rect1(1, 3);
    /* rect1がconstであるため、下記コードはコンパイルエラー
    rect1.SetWidth(3);
    */
    // @@@ sample end
}
}  // namespace const_member
