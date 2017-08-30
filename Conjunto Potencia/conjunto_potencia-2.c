#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //int data[] = {3, 6, 2};
    int data[] = {3, 6, 2, 7, 8, 4, 1, 0};
    // Compute the size of the array
    int size = sizeof data / sizeof data[0];
    
    int ** power_set;
    int * subset_sizes;
    
    printf("Size of the original array: %d\n", size);
    
    int counter = 0;
    int sub_counter = 0;
    int j;
    
    // Allocate memory for the whole set
    power_set = malloc(sizeof(int*) * pow(2, size));
    subset_sizes = malloc(sizeof(int) * pow(2, size));
    
    for(counter=0; counter<pow(2, size); counter++)
    {
        printf("\nNew array\n");
        subset_sizes[counter] = 0;
        // First pass to determine the amount of memory necessary
        for (j=0; j<size; j++)
        {
            if (counter & (int)pow(2, j))
            {
                printf("Insert item at index %d: %d\n", j, data[j]);
                subset_sizes[counter]++;
            }
        }
        power_set[counter] = malloc(sizeof(int) * subset_sizes[counter]);
        sub_counter = 0;
        // Second pass to fill in the dynamically allocated arrays
        for (j=0; j<size; j++)
        {
            if (counter & (int)pow(2, j))
            {
                power_set[counter][sub_counter++] = data[j];
            }
        }
    }
    
    // Print the power_set
    printf("\nThis is the result:\n {\n");
    for(counter=0; counter<pow(2, size); counter++)
    {
        printf("  [");
        for (j=0; j<subset_sizes[counter]; j++)
        {
            printf("%d, ", power_set[counter][j]);
        }
        printf("]\n");
    }
    printf(" }\n");
    
    // Free all subsets
    for(counter=0; counter<pow(2, size); counter++)
    {
        free(power_set[counter]);
    }
    free(power_set);
    free(subset_sizes);
    
    return 0;
}