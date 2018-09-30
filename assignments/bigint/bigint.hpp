/**
 *  @file bigint.hpp
 *
 *  Interface to a bigint class, implementing an
 *  arbitrary precision integer (of fixed array size).
 *
 *  @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

class bigint {

public:
  static const int MAX_DIGITS = 50;

private:
  int digits[MAX_DIGITS];

public:

  // constructors
  bigint();
  bigint(int number);
  bigint(const char * number);
  
  bool operator==(const bigint & rhs);

  int operator[](int pos) const;

  bigint times_digit(int digit) const;
  bigint times_10(int number) const;

  friend bigint operator+(bigint lhs, const bigint & rhs);
  friend bigint operator*(bigint lhs, const bigint & rhs);

  void debug_print(std::ostream & out);
  friend std::ostream& operator<<(std::ostream & out, const bigint & rhs);
  friend std::istream& operator>>(std::istream & in, bigint & rhs);

};


#endif
