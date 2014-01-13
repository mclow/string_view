//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//


// <string_view>

// constexpr basic_string_view(const _CharT* _s)
// 	  : __data (_s), __size(_Traits::length(_s)) {}


#include <experimental/string_view>
#include <string>
#include <cassert>

#if _LIBCPP_STD_VER > 11

template<typename CharT>
constexpr size_t StrLen ( const CharT *s ) {
	size_t retVal = 0;
	while ( *s != 0 ) { ++retVal; ++s; }
	return retVal;
	}

template<typename CharT>
void test ( const CharT *s ) {
	{
	std::experimental::basic_string_view<CharT> sv1 ( s );
	assert ( sv1.size() == StrLen( s ));
	assert ( sv1.data() == s );
	}
}

struct dummy_char_traits : public std::char_traits<char> {
    constexpr static size_t length(const char_type* s) {
		size_t retVal = 0;
		while ( *s != 0 ) { ++retVal; ++s; }
		return retVal;
    	}
};


int main () {

	test ( "QBCDE" );
	test ( "A" );
	test ( "" );
	
	test ( L"QBCDE" );
	test ( L"A" );
	test ( L"" );

	test ( u"QBCDE" );
	test ( u"A" );
	test ( u"" );

	test ( U"QBCDE" );
	test ( U"A" );
	test ( U"" );

 	{
 	constexpr std::experimental::basic_string_view<char, dummy_char_traits> sv1 ( "ABCDE" );
 	static_assert ( sv1.size() == 5, "");
 	}
}
#else
int main () {}
#endif
