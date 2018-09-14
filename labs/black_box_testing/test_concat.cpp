/**
 * @file test_concat.cpp
 *
 * Tests String class operator+
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

//===========================================================================
int main () {

    // This follows more closely to methdology on deriving tests
    // Would order tests differently for TDD.  Might also have more because incremental build up.
    // Show after write.
    // Categories: 
    // Input empty, singles, multi
    // Output: empty, single, multi
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("ab");
        String  right("xyz");

        // TEST
        String result;
        result = left + right;

        // VERIFY
        assert(left   == "ab");
        assert(right  == "xyz");
        assert(result == "abxyz");
        assert(result.length() == 5);
        // less important in this implementation, but would be or dynamic allocated
        // could use same tests. That being said, may never need dynamic allocated, so...
        assert(result.capacity() >= STRING_SIZE-1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "abc");
        assert(left   == "abc");
        assert(right  == "");
        assert(result.length() == 3);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("d");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "abcd");
        assert(left   == "abc");
        assert(right  == "d");
        assert(result.length() == 4);
        assert(result.capacity() >= STRING_SIZE-1);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right("xyz");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "xyz");
        assert(left   == "");
        assert(right  == "xyz");
        assert(result.length() == 3);
        assert(result.capacity() >= STRING_SIZE-1);
    }
   
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("w");
        String  right("xyz");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "wxyz");
        assert(left   == "w");
        assert(right  == "xyz");
        assert(result.length() == 4);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right("");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "");
        assert(left   == "");
        assert(right  == "");
        assert(result.length() == 0);
        assert(result.capacity() >= STRING_SIZE-1);
    }
    
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
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right("x");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "x");
        assert(left   == "");
        assert(right  == "x");
        assert(result.length() == 1);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("a");
        String  right("");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "a");
        assert(left   == "a");
        assert(right  == "");
        assert(result.length() == 1);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("a");
        String  right("");
        
        // TEST
        String result = left + right;
        
        // VERIFY
        assert(result == "a");
        assert(left   == "a");
        assert(right  == "");
        assert(result.length() == 1);
        assert(result.capacity() >= STRING_SIZE-1);
    }

    return 0;
}

