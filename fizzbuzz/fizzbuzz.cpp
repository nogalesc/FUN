//Author: Chris Nogales
//Date:   1/29/2016

// How to build:

// -Wall         = Warn all
// -o            = names the executable

// $ g++ -Wall -o NAME_OF_EXE NAME_OF_SRC.cpp


// "Write a program that prints the numbers from 1 to 100.
// But for multiples of three print “Fizz” instead of the 
// number and for the multiples of five print “Buzz”. 
// For numbers which are multiples of both three and five print “FizzBuzz”.

#include <iostream>

int main()
{
	for(int i=1; i<=100; ++i)
	{
		if(i%3 == 0)      	// Print Fizz for multiples of 3
		{
 			std::cout << " Fizz" << std::endl;
		}
		else if (i%5 == 0)  // Print Buzz for multiples of 5
		{
 			std::cout << " Buzz" << std::endl;
		}
		if( (i%3 == 0) && (i%5 == 0) ) //Print FizzBuzz if both cases true
		{
			std::cout << "FizzBuzz" << std::endl;
		}
		else //Otherwise just print the number
		{
			std::cout << i << std::endl; 
		}
	}
	return 0;
}
