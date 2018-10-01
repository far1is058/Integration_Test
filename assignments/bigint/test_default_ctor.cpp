/**
 * @file test_default_ctor.cpp
 *
 * Tests bigint default ctor.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <cassert>
#include "bigint.hpp"

int main() {

  {

    // setup
    bigint b(4);
    bigint a;    
    // test
	a = 4;
    // verification
    assert(b==a);

  }

  {

    // setup
    bigint b(2147483647);
    bigint a;
    // test
        a = 2147483647;
    // verification
    assert(b==a);

  }


  {

    // setup
    bigint b;
    
    // test
        
    // verification
    assert(b==0);

  }
 

  return 0;
}
