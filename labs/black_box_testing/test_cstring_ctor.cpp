/**
 * @file test_cstring_ctor.cpp
 *
 * Tests String class C string constructor.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

int main () {
	 // SETUP FIXTURE
        String  left("abcd");
        String  right("xyz");

        // TEST
        String result;
        result = left + right;

        // VERIFY
        assert(left   == "abcd");
        assert(right  == "xyz");
        assert(result == "abcdxyz");
        assert(result.length() == 7);
	assert(result.capacity() >= STRING_SIZE-1);
    return 0;
}
