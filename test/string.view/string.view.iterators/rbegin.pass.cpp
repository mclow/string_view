//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string_view>

// const_iterator rbegin() const;

#include <experimental/string_view>
#include <cassert>

#if _LIBCPP_STD_VER > 11

template <class S>
void
test(S s)
{
    const S& cs = s;
    typename S::reverse_iterator b = s.rbegin();
    typename S::const_reverse_iterator cb1 = cs.rbegin();
    typename S::const_reverse_iterator cb2 = s.crbegin();
    if (!s.empty())
    {
    	const size_t last = s.size() - 1;
        assert(   *b ==  s[last]);
        assert(  &*b == &s[last]);
        assert( *cb1 ==  s[last]);
        assert(&*cb1 == &s[last]);
        assert( *cb2 ==  s[last]);
        assert(&*cb2 == &s[last]);
        
    }
    assert(  b == cb1);
    assert(  b == cb2);
    assert(cb1 == cb2);
}


int main()
{
	using string_view    = std::experimental::string_view;
	using u16string_view = std::experimental::u16string_view;
	using u32string_view = std::experimental::u32string_view;
	using wstring_view   = std::experimental::wstring_view;

    test(string_view   {});
    test(string_view   { "123"});
    test(u16string_view{});
    test(u16string_view{u"123"});
    test(u32string_view{});
    test(u32string_view{U"123"});
    test(wstring_view  {});
    test(wstring_view  {L"123"});
}
#else
int main () {}
#endif
