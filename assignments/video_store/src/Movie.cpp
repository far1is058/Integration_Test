/*
  Movie.cpp

  Definition file for Movie class
*/

#include "Movie.hpp"
//#include "Price.hpp"
//#include "NewReleasePrice.hpp"
//#include "ChilrenPrice.hpp"
//#include "RegularPrice.hpp"

// constructor
Movie::Movie(const std::string& name, int priceCode){
  
  title = name;
  setPriceCode(priceCode);
}
 
// movie price code
int Movie::getPriceCode() const {

    return price_code;
}

// void Movie::operator=(const Movie &M ) { 
        //m1 = M.m1;
        //m2 = M.m2;
  //  }


// set movie price code
void Movie::setPriceCode(int arg) {
    switch(arg) {
	case REGULAR:
	     price_code = new RegularPrice();
	     break;

	case CHILDRENS:
	     price_code = new ChildrenPrice();
	     break;

	case NEW_RELEASE:
	     price_code = new NewReleasePrice();
	     break;
	
	default:;	     


    }
    
}

// movie title
const std::string& Movie::getTitle() const {

    return title;
}
double Movie::getCharge(int numOfDaysRented) const{


    double thisAmount = 0;
    //determine amounts for each line
    switch (getPriceCode()) {
        case Movie::REGULAR:
            thisAmount += 2;
            if (numOfDaysRented > 2)
                thisAmount += (numOfDaysRented - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += numOfDaysRented * 3;
            break;
        case Movie::CHILDRENS:
            thisAmount += 1.5;
            if (numOfDaysRented > 3)
                thisAmount += (numOfDaysRented - 3) * 1.5;
            break;

    }
    return thisAmount;

}

int Movie::getFrequentRenterPoints(int numOfDaysRented) const {
           // add bonus for a two day new release rental
        if ((getPriceCode() == Movie::NEW_RELEASE) &&
            numOfDaysRented > 1) return 2;
        else
                return 1;

}





