#include <stdio.h>
#include <math.h>

int main()
{
    int data[] = {3, 6, 2};
    //int data[] = {3, 6, 2, 7, 8, 4, 1, 0};
    
    int size = sizeof data / sizeof data[0];
    
    printf("Size of the original array: %d\n", size);
    
    int counter = 0;
    int j;
    
    for(counter=0; counter<pow(2, size); counter++)
    {
        printf("\nNew array\n");
        for (j=0; j<size; j++)
        {
            if (counter & (int)pow(2, j))
            {
                printf("Insert item at index %d\n", j);
            }
        }
    }
    
    return 0;
}