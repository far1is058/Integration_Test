#include <iostream>
#include <cassert>
#include "bigint.hpp"

int main() {

  {

    // setup
    bigint b("4");
    bigint a;
    // test
        a = "4";
    // verification
    assert(b==a);

  }

  {

    // setup
    bigint b("2147483647");
    bigint a("2147483647");
    // test
        
    // verification
    assert(b==a);

  }


  {

    // setup
    bigint b("");

    // test

    //verification
    assert(b == 0);
  }

  {

    // setup
    bigint b(10000000000000000000000000000000000000000);
    bigint c = b.times_10(49);

    // test

    //verification
    std::cout<<c;
  }


return 0;
}
