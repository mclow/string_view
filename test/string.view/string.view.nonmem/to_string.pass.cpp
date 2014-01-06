//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//


// <string_view>

// 	template<class _CharT, class _Traits = char_traits<_CharT>, class Allocator = allocator<_CharT> >
//  basic_string<_CharT, _Traits, Allocator> to_string (
// 	        basic_string_view<_CharT, _Traits> _sv, const Allocator& _a = Allocator())

#include <string_view>
#include <cassert>

template<typename CharT>
void test ( const CharT *s ) {
	{
	std::experimental::basic_string_view<CharT> sv1 { s };
	std::basic_string<CharT>                    str { to_string(sv1) };

	assert ( sv1.size() == str.size ());
	assert ( std::char_traits<CharT>::compare ( sv1.data(), str.data(), sv1.size()) == 0 );
	}

	{
	std::experimental::basic_string_view<CharT> sv1 {};
	std::basic_string<CharT>                    str { to_string(sv1) };

	assert ( sv1.size() == str.size ());
	assert ( std::char_traits<CharT>::compare ( sv1.data(), str.data(), sv1.size()) == 0 );
	}
}

int main () {
	test ( "ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDE" );
	test ( "ABCDE");
	test ( "a" );
	test ( "" );

	test ( L"ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDE" );
	test ( L"ABCDE" );
	test ( L"a" );
	test ( L"" );

	test ( u"ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDE" );
	test ( u"ABCDE" );
	test ( u"a" );
	test ( u"" );

	test ( U"ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDE" );
	test ( U"ABCDE" );
	test ( U"a" );
	test ( U"" );
}
