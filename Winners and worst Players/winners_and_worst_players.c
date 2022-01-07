#include <stdio.h>
#include <stdlib.h>

void solve(){
    unsigned int size;
    int *arr;
    
    // Input
    //printf("Enter number of players: ");
    scanf("%u", &size);
    arr = (int *)malloc(sizeof(int)*size);
    //printf("\nEnter scores: ");
    int i;
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    //solving

    int best, secBest, worst, secWorst;

    best = secBest = worst = secWorst = 0;

    for(i = 0; i < size; i++){
        //printf("\narr[i]=%d\n",arr[i]);
        if (arr[i] >= arr[secBest] || arr[secBest] == arr[best]){
            if (arr[i] > arr[best]){
                secBest = best;
                best = i;
            }
            else{
                secBest = i;
            }
        }

        if (arr[i] <= arr[secWorst] || arr[secWorst] == arr[worst]){
            if (arr[i] < arr[worst]){
                secWorst = worst;
                worst = i;
            }
            else{
                secWorst = i;
            }
        }
        //printf("Winner %d\nNext winner %d\nWorst player %d\nNext worst player %d", best+1, secBest+1, worst+1, secWorst+1);
        //printf("\n\n");
    }

    printf("Winner %d\nNext winner %d\nWorst player %d\nNext worst player %d", best+1, secBest+1, worst+1, secWorst+1);
    
}

int main(){
    solve();
    return 0;
}