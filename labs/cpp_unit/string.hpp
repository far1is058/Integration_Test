/**
 * @file string.hpp
 *
 * @version 1.0
 * @date Spring 2017
 * @authors Dr. J. Maletic, Michael John Decker
 *
 * Interface definition of a string class.
  */

#ifndef STRING_INTERFACE_HPP
#define STRING_INTERFACE_HPP

#include <iostream>
#include <vector>
#include <cassert>

// size of the array.
const int STRING_SIZE = 8;

/**
 * @invariant str[length()] == 0
 *         && 0 <= length() <= capacity()
 *         && capacity() == STRING_SIZE - 1
 * Note: -1 is for null-terminator
 *
 */
class String {
private:
    char str[STRING_SIZE];
public:
    // constructor: empty string, String('x'), and String("abcd")
    String();
    String(char);
    String(const char[]);

    // subscript: accessor/modifier and accessor
    char & operator[](int);
    char   operator[](int) const;

    // max chars that can be stored (not including null terminator)
    int capacity() const;

    // number of char in string
    int length  () const;

    // Standard string concatenation.
    // What changes in testing if say fized size or dynamic growing?
    String   operator+ (const String &) const;
    String & operator+=(String);

    // relational methods
    bool operator==(const String &) const;
    bool operator< (const String &) const;

    // i/o
    friend std::istream & operator>>(std::istream &, String &);
    friend std::ostream & operator<<(std::ostream &, const String &);

    int find(char, int start_pos) const;
    int find(const String & s, int start_pos) const;
    String substr(int start_pos, int count) const;
    std::vector<String> split(char ch) const;

};

// free functios for concatenation and relational
String operator+       (const char[],  const String &);
String operator+       (char,          const String &);
bool   operator==      (const char[],  const String &);
bool   operator==      (char,          const String &);
bool   operator<       (const char[],  const String &);
bool   operator<       (char,          const String &);
bool   operator<=      (const String &, const String &);
bool   operator!=      (const String &, const String &);
bool   operator>=      (const String &, const String &);
bool   operator>       (const String &, const String &);

#endif
