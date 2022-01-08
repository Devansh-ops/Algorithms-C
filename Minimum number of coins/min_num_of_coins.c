#include <stdio.h>
#include <stdlib.h>

void sortDesc(int arr[], int n){
    int i, j, t;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if (arr[i] < arr[j]){
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int coinsUsed(int m, int d[], int n, int used[]){
    if (m <= 0){
        return 0;
    }
    int i;
    for (i = 0; i < n; i++){
        if (m >= d[i]){
            used[i]++;
            return 1 + coinsUsed(m-d[i], d, n, used);
        }
    }
    return -1;
}


void solve(){
    // input
    int m;
    int n;
    //printf("\nEnter the number of denomination: ");
    scanf("%d", &n);
    int* d = (int*)malloc(sizeof(int) * n);
    int* used = (int*)malloc(sizeof(int) * n);
    int i;
    //printf("\nEnter the denominations: ");
    for(i = 0; i < n; i++){
        scanf("%d", &d[i]);
        used[i] = 0;
    }

    //printf("Enter the amount M: ");
    scanf("%d", &m);

    // sort the denominations in descending order
    sortDesc(d, n);

    // solving using recursive greedy algo
    int c = coinsUsed(m, d, n, used);

    //printf("\nTotal coins = %d (", c);
    printf("%d\n", c);

    int prev = -1;
    for(i = 0; i < n-1; i++){
        while(used[i] > 0){
            if (prev == -1){
                prev = d[i];
                used[i]--;
            }
            else{
                printf("%d+", prev);
                prev = d[i];
                used[i]--;
            }
        }
    }
    if (prev != -1){
        printf("%d", prev);
    }
    //printf(")");
}

int main(){
    solve();
    return 0;
}