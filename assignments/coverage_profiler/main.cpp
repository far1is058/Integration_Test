/**
 *  @file main.cpp
 *
 *  @author Michael John Decker, Ph.D.
 *  Copyright 2018 Bowling Green State University. All rights reserved.
 *
 *  Coverage instrumentor, requires main.cpp first, followed by other files.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "syntax_tree.hpp"

// Reads a srcML file into an internal data structure.
// Then prints out the data structure.

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Input file(s) are required." << std::endl;
        std::cerr << "       The main must be the first argument followed by ";
        std::cerr << "any other .cpp files.  For example:" << std::endl;
        std::cerr << "coverage main.cpp.xml file1.cpp.xml file2.cpp.xml";
        std::cerr << std::endl << std::endl;
        return(1);
    }

    // Source code to be profiled.
    srcml code;
    // List of file names (no .xml)
    std::vector<std::string>  files;
    // List of profile names
    std::vector<std::string>  coverage_names;

    for (int i = 1; i < argc; ++i) {
        std::string filename = argv[i];
        files.push_back(filename);
        // Remove .xml
        filename = filename.substr(0, filename.find(".xml"));
        // . => _
        std::replace(filename.begin(), filename.end(), '.', '_');
        coverage_names.push_back(filename);
    }

    // Read in the main.
    std::ifstream in_file(files[0].c_str());
    in_file >> code;
    in_file.close();
    
    // test copy ctor
    // test_copy(code);

    // Add in main header info
    code.main_header(coverage_names);
    // Add in the report
    code.main_report(coverage_names);
    // Instrument functions
    code.instrument_functions(coverage_names[0]);

    std::string out_file_name = "c-" + files[0];
    out_file_name = out_file_name.substr(0, out_file_name.find(".xml"));
    std::ofstream out_file(out_file_name.c_str());
    out_file << code << std::endl;
    out_file.close();

    // Read rest of the files.
    for (unsigned i = 1; i < files.size(); ++i) {
        in_file.open(files[i].c_str());
        in_file >> code;
        in_file.close();

        // Add in file header info
        code.file_header(coverage_names[i]);
        // Instrument functions
        code.instrument_functions(coverage_names[i]);

        out_file_name = "c-" + files[i];
        out_file_name = out_file_name.substr(0, out_file_name.find(".xml"));
        out_file.open(out_file_name.c_str());
        out_file << code << std::endl;
        out_file.close();
    }

    return 0;
}
