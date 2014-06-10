//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string_view>

// constexpr int compare(string_view str) const;

#include <experimental/string_view>
#include <cassert>

#include "constexpr_char_traits.hpp"

int sign(int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

template <class S>
void
test(const S& s, S str, int x)
{
    assert(sign(s.compare(str)) == sign(x));
}

int main()
{
    {
    typedef std::experimental::string_view S;
    test(S(""), S(""), 0);
    test(S(""), S("abcde"), -5);
    test(S(""), S("abcdefghij"), -10);
    test(S(""), S("abcdefghijklmnopqrst"), -20);
    test(S("abcde"), S(""), 5);
    test(S("abcde"), S("abcde"), 0);
    test(S("abcde"), S("abcdefghij"), -5);
    test(S("abcde"), S("abcdefghijklmnopqrst"), -15);
    test(S("abcdefghij"), S(""), 10);
    test(S("abcdefghij"), S("abcde"), 5);
    test(S("abcdefghij"), S("abcdefghij"), 0);
    test(S("abcdefghij"), S("abcdefghijklmnopqrst"), -10);
    test(S("abcdefghijklmnopqrst"), S(""), 20);
    test(S("abcdefghijklmnopqrst"), S("abcde"), 15);
    test(S("abcdefghijklmnopqrst"), S("abcdefghij"), 10);
    test(S("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), 0);
    }

#if _LIBCPP_STD_VER > 11
    {
    typedef std::experimental::basic_string_view<char, constexpr_char_traits<char>> SV;
    constexpr SV  sv1 { "abcde", 5 };
    constexpr SV  sv2 { "abcde", 5 };
    constexpr SV  sv3 { "edcba0", 6 };
    static_assert ( sv1.compare(sv2) == 0, "" );
    static_assert ( sv2.compare(sv1) == 0, "" );
    static_assert ( sv3.compare(sv2)  > 0, "" );
    static_assert ( sv2.compare(sv3)  < 0, "" );
    }
#endif
}
