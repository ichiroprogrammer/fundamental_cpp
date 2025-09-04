#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gtest_wrapper.h"

namespace {
// @@@ sample begin 0:0

void c_str_add(char const* first, char const* second, char** result)
{
    assert(first && second && result);

    size_t len1 = strlen(first);
    size_t len2 = strlen(second);
    *result = (char *)malloc(len1 + len2 + 1); // +1 for null terminator

    if (!*result) {
        return;
    }

    strcpy(*result, first);
    strcat(*result, second);
}
// @@@ sample end

TEST(cpp03, c_style)
{
    // @@@ sample begin 0:1

    char const* first = "first";
    char const* second = ":second";
    char* result = NULL;

    c_str_add(first, second, &result);
    
    ASSERT_STREQ("first:second", result);

    free(result);   // この行を実行しないとメモリーリーク
    // @@@ sample end
}
}

namespace {
// @@@ sample begin 1:0

struct String {

    char const* str;
    bool  str_allocated;

    ~String() { // デストラクタ
        if(str_allocated) {
            free((void*)str);
        }
    }
};
// @@@ sample end
// @@@ sample begin 1:1

void String_add(String const* first, String const* second, String* result)
{
    assert(first && second && result);

    result->str = NULL;
    result->str_allocated = false;

    size_t len1 = strlen(first->str);
    size_t len2 = strlen(second->str);
    char *str_buf = (char *)malloc(len1 + len2 + 1); // +1 for null terminator

    if (!str_buf) {
        return;
    }

    strcpy(str_buf, first->str);
    strcat(str_buf, second->str);

    result->str = str_buf;
    result->str_allocated = true;
}
// @@@ sample end

TEST(cpp03, cpp_style)
{
    // @@@ sample begin 1:2

    String first;
    String second;

    first.str = "first";
    first.str_allocated = false;

    second.str = ":second";
    second.str_allocated = false;

    String result;
    String_add(&first, &second, &result);
    
    ASSERT_STREQ("first:second", result.str);

    // Stringのデストラクタ(~String())はここで呼び出されるため、result.strがfreeされる
    // @@@ sample end
}
}
