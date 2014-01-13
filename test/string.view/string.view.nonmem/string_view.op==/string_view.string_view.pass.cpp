//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string_view>

// template<class charT, class traits, class Allocator>
//   bool operator==(const basic_string_view<charT,traits> lhs,
//                   const basic_string_view<charT,traits> rhs);

#include <string_view>
#include <cassert>

#if _LIBCPP_STD_VER > 11

template <class S>
void
test(S lhs, S rhs, bool x)
{
    assert((lhs == rhs) == x);
    assert((rhs == lhs) == x);
}

int main()
{
    {
    typedef std::experimental::string_view S;
    test(S(""), S(""), true);
    test(S(""), S("abcde"), false);
    test(S(""), S("abcdefghij"), false);
    test(S(""), S("abcdefghijklmnopqrst"), false);
    test(S("abcde"), S(""), false);
    test(S("abcde"), S("abcde"), true);
    test(S("abcde"), S("abcdefghij"), false);
    test(S("abcde"), S("abcdefghijklmnopqrst"), false);
    test(S("abcdefghij"), S(""), false);
    test(S("abcdefghij"), S("abcde"), false);
    test(S("abcdefghij"), S("abcdefghij"), true);
    test(S("abcdefghij"), S("abcdefghijklmnopqrst"), false);
    test(S("abcdefghijklmnopqrst"), S(""), false);
    test(S("abcdefghijklmnopqrst"), S("abcde"), false);
    test(S("abcdefghijklmnopqrst"), S("abcdefghij"), false);
    test(S("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), true);
    }
}
#else
int main () {}
#endif
