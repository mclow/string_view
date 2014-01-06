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
//   bool operator!=(const basic_string_view<charT,traits> lhs,
//                   const basic_string_view<charT,traits> rhs);

#include <string_view>
#include <cassert>

template <class S>
void
test(S lhs, S rhs, bool x)
{
    assert((lhs != rhs) == x);
    assert((rhs != lhs) == x);
}

int main()
{
    {
    typedef std::experimental::string_view S;
    test(S(""), S(""), false);
    test(S(""), S("abcde"), true);
    test(S(""), S("abcdefghij"), true);
    test(S(""), S("abcdefghijklmnopqrst"), true);
    test(S("abcde"), S(""), true);
    test(S("abcde"), S("abcde"), false);
    test(S("abcde"), S("abcdefghij"), true);
    test(S("abcde"), S("abcdefghijklmnopqrst"), true);
    test(S("abcdefghij"), S(""), true);
    test(S("abcdefghij"), S("abcde"), true);
    test(S("abcdefghij"), S("abcdefghij"), false);
    test(S("abcdefghij"), S("abcdefghijklmnopqrst"), true);
    test(S("abcdefghijklmnopqrst"), S(""), true);
    test(S("abcdefghijklmnopqrst"), S("abcde"), true);
    test(S("abcdefghijklmnopqrst"), S("abcdefghij"), true);
    test(S("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), false);
    }
}
