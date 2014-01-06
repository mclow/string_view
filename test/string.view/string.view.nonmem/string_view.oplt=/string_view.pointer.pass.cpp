//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<class charT, class traits, class Allocator>
//   bool operator<=(const charT* lhs, basic_string_wiew<charT,traits> rhs);
// template<class charT, class traits, class Allocator>
//   bool operator<=(basic_string_wiew<charT,traits> lhs, const charT* rhs);

#include <string_view>
#include <cassert>

template <class S>
void
test(const typename S::value_type* lhs, const S& rhs, bool x, bool y)
{
    assert((lhs <= rhs) == x);
    assert((rhs <= lhs) == y);
}

int main()
{
    {
    typedef std::experimental::string_view S;
    test("", S(""), true, true);
    test("", S("abcde"), true, false);
    test("", S("abcdefghij"), true, false);
    test("", S("abcdefghijklmnopqrst"), true, false);
    test("abcde", S(""), false, true);
    test("abcde", S("abcde"), true, true);
    test("abcde", S("abcdefghij"), true, false);
    test("abcde", S("abcdefghijklmnopqrst"), true, false);
    test("abcdefghij", S(""), false, true);
    test("abcdefghij", S("abcde"), false, true);
    test("abcdefghij", S("abcdefghij"), true, true);
    test("abcdefghij", S("abcdefghijklmnopqrst"), true, false);
    test("abcdefghijklmnopqrst", S(""), false, true);
    test("abcdefghijklmnopqrst", S("abcde"), false, true);
    test("abcdefghijklmnopqrst", S("abcdefghij"), false, true);
    test("abcdefghijklmnopqrst", S("abcdefghijklmnopqrst"), true, true);
    }
}
