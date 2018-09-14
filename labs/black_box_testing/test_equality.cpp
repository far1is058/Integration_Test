/**
 * @file test_equality.cpp
 *
 * Tests String class operator==(const String &)
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

int main () {
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("a");
        String  right("x");

        // TEST
        String result = left + right;

        // VERIFY
        assert(result == "ax");
        assert(left   == "a");
        assert(right  == "x");
        assert(result.length() == 2);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    return 0;
}
