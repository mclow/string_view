//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//


// <string_view>

// constexpr const _CharT& back();

#include <experimental/string_view>
#include <cassert>

#if _LIBCPP_STD_VER > 11

template <typename CharT>
bool test ( const CharT *s, size_t len ) {
    std::experimental::basic_string_view<CharT> sv ( s, len );
    assert ( sv.length() == len );
    assert ( sv.front() == s[0] );
    return &sv.front() == s;
    }
    
int main () {
    assert ( test ( "ABCDE", 5 ));
    assert ( test ( "a", 1 ));

    assert ( test ( L"ABCDE", 5 ));
    assert ( test ( L"a", 1 ));

    assert ( test ( u"ABCDE", 5 ));
    assert ( test ( u"a", 1 ));

    assert ( test ( U"ABCDE", 5 ));
    assert ( test ( U"a", 1 ));

    {
    constexpr std::experimental::basic_string_view<char> sv ( "ABC", 2 );
    static_assert ( sv.length() ==  2,  "" );
    static_assert ( sv.front()  == 'A', "" );
    }
}
#else
int main () {}
#endif
