#ifndef NEWRELEASEPRICE_H
#define NEWRELEASEPRICE_H

#include <string>
#include "Price.hpp"



class NewReleasePrice : Price {

        int getPriceCode(){
                return Movie.NEW_RELEASE;
        }

};
#endif

