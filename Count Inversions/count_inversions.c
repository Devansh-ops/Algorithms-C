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