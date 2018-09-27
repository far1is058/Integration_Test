#ifndef INCLUDED_test_equality_HPP
#define INCLUDED_test_equality_HPP

#include "string.hpp"
#include <TestFixture.h>
#include <TestSuite.h>
#include <TestCaller.h>
#include <extensions/HelperMacros.h>

class test_equality : public CppUnit::TestFixture {

private:
    String * abc;
    String * xyz;

public:

    void setUp() {
	abc = new String("abc");
	xyz = new String("xyz");
    }

    void tearDown() {
	delete abc;
	delete xyz;
    }


    void test_typical() {
	CPPUNIT_ASSERT(*abc == "abc");
	CPPUNIT_ASSERT(*xyz == "xyz");
    }

    void test_typical_not() {
	CPPUNIT_ASSERT(!(*abc == *xyz));
    }

    CPPUNIT_TEST_SUITE(test_equality);
    CPPUNIT_TEST(test_typical);
    CPPUNIT_TEST(test_typical_not);
    CPPUNIT_TEST_SUITE_END();

};

#endif
