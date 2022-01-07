# Question
Write a C program for the following problem. Suppose an array A has n distinct integers. Write an algorithm to find an index k (k need not exist/ need not be unique) such that A[0]....................................... A[k] is an increasing sequence and A[k+1]....... A[n-1] is a decreasing sequence.

**Examples:**

A = {5,4, 3, 2, 1} Here k=0, A[0] is an increasing sequence and A[1,4] = {4,3,2,1} is decreasing.

A = {2,4,6,5,2,1} then k can be 1 or 2. 

A = {1,3,5,4,6,2} k does not exist

**Note:** Read how many numbers and numbers in the array. Print k value if found or else print 'k does not exist'

## Test cases
| Input         | Result           |
|---------------|------------------|
| 5<br>5 4 3 2 1   | 0                |
| 6<br>1 3 5 4 6 2 | k does not exist |

# Code
    #include <stdio.h>
    #include <stdlib.h>

    void solve(){
        unsigned int size;
        int *arr;

        //Input
        //printf("\nEnter the size of array: ");
        scanf("%u", &size);
        arr = (int *)malloc(sizeof(int)*size);

        //printf("\nInput values: ");
        int i;
        for(i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }

        //Solving

        int k = 0;

        while(k < size && arr[k+1] > arr[k]){
            k++;
        }

        /* //redundant 
        if (k == size-1){
            printf("\nk=%d\n", k);
            return;
        }
        */
    
        for(i = k+1; i < size; i++){
            if (arr[i]>arr[i-1]){
                printf("k does not exist");
                return;
            }
        }

        printf("%d", k);
    }