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


template <class T>
class Array {
    private:
        T * data;
        int size;
    public:
        // Class constructor
        Array(int _size);
        // Destructor
        ~Array();
        // Helper methods
        void swap(T * item_1, T * item_2);
        void print_data();
        // Operator overloads
              T& operator[](std::size_t idx)       { return data[idx]; };
        const T& operator[](std::size_t idx) const { return data[idx]; };

        //Sorting method
        

        ///// EVALUATION QUESTION /////
        void sort_decreasing();

        };

/*
Constructor
It creates the array of integers
*/
template <class T>
Array<T>::Array(int _size)
{
    // Create the array of type T
    size = _size;
    data = new T[size];
}

/*
Destructor
This one frees the memory used for the array
*/
template <class T>
Array<T>::~Array()
{
    delete [] data;
}


template <class T>
void Array::sort_decreasing()
{
    int smallest_index;
    for (int i=0; i<size; i++)
    {
        smallest_index = i;
        for (int j=i+1; j<size; j++)
        {
            if (data[j] > data[smallest_index])
                smallest_index = j;
        }
        swap(&data[i], &data[smallest_index]);
    }
}



/*
   Show the contents of the array
*/
template <class T>
void Array<T>::print_data()
{
    for(int i=0; i<size; i++)
    {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;
}

/*
   Exchange the contents of the array at two different indices
*/
template <class T>
void Array<T>::swap(T * item_1, T * item_2)
{
    T tmp;
    tmp = *item_1;
    *item_1 = *item_2;
    *item_2 = tmp;
}
