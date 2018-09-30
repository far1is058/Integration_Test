#include <iostream>
#include <cassert>
#include "bigint.hpp"

int main() {

  
   {
	//Setup
    	bigint b =4, a =3, c;
	
	//Test
	c=a*b;//12
	
	//Varification
	if(c==12)
    		std::cout<< c <<std::endl;
	else
		std::cout<<"a*b != 12"<<std::endl;
    	
	assert(a*b == 12);
	}


    {
        //Setup
        bigint b(1234567890);

        //Test
	if(b == "1234567890")
                std::cout<< b <<std::endl;
        else
                std::cout<<"b != 1234567890"<<std::endl;
        

        //Varification
        assert(b == "1234567890");
    }

  return 0;
}

