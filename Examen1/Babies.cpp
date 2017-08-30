/*
   First Partial Evaluation
   Data Structures TC1018.1
   January 2016

    Name: Jose Manuel Beauregard Mendez
    ID Number: A01021716
    Compiler: Windows Console

    Complete the program accroding to the requirements
*/

#include <iostream>
#include "Array.h"
#include "NewBorn.h"

///// EXAM QUESTION /////
// Recursive method to sum all weights



int sumrec(Array<NewBorn> weights)
{
    int i = 6;
    int sum = 0;
    if(i != 0)
    {
        sum += weights[i-1].get_weight();
        i--;
        return sumrec(weights);
    }
    else 
        return sum;
    
}





int main()
{
    Array<NewBorn> babies(6);
    
    babies[0] = NewBorn("Laura", 5.8, 2.47, 47.3);
    babies[1] = NewBorn("Martin", 7.9, 3.18, 52.1);
    babies[2] = NewBorn("Alan", 8.9, 3.43, 50.2);
    babies[3] = NewBorn("Sara", 7.9, 2.98, 49.2);
    babies[4] = NewBorn("Sofia", 5.8, 2.47, 49.6);
    babies[5] = NewBorn("David", 6.8, 3.02, 51.3);

    std::cout << "Unordered:" << std::endl;
    babies.print_data();

    babies.sort_decreasing();
    std::cout << "Ordered:" << std::endl;
    babies.print_data();

    ///// EXAM QUESTION /////
    std::cout << "Sum of all weights: " << sumrec(babies); <<  " kg." << std::endl;

    return 0;
}

