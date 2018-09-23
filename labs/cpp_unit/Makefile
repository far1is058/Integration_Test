##
# @file Makefile
#
# @version 1.0
# @date Fall 2018
# @authors Michael John Decker, Ph.D.
#
# Makefile for string class.
#

all: string.o

###############################################################
# Variables
CPP     = g++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++0x

###############################################################
# Run all of your tests
tests: test_driver
	./test_driver

###############################################################
# Compile all tests
#

test_driver: test_driver.cpp string.o # REMOVE This and add test hpp.cpp
	$(CPP) $(OPTIONS) -I /usr/include/cppunit/ -o test_driver -lcppunit string.o test_driver.cpp # add cpp files here

clean:
	rm -f test_driver
