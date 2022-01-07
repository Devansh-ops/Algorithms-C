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