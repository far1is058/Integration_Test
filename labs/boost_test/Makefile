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

test_driver: test_driver.cpp string.o
	$(CPP) $(OPTIONS) -o test_driver string.o test_driver.cpp

clean:
	rm -f test_driver
