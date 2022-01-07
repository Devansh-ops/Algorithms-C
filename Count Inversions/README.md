# Question
Write a C program for the following problem. Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

**Example:** Input: arr[] = {8, 4, 2, 1}

Output: 6. The six inversions: (8,4), (4,2), (8,2), (8,1), (4,1), (2,1).

Input: arr[] = {3, 1, 2}

Output: 2. The two inversions: (3,1), (3,2).

**Note:** Read how many numbers and numbers in the array from the user. Print the total count of inversions.

## Test cases
| Input      | Result |
|------------|--------|
| 4<br>8 4 2 1  | 6      |
| 3<br>3 1 2    | 2      |

# Code
    #include <stdio.h>
    #include <stdlib.h>

    void solve(){
        unsigned int size;
        int *arr;
        int i, j;
        // Input
        //printf("Enter size of array: ");
        scanf("%u", &size);
        arr = (int *)malloc(sizeof(int)*size);
        
        //printf("\nInput values: ");
        for(i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }

        //solving
        unsigned int inversions = 0;

        for (i = 0; i < size-1; i++){
            for(j = i+1; j < size; j++){
                if (arr[i] > arr[j]){
                    inversions++;
                }
            }
        }

        //printf("\nThe inversion count is %d\n", inversions);
        printf("%d", inversions);
    }

    int main(){
        solve();
        return 0;
    }