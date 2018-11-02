###
# @file Makefile
#
# @author Michael John Decker, Ph.D.
# Copyright 2018 Bowling Green State University. All rights reserved.
# Make file for coverage
#

###############################################################
# Variables
CPP      = g++
CPP_OPTS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

###############################################################
# The first rule is run if only make is typed
msg:
	@echo 'Targets are:'
	@echo '  coverage:'
	@echo '  simple_main:'
	@echo '  c-simple_main:'
	@echo '  test_output:'
	@echo '  c-test_output:'
	@echo '  clean:'

###############################################################
coverage : main.o syntax_tree.o 
	$(CPP) $(CPP_OPTS) main.o syntax_tree.o -o coverage

main.o : main.cpp syntax_tree.hpp
	$(CPP) $(CPP_OPTS) -c main.cpp

syntax_tree.o   : syntax_tree.hpp syntax_tree.cpp
	$(CPP) $(CPP_OPTS) -c syntax_tree.cpp

###############################################################

simple_main : simple_main.cpp
	$(CPP) $(CPP_OPTS) simple_main.cpp -o simple_main

c-simple_main : c-simple_main.cpp coverage_map.hpp
	$(CPP) $(CPP_OPTS) c-simple_main.cpp -o c-simple_main

test_output : test_output.cpp bigint.cpp bigint.hpp
	$(CPP) $(CPP_OPTS) test_output.cpp bigint.cpp -o test_output

c-test_output : c-test_output.cpp bigint.cpp bigint.hpp coverage_map.hpp
	$(CPP) $(CPP_OPTS) c-test_output.cpp c-bigint.cpp -o c-test_output

###############################################################

#This will clean up everything via "make clean"
clean:
	rm -f coverage
	rm -f simple_main
	rm -f c-simple_main
	rm -f test_output
	rm -f c-test_output
	rm -f *.o

