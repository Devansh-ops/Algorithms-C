# Question
Write a C program for the following problem. There are n items in the suitcase of a traveler. On boarding the flight, the airline company told him that his suitcase is over weight than the allowed capacity W and asked him to deload some items and not to carry more than W. He knows weight of each item. Devise an algorithm to find out which items to be discarded so that he can carry max. weight W. (assume the weight of the suitcase is ignored). Note: The objective here is that he must carry maximum items. For example

Weights of items : 5 3 2 1

W=6

Output: 0 1 1 1 

Weights of items : 20 12 10 7 5

W=27

Output: 0 0 1 1 1

Note: Read number of items, knapsack capacity and weights of items from the user. Print the solution.

## Test cases
| Input             | Result    |
|-------------------|-----------|
| 4<br>6<br>5 3 2 1       | 0 1 1 1   |
| 5<br>27<br>20 12 10 7 5 | 0 0 1 1 1 |

# Code
    #include <stdio.h>
    #include <stdlib.h>

    void solve(){
        int size;
        int *arr;
        int w;
        //input

        //printf("\nEnter the number of items: ");
        scanf("%d", &size);

        //printf("\nEnter the weight limit: ");
        scanf("%d", &w);

        arr = (int*)malloc(sizeof(int)*size);

        //printf("\nEnter the weights: ");
        int i;
        for(i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }
        
        //solving
        //int i;
        int max = 0;
        int* used;
        used = (int*)malloc(sizeof(int)*size);
        for(i = 0; i < size; i++){
            used[i] = 0;
        }

        for(i = size-1; i>=0; i--){
            if (max + arr[i] <= w){
                used[i] = 1;
                max += arr[i];
            }
        }

        for(i = 0; i < size; i++){
            printf("%d ", used[i]);
        }
    }


    int main(){
        solve();
        return 0;
    }
