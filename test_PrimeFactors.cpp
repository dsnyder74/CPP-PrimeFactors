//============================================================================
// File        : test_PrimeFactors.cpp
// Author      : DS
// Description : Unit tests for PrimeFactors function
//============================================================================

#ifdef _UNIT_TEST

# include "gtest/gtest.h"
# include "PrimeFactors.h"

#include <stdio.h>
#include <vector>

TEST(GetPrimeFactorsTest, negative) {
	std::vector<int> emptyVector;
    EXPECT_EQ(emptyVector, GetPrimeFactors(-5));
}

TEST(GetPrimeFactorsTest, zero) {
	std::vector<int> emptyVector;
    EXPECT_EQ(emptyVector, GetPrimeFactors(0));
}


TEST(GetPrimeFactorsTest, postive) {
	int testInts1[] = {2,5};
	std::vector<int> testVector1 (testInts1, testInts1 + (sizeof(testInts1) / sizeof(int)) );
	EXPECT_EQ(testVector1, GetPrimeFactors(10));

	int testInts2[] = {3,5,823};
	std::vector<int> testVector2 (testInts2, testInts2 + (sizeof(testInts2) / sizeof(int)) );
	EXPECT_EQ(testVector2, GetPrimeFactors(12345));

// This unit test will fail, as the proper vector for GetPrimeFactors(54321) is {3,19,953}
/*
	int testInts3[] = {3,5,823};
	std::vector<int> testVector3 (testInts3, testInts3 + (sizeof(testInts3) / sizeof(int)) );
	EXPECT_EQ(testVector3, GetPrimeFactors(54321));
*/
}


GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif  // #ifdef _UNIT_TEST

