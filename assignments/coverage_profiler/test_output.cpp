// bigint Test Program
//
// Tests:  testing oracle for subscript
//
#include <iostream>
#include <cassert>
#include <sstream>
#include "bigint.hpp"

//===========================================================================
int main() {
    
    // 0 test
    {
        // Setup
        bigint bi;

        // Test 
        std::ostringstream out;
        out << bi;

        // Verify
        assert(out.str() == "0");
    }

    // 1 digit
    {
        // Setup
        bigint bi(1);

        // Test 
        std::ostringstream out;
        out << bi;

        // Verify
        assert(out.str() == "1");
    }

    // typical
    {
        // Setup
        bigint bi("1234567890");

        // Test 
        std::ostringstream out;
        out << bi;

        // Verify
        assert(out.str() == "1234567890");
    }

    // 49 digit (MAX - 1)
    {
        // Setup
        bigint bi("1234567890123456789012345678901234567890123456789");

        // Test 
        std::ostringstream out;
        out << bi;

        // Verify
        assert(out.str() == "1234567890123456789012345678901234567890123456789");
    }

    // 50 digit (MAX - 1)
    {
        // Setup
        bigint bi("12345678901234567890123456789012345678901234567890");

        // Test 
        std::ostringstream out;
        out << bi;

        // Verify
        assert(out.str() == "12345678901234567890123456789012345678901234567890");
    }

    std::cout << "Done testing operator<<" << std::endl;
    return 0;
}

