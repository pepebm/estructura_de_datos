// Jose Manuel Beauregard Mendez A01021716
#include <iostream>
#include <fstream>



template <typename T>
void swap(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <typename T>
int quick_sort_lomuto(int start, int end, T names[])
{
	int pivot = end;
    int i = start; 
    
    for(int j = start; j < end; j++)
    {
        if (names[j] < names[pivot])
        {
            swap(&names[i], &names[j]);
            i++;
        }
    }
    swap(&names[i], &names[pivot]);
    return i;
}

template <typename T>
void quick_sort_recursion(int start, int end, T names[])
{
	if (start < end)
	{
		int pivot = quick_sort_lomuto(start, end, names);
		quick_sort_recursion(start, pivot - 1, names);
		quick_sort_recursion(pivot + 1, end, names);
	}
}

template <typename T>
void quick_sort(int size, T names[])
{
	quick_sort_recursion(0, size, names);
}

template <typename T>
void printArray(T names[], int size)
{
 	for(int i=0; i < size; i++)
 	{
 		std::cout<<names[i]<<std::endl;
 	}
}

int countline()
{
 	int i = 0;
	std::ifstream file;
	file.open("ASOIF_names.txt");
	if (file.fail()){
		std::cout<<"Error, could not load the file."<<std::endl;
		return 0;
	}
	char* n = new char[256];
	while(!file.eof())
	{
		file.getline(n, 256);
		i++;
	}
	delete [] n;
	file.close();
	return i;
}

template <typename T>
void makeArray(T names[])
{
	int i = 0;
	std::ifstream file;
	file.open("ASOIF_names.txt");
	if (file.fail()) return;
	char nn[256];
	while(!file.eof())
	{
		file.getline(nn, 256);
		T row(nn);
		names[i]=row;
		i++;
	}
}

template <typename T>
bool binarySearch(T names[], int start, int end, T goal)
{
	if(end < start){
		std::cout<<goal<<" was not found in the list. ";
		return false;
	}

    int a = (start + end) / 2;
    
    if(goal < names[a])
    	return binarySearch(names,start,a-1,goal);
  
    else if(goal > names[a])
    	return binarySearch(names,a+1,end,goal);
    	
    else {
    	std::cout<<goal<<" was found on index "<<a<<std::endl;
     	return true;
    }
}


int main()
{	
	int size = countline();
	if(size==0)return 0;
	std::string names[size];
	std::string goal;
	makeArray(names);
	quick_sort(size-1, names);
	int choice;
	while(true){
		std::cout<<"\nWelcome, please choose one of the following options."<<std::endl;
		std::cout<<"1. Search by full name."<<std::endl;
		std::cout<<"2. Print complete list."<<std::endl;
		std::cout<<"3. Exit Program"<<std::endl;
		std::cin>>choice;
		std::cin.ignore();
		switch(choice){
			case 1:
				std::cout<<"Enter the full name. ";
				std::getline(std::cin, goal);
				std::cout<<std::endl;
				if (binarySearch(names, 0, size, goal))
					std::cout<<"Thank you for using this program";
				else
					std::cout<"Try again.";
				break;
			case 2:
				printArray(names, size);
				break;
			case 3:
				return 0;
				break;
			default:
				std::cout<<"\nInvalid option."<<std::endl;
		}

	}
	return 0;
}