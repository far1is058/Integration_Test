#include <iostream>
#include <cassert>
#include "bigint.hpp"
#include <sstream>
int main() {

  
   {
	//Setup
    	
	std::stringstream c;
	c << "";
	//Test
	
	
	//Varification
	
    	
	assert(c.str().empty());
    }


     {
        //Setup

        std::stringstream c;
        c << "123456789";
        //Test


        //Varification


        assert(c.str()=="123456789");
    }

    {
        //Setup

        std::stringstream c;
        c << "123456789015487";
        //Test


        //Varification


        assert(c.str()=="123456789015487");
    }



  return 0;
}

