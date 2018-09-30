/**
 * @file test_subscript.cpp
 *
 * Tests bigint subscript.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <cassert>
#include "bigint.hpp"

int main() {

  {
    // setup
    bigint b("1000000000000000000000000200000000000000000000000");
    b = b.times_10(1);
    b = b + 3;

    // test
    int result = b[0];

    // verify
    assert(result == 3);
  }

  {
    // setup
    bigint b("1000000000000000000000000200000000000000000000000");
    b = b.times_10(1);
    b = b + 3;

    // test
    int result = b[24];

    // verify
    assert(result == 2);
  }

  {
    // setup
    bigint b("1000000000000000000000000200000000000000000000000");
    b = b.times_10(1);
    b = b + 3;

    // test
    int result = b[49];

    // verify
    assert(result == 1);
  }



  return 0;
}
