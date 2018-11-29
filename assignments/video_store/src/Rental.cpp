/*
  Rental.cpp

  Definition file for Rental class.
*/

#include "Rental.hpp"

// constructor
Rental::Rental(const Movie& movie, int days_rented)
    : movie(movie), days(days_rented)
{ }

// days rented
int Rental::getDaysRented() const {

    return days;
}

// movie rented
const Movie& Rental::getMovie() const {

    return movie;
}

double Rental::getCharge()const {
      
   return movie.getCharge(getDaysRented());
}

int Rental::getFrequentRenterPoints() const {
           // add bonus for a two day new release rental
        if ((getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
            getDaysRented() > 1) return 2;
        else
                return 1;

}


