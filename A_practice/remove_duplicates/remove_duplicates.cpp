//Author: Chris Nogales
//Date:   1/29/2016
//Task: 

// Return distinct values from a list 
// including duplicates (i.e. "1 3 5 3 7 3 1 1 5" -> "1 3 5 7")

#include <iostream>
#include <list> 
#include <algorithm>    // To use std::find

// std::vector   -> dynamically allocated array
// std::list     -> double linked sequences

/* Both hold array addresses.*/
/* A list does not provide random access */
/* A list is not synchronized, a vector is. Sync means you can access random
addresses and make changes more easily*/
/* Lists are faster than vectors and are ideal for insertion 
and deletion in the beginning, middle, and end of the element lists.*/
/* Lists have no default size while a vector has a default size of 10*/
/* A list is not thread safe, a vector is thread safe*/


// argc (argument count)  = num_args
// argv (argument vector) = arg_strings

typedef std::list<int> IntegerList;

//Function that check if a value is not there. 
//Assuming it's all integers
bool checkExistence(int my_variable, IntegerList my_list)
{
    bool found = (std::find(my_list.begin(), my_list.end(), my_variable) != my_list.end());
    return found;
}

int main(int num_args, char *arg_strings[])
{
	IntegerList my_numbers;
	IntegerList my_distinct_numbers;
	int my_int;
	int my_set_size = 10;

    // Populate list of integers
	std::cout << " Enter some integers (0 to 10):\n" << std::endl;
	do
	{
		std::cin >> my_int;
		my_numbers.push_back(my_int);		
	}
	while(my_numbers.size() != my_set_size);

  	std::cout << "mylist stores " << my_numbers.size() << " numbers.\n";

	// Constant iterator to print out contents of list
    for (IntegerList::const_iterator ci = my_numbers.begin(); 
    	ci != my_numbers.end(); ++ci)
    {
    	std::cout << " " << *ci << " ";
    }
	std::cout << std::endl;
	int cur_int = 0;

	// Return distinct values from a list of numbers
    for (IntegerList::const_iterator ci = my_numbers.begin(); 
    	ci != my_numbers.end(); ++ci)
    {	
    	cur_int  = *ci;
    	if(my_distinct_numbers.size() == 0)
    	{
    		my_distinct_numbers.push_back(cur_int);
    	}
        else
        {   
            //If it does not exist in the new list, then add the number to it
            bool exists = checkExistence(*ci, my_distinct_numbers);
            if(exists == false)
            {
                my_distinct_numbers.push_back (*ci);
            }
       
        }
    }
    //Output result
    std::cout << "Result " << std::endl;
    for (IntegerList::const_iterator ii = my_distinct_numbers.begin(); 
    	ii != my_distinct_numbers.end(); ++ii)
    {
	    	//If not repeated
	    	std::cout << " " << *ii << " ";
	}
// std::list<int>::const_iterator iterator;
// for (iterator = intList.begin(); iterator != intList.end(); ++iterator) {
//     std::cout << *iterator;
// }

	// std::cout << "Hello World" << std::endl;
	return 0;
}