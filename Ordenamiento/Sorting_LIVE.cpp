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
        
        void merge_sort_recursion(int * temp, int start, int end);
        void merge_sort_merge(int * temp, int start, int middle, int end);
        void merge_sort_copy(int * temp, int start, int end);
        void quick_sort_recursion(int start, int end);
        int quick_sort_lomuto_partition(int start, int end);
        int quick_sort_hoare_partition(int start, int end);
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
        void merge_sort();
        void quick_sort();
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


void Array::bubble_sort()
{
    bool change;
    for(int i=0; i<size; i++)
    {
        change = false;
        for(int j=1; j<size-i; j++) 
        {
            if (data[j-1] > data[j])
            {
                swap(&data[j-1], &data[j]);
                change = true;
            }
        }
        // Optimisation to exit if the array is already ordered
        if (!change)
            break;
    }
}

void Array::selection_sort()
{
    int smallest_index;
    for (int i=0; i<size; i++)
    {
        smallest_index = i;
        for (int j=i+1; j<size; j++)
        {
            if (data[j] < data[smallest_index])
                smallest_index = j;
        }
        swap(&data[i], &data[smallest_index]);
    }
}

void Array::insertion_sort()
{
    int tmp;
    int j;
    for (int i=1; i<size; i++)
    {
        tmp = data[i];
        for (j=i; j>0; j--)
        {
            if (tmp < data[j-1])
                data[j] = data[j-1];
            else
                break;
        }
        data[j] = tmp;
    }
}


void Array::merge_sort()
{
    int * temp = new int[size];
    merge_sort_recursion(temp, 0, size);
    delete [] temp;
}

void Array::merge_sort_recursion(int * temp, int start, int end)
{
    if (end - start > 1)
    {
        int middle = (start + end) / 2;
        merge_sort_recursion(temp, start, middle);
        merge_sort_recursion(temp, middle, end);
        merge_sort_merge(temp, start, middle, end); 
    }
}

void Array::merge_sort_merge(int * temp, int start, int middle, int end)
{
    int i = start;
    int j = middle;
    
    for (int temp_index=start; temp_index < end; temp_index++)
    {
        if (i < middle && (j >= end || data[i] < data[j]))
        {
            temp[temp_index] = data[i++];
        }
        else
        {
            temp[temp_index] = data[j++];
        }
    }
    
    for (int k=start; k<end; k++)
    {
        data[k] = temp[k];
    }
}

void Array::quick_sort()
{
    quick_sort_recursion(0, size-1);
}

void Array::quick_sort_recursion(int start, int end)
{
    if (start < end)
    {
        //int pivot = quick_sort_lomuto_partition(start, end);
        int pivot = quick_sort_hoare_partition(start, end);
        quick_sort_recursion(start, pivot-1);
        quick_sort_recursion(pivot+1, end);
    }
}

int Array::quick_sort_lomuto_partition(int start, int end)
{
    int pivot = end;
    int i = start; 
    
    for(int j=start; j<end; j++)
    {
        if (data[j] < data[pivot])
        {
            swap(&data[i], &data[j]);
            i++;
        }
    }
    swap(&data[i], &data[pivot]);
    return i;
}

int Array::quick_sort_hoare_partition(int start, int end)
{
    int pivot = start;
    //int i = start - 1;
    int i = start;
    int j = end + 1;
    
    while(true)
    {
        do
        {
            j--;
        } while (data[j] > data[pivot]);
        do
        {
            i++;
        } while (data[i] < data[pivot] && i <= end);
        if (i < j)
        {
            swap (&data[i], &data[j]);
        }
        else
        {
            swap (&data[pivot], &data[j]);
            return j;
        }
    }
}

void Array::swap(int * item_1, int * item_2)
{
    int tmp;
    tmp = *item_1;
    *item_1 = *item_2;
    *item_2 = tmp;
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
    
    //array_one.fill_ordered();
    //array_one.bubble_sort();
    //array_one.selection_sort();
    //array_one.insertion_sort();
    //array_one.merge_sort();
    array_one.quick_sort();
    std::cout << "Array one:"  << std::endl;
    array_one.print_data();
    //array_two->fill_ordered();
    //array_two->bubble_sort();
    //array_two->selection_sort();
    //array_two->insertion_sort();
    //array_two->merge_sort();
    array_two->quick_sort();
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