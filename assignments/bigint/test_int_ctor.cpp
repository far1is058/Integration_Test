/**
 * @file test_int_ctor.cpp
 *
 * Tests bigint int ctor.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <cassert>
#include "bigint.hpp"

int main() {

  {

    // setup
    bigint b(0);

    // test

    // verification
    assert(b == bigint());

  }

  {

    // setup
    bigint b(1000000);

    // test

    // verification
    assert(b == bigint("1000000"));

  }

 // {

    // setup
//    bigint b(2147483647);

    // test

    // verification
//    assert(b == bigint("2147483647"));

 // }

  return 0;
}
