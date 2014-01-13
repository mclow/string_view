//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//


// <string_view>

// void clear() noexcept

#include <experimental/string_view>
#include <cassert>

#if _LIBCPP_STD_VER > 11

template<typename CharT>
void test ( const CharT *s, size_t len ) {
	{
	std::experimental::basic_string_view<CharT> sv1 ( s );
	assert ( sv1.size() == len );
	assert ( sv1.data() == s );

	sv1.clear ();
	assert ( sv1.size() == 0 );
	assert ( sv1 == std::experimental::basic_string_view<CharT>{} );
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
#else
int main () {}
#endif
