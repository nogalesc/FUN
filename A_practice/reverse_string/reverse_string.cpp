//Author: Chris Nogales
//Date:   1/29/2016
//Task: Reverse a string
#include <iostream>

int main()
{
	//Print out the string and its size. 
	std::string my_phrase = "Hi Chris";
	int str_ll = my_phrase.size();
	std::cout << my_phrase << " is " << str_ll 
	          << " characters long" << std::endl;
	//Iterate through the phrase.
	//length() or size() function is important here because C++ strings are not 
        //guaranteed to be null-terminated (by a '\0').
	for(int ii = 0; ii<str_ll; ++ii)
	{
		std::cout << my_phrase[ii] << std::endl;
	}
	//Reverse the string
	for(int ii = str_ll; ii >= 0; --ii)
	{
		std::cout << my_phrase[ii] << std::endl;
	}
	return 0;
}
