//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//


// <string_view>

// void remove_prefix(size_type _n)

#include <string_view>
#include <cassert>
#include <iostream>

template<typename CharT>
void test ( const CharT *s, size_t len ) {
	{
	std::experimental::basic_string_view<CharT> sv1 ( s );
	assert ( sv1.size() == len );
	assert ( sv1.data() == s );

	if ( len > 0 ) {
		sv1.remove_prefix ( 1 );
		assert ( sv1.size() == (len - 1));
		assert ( sv1.data() == (s + 1));
	}
	
	sv1.remove_prefix ( len - 1 );
	assert ( sv1.size() == 0 );

	std::experimental::basic_string_view<CharT> sv2 ( s );
	sv2.remove_prefix ( len << 1 );
	assert ( sv1.size() == 0 );	
	}
}

int main () {
	test ( "ABCDE", 5 );
	test ( "a", 1 );
	test ( "", 0 );

	test ( L"ABCDE", 5 );
	test ( L"a", 1 );
	test ( L"", 0 );

	test ( u"ABCDE", 5 );
	test ( u"a", 1 );
	test ( u"", 0 );

	test ( U"ABCDE", 5 );
	test ( U"a", 1 );
	test ( U"", 0 );
}
