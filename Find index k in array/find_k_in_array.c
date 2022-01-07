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