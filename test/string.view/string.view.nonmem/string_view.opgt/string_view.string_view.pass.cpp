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
//   bool operator>(basic_string_view<charT,traits> lhs,
//                  basic_string_view<charT,traits> rhs);
//   bool operator>(basic_string_view<charT,traits> lhs,
//                  basic_string_view<charT,traits> rhs);

#include <string_view>
#include <cassert>

#if _LIBCPP_STD_VER > 11

template <class S>
void
test(const S& lhs, const S& rhs, bool x, bool y)
{
    assert((lhs > rhs) == x);
    assert((rhs > lhs) == y);
}

int main()
{
    {
    typedef std::experimental::string_view S;
    test(S(""), S(""), false, false);
    test(S(""), S("abcde"), false, true);
    test(S(""), S("abcdefghij"), false, true);
    test(S(""), S("abcdefghijklmnopqrst"), false, true);
    test(S("abcde"), S(""), true, false);
    test(S("abcde"), S("abcde"), false, false);
    test(S("abcde"), S("abcdefghij"), false, true);
    test(S("abcde"), S("abcdefghijklmnopqrst"), false, true);
    test(S("abcdefghij"), S(""), true, false);
    test(S("abcdefghij"), S("abcde"), true, false);
    test(S("abcdefghij"), S("abcdefghij"), false, false);
    test(S("abcdefghij"), S("abcdefghijklmnopqrst"), false, true);
    test(S("abcdefghijklmnopqrst"), S(""), true, false);
    test(S("abcdefghijklmnopqrst"), S("abcde"), true, false);
    test(S("abcdefghijklmnopqrst"), S("abcdefghij"), true, false);
    test(S("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), false, false);
    }
}
#else
int main () {}
#endif
