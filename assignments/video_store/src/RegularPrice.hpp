#ifndef REGULARPRICE_H
#define REGULARPRICE_H

#include <string>
#include "Price.hpp"



class RegularPrice : Price {

        int getPriceCode(){
                return Movie.REGULAR;
        }

};
#endif

