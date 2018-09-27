/**
 * @file file.hpp
 *
 * This is a generic C++ header template.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#ifndef INCLUDED_test_default_ctor_HPP
#define INCLUDED_test_default_ctor_HPP

#include "string.hpp"
#include <TestFixture.h>
#include <TestSuite.h>
#include <TestCaller.h>
#include <extensions/HelperMacros.h>

class test_default_ctor : public CppUnit::TestFixture {


    void test_typical() {
	String s;
	CPPUNIT_ASSERT(s.length() == 0);
	CPPUNIT_ASSERT(s.capacity() == (STRING_SIZE - 1));
    }

    CPPUNIT_TEST_SUITE(test_default_ctor);
    CPPUNIT_TEST(test_typical);
    CPPUNIT_TEST_SUITE_END();

};

#endif
