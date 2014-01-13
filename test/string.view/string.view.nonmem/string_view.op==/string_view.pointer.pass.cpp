//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<class charT, class traits>
//   bool operator==(basic_string_view<charT,traits> lhs, const charT* rhs);
// template<class charT, class traits>
//   bool operator==(const charT* lhs, basic_string_view<charT,traits> rhs);

#include <experimental/string_view>
#include <cassert>

#if _LIBCPP_STD_VER > 11

template <class S>
void
test(S lhs, const typename S::value_type* rhs, bool x)
{
    assert((lhs == rhs) == x);
    assert((rhs == lhs) == x);
}

int main()
{
    {
    typedef std::experimental::string_view S;
    test(S(""), "", true);
    test(S(""), "abcde", false);
    test(S(""), "abcdefghij", false);
    test(S(""), "abcdefghijklmnopqrst", false);
    test(S("abcde"), "", false);
    test(S("abcde"), "abcde", true);
    test(S("abcde"), "abcdefghij", false);
    test(S("abcde"), "abcdefghijklmnopqrst", false);
    test(S("abcdefghij"), "", false);
    test(S("abcdefghij"), "abcde", false);
    test(S("abcdefghij"), "abcdefghij", true);
    test(S("abcdefghij"), "abcdefghijklmnopqrst", false);
    test(S("abcdefghijklmnopqrst"), "", false);
    test(S("abcdefghijklmnopqrst"), "abcde", false);
    test(S("abcdefghijklmnopqrst"), "abcdefghij", false);
    test(S("abcdefghijklmnopqrst"), "abcdefghijklmnopqrst", true);
    }
}
#else
int main () {}
#endif
