#include "bigint.hpp"

bigint::bigint() {
  
  for (int i = 0; i < MAX_DIGITS; ++i) {
    digits[i] = 0;
  }

}

bigint::bigint(int number):bigint() {

  int bigintPos = 0;
  int nextDigit = number;

  while (nextDigit != 0) {
    digits[bigintPos] = nextDigit % 10;
    nextDigit /= 10;
    ++bigintPos;
  }
}

bigint::bigint(const char * cString) : bigint() {

  int stringPos = 0;
  while (cString[stringPos] != '\0') {
    ++stringPos;
  }

  int bigintPos = 0;
  for (int i = stringPos - 1; i >= 0; --i) {
    if(bigintPos >= MAX_DIGITS) {
      break;
    }
    digits[bigintPos] = cString[i] - '0';
    ++bigintPos;
  }

}

bool bigint::operator==(const bigint& lhs) const {

  for (int i = 0; i < MAX_DIGITS; ++i) {
    if (digits[i] != lhs.digits[i]) {
      return false;
    }
  }
  return true;
}

void bigint::debug_print(std::ostream& out) {
  out << "| ";
  for (int i = MAX_DIGITS - 1; i >= 0; --i) {
    out << digits[i] << " | ";
  }
}

std::ostream& operator<<(std::ostream& out, const bigint& bigNumber) {
  bool foundDigits = false;
  int digitsPerLine = 0;
  
  for (int i = bigint::MAX_DIGITS - 1; i > 0; --i) {

    if (!foundDigits) {
      foundDigits = (bigNumber.digits[i] != 0);
    }

    if (foundDigits) {
      out << bigNumber.digits[i];
      ++digitsPerLine;
      if (digitsPerLine == 70) {
        out << '\n';
        digitsPerLine = 0;
      }
    }
  }

  out << bigNumber.digits[0];
  
  return out;
}

int bigint::operator[](int index) const {
  return digits[index];
}

bigint operator+(bigint lhs, const bigint & rhs) { 
  bigint sum;
  int carry = 0;

  for (int i = 0; i < bigint::MAX_DIGITS; ++i) {
    int temp = (lhs.digits[i] + rhs.digits[i] + carry); 
    sum.digits[i] = temp % 10;
    carry = temp / 10;
  }

  return sum;
}

std::istream& operator>>(std::istream& in, bigint& bigData) {
  char arr[bigint::MAX_DIGITS + 1];
  
  int index = 0;
  char data;
  while (in >> data && data != ';') {
    arr[index] = data;
    ++index;
  }

  arr[index] = '\0';

  bigint temp(arr);
  bigData = temp;

  return in;
}

bigint bigint::times_digit(int digit) const {
  bigint result;
  int carry = 0;
  
  for (int i = 0; i < MAX_DIGITS; ++i) {
    int temp = (digits[i] * digit) + carry;
    result.digits[i] = temp % 10;
    carry = temp / 10;
  }

  return result;
}

bigint bigint::times_10(int offset) const {
  bigint result;
  int index = 0;
  
  for (int i = offset; i < MAX_DIGITS; ++i) {
    result.digits[i] = digits[index];
    ++index;
  }
  return result;
}

bigint operator*(bigint lhs, const bigint & rhs) {

  bigint product;
  for (int i = 0; i < bigint::MAX_DIGITS; ++i) {
    bigint temp = lhs.times_digit(rhs.digits[i]);
    product = product + temp.times_10(i);
  }

  return product;
}

