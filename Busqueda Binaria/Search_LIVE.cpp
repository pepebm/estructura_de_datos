/*
Implementation of search algorithms on arrays
Gilberto Echeverria
*/

#include <iostream>
#include <cstdlib>      // Required to use the random functions
#include <ctime>        // Required to make use of time functions

#define MAX 1000
#define STEP 5

class Array {
    private:
        int * data;
        int size;
    public:
        // Class constructor
        Array(int _size);
        // Destructor
        ~Array();
        void fill_random();
        void fill_ordered();
        void print_data();
        // Search methods
        bool linear_search(int item);
        bool binary_search_iterative(int item, int start, int end);
        bool binary_search_recursive(int item, int start, int end);
        // Sort methods
        void bubble_sort();
        void selection_sort();
        void insertion_sort();
        // Helper methods
        int get_last() { return size-1; }
        void swap(int * item_1, int * item_2);
};

/*
Constructor
It creates the array of integers
*/
Array::Array(int _size)
{
    // Create the array of integers
    size = _size;
    data = new int[size];
    // Fill the array with data
    fill_random();
}

/*
Destructor
This one frees the memory used for the array
*/
Array::~Array()
{
    delete [] data;
}

void Array::fill_random()
{
    for(int i=0; i<size; i++)
    {
        data[i] = rand() % MAX + 1;
    }
}

void Array::fill_ordered()
{
    int previous = 0;
    
    for(int i=0; i<size; i++)
    {
        // Skip a few numbers after every element stored in the array
        data[i] = previous + (rand() % STEP + 1);
        previous = data[i];
    }
}

void Array::print_data()
{
    for(int i=0; i<size; i++)
    {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;
}


bool Array::linear_search(int item)
{
    for(int i=0; i<size; i++)
    {
        if (data[i] == item)
            return true;
    }
    return false;
}

bool Array::binary_search_iterative(int item, int start, int end)
{
    int middle;
    
    while (start < end)
    {
        middle = (start + end) / 2;
        if (item < data[middle])
        {
            end = middle - 1;
        }
        else if (item > data[middle])
        {
            start = middle + 1;
        }
        else
        {
            return true;
        }
    }
    return false;    
}

bool Array::binary_search_recursive(int item, int start, int end)
{
    if (end < start)
        return false;
        
    int middle = (start + end) / 2;
    
    if (item < data[middle])
        return binary_search_recursive(item, start, middle-1);
    else if (item > data[middle])
        return binary_search_recursive(item, middle+1, end);
    else
        return true;
}



int main()
{
    // Initialize the random number seed
    srand(time(NULL));
    
    Array array_one(20);
    Array * array_two = new Array(30);
    int search;
    bool result;
    
    std::cout << "Array one:"  << std::endl;
    array_one.print_data();
    std::cout << "Array two:"  << std::endl;
    array_two->print_data();
    
    // DO SOME TESTS OF LINEAR SEARCHING HERE
    std::cout << "Search for which number: ";
    std::cin >> search;
    std::cout << "USING LINEAR SEARCH:" << std::endl;
    result = array_one.linear_search(search);
    std::cout << (result ? "Found" : "NOT found") << " in Array One" << std::endl;
    result = array_two->linear_search(search);
    std::cout << (result ? "Found" : "NOT found") << " in Array Two" << std::endl;
    
    array_one.fill_ordered();
    std::cout << "Array one:"  << std::endl;
    array_one.print_data();
    array_two->fill_ordered();
    std::cout << "Array two:"  << std::endl;
    array_two->print_data();
    
    // DO SOME TESTS OF LINEAR SEARCHING HERE
    std::cout << "Search for which number: ";
    std::cin >> search;
    std::cout << "USING ITERATIVE BINARY SEARCH:" << std::endl;
    result = array_one.binary_search_iterative(search, 0, array_one.get_last());
    std::cout << (result ? "Found" : "NOT found") << " in Array One" << std::endl;
    result = array_two->binary_search_iterative(search, 0, array_two->get_last());
    std::cout << (result ? "Found" : "NOT found") << " in Array Two" << std::endl;
    std::cout << "USING RECURSIVE BINARY SEARCH:" << std::endl;
    result = array_one.binary_search_recursive(search, 0, array_one.get_last());
    std::cout << (result ? "Found" : "NOT found") << " in Array One" << std::endl;
    result = array_two->binary_search_recursive(search, 0, array_two->get_last());
    std::cout << (result ? "Found" : "NOT found") << " in Array Two" << std::endl;
    
    delete array_two;
    
    return 0;
}