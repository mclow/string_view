//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//


// <string_view>

// void swap(basic_string_view& _other) noexcept

#include <string_view>
#include <cassert>

template<typename CharT>
void test ( const CharT *s, size_t len ) {
	{
	std::experimental::basic_string_view<CharT> sv1{s};
	std::experimental::basic_string_view<CharT> sv2{};
	
	assert ( sv1.size() == len );
	assert ( sv1.data() == s );
	assert ( sv2.size() == 0 );

	sv1.swap ( sv2 );
	assert ( sv1.size() == 0 );
	assert ( sv2.size() == len );
	assert ( sv2.data() == s );
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
