#include <iostream>
#include <cassert>
#include "bigint.hpp"
#include <sstream>
int main() {

  
   {
	//Setup
    	bigint b(111);
	std::ostringstream c;
	c << b;
	//Test
	
	
	//Varification
	
    	
	assert(!(c.str().empty()));
    }


     {
        //Setup
	bigint b;
        std::stringstream c;
        c << b;
        //Test


        //Varification


        assert(c.str().empty());
    }

    {
        //Setup
	bigint b("123456789");
        std::stringstream c;
        c << b;
        //Test


        //Varification


        assert(c.str()=="123456789");
    }



  return 0;
}

