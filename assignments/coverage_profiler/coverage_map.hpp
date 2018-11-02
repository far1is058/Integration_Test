/**
 * @file coverage_map.hpp
 *
 * Class to store what elements are covered in the program.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#ifndef INCLUDED_COVERAGE_MAP_HPP
#define INCLUDED_COVERAGE_MAP_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class coverage_map_t {

private:
    typedef std::map<std::string, std::vector<bool>>::iterator map_itr;
    typedef std::pair<std::string, std::vector<bool>> map_entry;

    std::string filename;
    std::map<std::string, std::vector<bool>> map;

public:

    coverage_map_t(const std::string & name) : filename(name), map() {}

    void append(const std::string & function_name, size_t num_elements) {

        map_itr itr = map.find(function_name);
        if(itr != map.end()) return;

        map.insert(itr, map_entry(function_name, std::vector<bool>(num_elements, false)));

    }

    void executed(const std::string & function_name, size_t element_executed) {

        map[function_name][element_executed] = true;

    }

    void print() {

        std::cout << '\n' << filename << '\n';
        for(const map_entry & entry : map) {

            std::cout << "function " << std::setw(10) << std::left << (entry.first + ":");

	    double percent_executed = 100;
	    if(entry.second.size() != 0) {
	      double num_executed = std::count(entry.second.begin(), entry.second.end(), true);
	      percent_executed = (num_executed / entry.second.size()) * 100;  
	    }
            std::cout << std::setprecision(2) << std::fixed << percent_executed << '\n';

        }

    }

};

#endif
