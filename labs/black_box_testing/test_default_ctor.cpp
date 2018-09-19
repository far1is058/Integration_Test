/**
 * @file test_default_ctor.cpp
 *
 * Tests String class default constructor.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include "string.hpp"

#include <cassert>
#include <iostream>

int main () {

	String S = "";
	assert(S.length()==0);
	//assert(S.capacity()==0;
	//assert(S[0]=='\0');
	
    return 0;
}
