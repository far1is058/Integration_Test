###############################################################
# @file Makefile
#
# Makefile for the bigint project
#
# You will need to modify the following lines to compile your tests.
# 1) Add the tests to TESTS variable (line 16). See comments.
# 2) In the tests rule (line 31), add each test file executable.
#
# @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
#

###############################################################
# Variables
CPP  = clang++
OPTS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

TESTS = test_default_ctor test_int_ctor test_subscript test_output

###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo '  tests:'
	@echo '  add:'
	@echo '  multiply:'
	@echo '  factorial:'
	@echo '  clean:'

###############################################################
# Build and run all tests and output demonstration
#
tests: $(TESTS)
	./test_default_ctor
	./test_int_ctor
	./test_subscript
	./test_output
###############################################################
# Compile and run all tests - uses a wild card.
test_%: bigint.o test_%.o
	$(CPP) $(OPTS) -o test_$* bigint.o test_$*.o

test_%.o: bigint.hpp test_%.cpp
	$(CPP) $(OPTS) -c test_$*.cpp



###############################################################
clean:
	rm -f test_*.o
	rm -f $(TESTS)
