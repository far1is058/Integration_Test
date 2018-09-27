#ifndef INCLUDED_test_cstring_ctor_HPP
#define INCLUDED_test_cstring_ctor_HPP

#include "string.hpp"
#include <TestFixture.h>
#include <TestSuite.h>
#include <TestCaller.h>
#include <extensions/HelperMacros.h>

class test_cstring_ctor : public CppUnit::TestFixture {


    void test_typical() {
	String s("abc");
	
	CPPUNIT_ASSERT(s[0] == 'a');
	CPPUNIT_ASSERT(s[1] == 'b');
	CPPUNIT_ASSERT(s[2] == 'c');
	CPPUNIT_ASSERT(s.length() == 3);
    }
	
    void test_boundary() {
	String s("abc");

        CPPUNIT_ASSERT(s[0] == 'a');
        CPPUNIT_ASSERT(s[2] == 'c');

    }
    
    void test_empty() {
        String s("");

        CPPUNIT_ASSERT(s.length()== 0);
        

    }


    CPPUNIT_TEST_SUITE(test_cstring_ctor);
    CPPUNIT_TEST(test_typical);
    CPPUNIT_TEST(test_boundary);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST_SUITE_END();

};

#endif
