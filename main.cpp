//============================================================================
// File        : main.cpp
// Author      : DS
// Description : Main program loop
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "PrimeFactors.h"

//============================================================================
// Function    : IntVectorToString
// Author      : DS
// Description : Converts vector of ints to a comma delimited string
//============================================================================
std::string IntVectorToString(std::vector<int> v)
{
	std::stringstream ss;

	for(std::vector<int>::const_iterator i=v.begin(); i!=v.end(); ++i) {
		ss << (*i);
		if (i!=v.end()-1)
			ss << ", ";
	}

	return ss.str();
}

// Have _UNIT_TEST defined in the project's build settings to conduct unit testing
//   using gTest (googletest - https://code.google.com/p/googletest/)
// Leave undefined to have program operate normally
#ifndef _UNIT_TEST

//============================================================================
// Function    : main
// Author      : DS
// Description : Main program loop
//============================================================================
int main(int argc, char* argv[] )
{

	// Validate command line arguments
	if (argc!=2) {
		std::cerr << "Program requires a filename as its single argument" << std::endl; // prints !!!Hello World!!!
		return -1;
	}

	// Open the file
    std::ifstream file(argv[1],std::ifstream::in);
	std::string line;
    if (!file)
    {
        std::cerr << "Unable to open file " << argv[1] << std::endl;
        return -2;
    }

    // For each line, find the prime factors
    while (std::getline(file, line))
    {
    	// Parse the line into an integer
    	int integerDatum=0;
    	std::istringstream iss(line);
    	iss >> integerDatum;

    	// If a valid integer...
		if (integerDatum>0) {
			// Get the prime factors
			std::vector<int> f = GetPrimeFactors(integerDatum);
			// Convert the vector to a string
			std::string primeFactorsList = IntVectorToString(f);
			// And print it
			std::cout<<primeFactorsList<<std::endl;
		}
    }
    file.close();

	return 0;
}

#endif  // #ifndef _UNIT_TEST
