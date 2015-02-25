//============================================================================
// File        : PrimeFactors.cpp
// Author      : DS
// Description : Obtain list of prime factors of a number.
//				 Use some heuristics to make it more efficient.
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>

//============================================================================
// Function    : GetPrimeFactors
// Author      : DS
// Description : Take an integer and creates a vector containing all of the
//                integer's prime factors.  Returns an empty vector if the
//                integer is 0 or negative.
//============================================================================
std::vector<int> GetPrimeFactors(int number)
{
	std::vector<int> factors;

	factors.clear();

	// Validate number
	if (number <= 0)
		return factors;

    // Divide out all the 2's
    while (number%2 == 0)
    {
    	factors.push_back(2);
        number = number / 2;
    }

    // Number must be odd at this point.  Check for odd factors.
    for (int x = 3; x <= sqrt(number); x = x+2)
    {
        // While x divides number with no remainder, save x and divide
        while (number%x == 0)
        {
        	factors.push_back(x);
            number = number / x;
        }
    }

    // At this point, if number is > 2, it must contain a prime number,
    //  so save it.
    if (number>2)
    	factors.push_back(number);

    // Done
	return factors;
}





