#include <stdio.h>
#include <stdlib.h>

int m(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

void printKnapsack(int** f, int weights[], int values[], int n, int W){
    int i;
    int res = f[n][W];
    int w = W;
    int* used = (int*)malloc(sizeof(int)*(n+1));
    for(i = 1; i <= n; i++){
        used[i] = 0;
    }
    for (i = n; (i > 0) && (res > 0) ; i--) {
        
        if (res == f[i-1][w])
            continue;       
        else {
 
            // This item is included.
            //printf("%d ", weights[i]);
            used[i] = 1;

            res = res - values[i];
            w = w - weights[i];

        }
    }

    for(i = 1; i <= n; i++){
        printf("%d ", used[i]);
    }
}

int knapsack(int** f, int weights[], int values[], int n, int w, int i, int j){
    int value = 0;
    if (f[i][j] < 0){
        if (j < weights[i]){
            value = knapsack(f, weights, values, n, w, i-1, j);
        }
        else {
            value = m(knapsack(f, weights, values, n, w, i-1, j), values[i]+knapsack(f, weights, values, n, w, i-1, j-weights[i]));
        }
        f[i][j] = value;
    }
    return f[i][j];
}

void solve(){
    // input

    int n;
    //printf("\nEnter number of items: ");
    scanf("%d", &n);

    int* weights = (int*)malloc(sizeof(int)* (n+1));
    int* values = (int*)malloc(sizeof(int)* (n+1));

    int i, j;
    //printf("\nEnter Weights: ");
    for(i = 1; i <= n; i++){
        scanf("%d", &weights[i]);
    }
    //printf("\nEnter Values: ");
    for(i = 1; i <= n; i++){
        scanf("%d", &values[i]);
        values[i] = n+1-values[i];
    }

    int w;
    //printf("\nEnter Knapsack capacity: ");
    scanf("%d", &w);

    // creating dp table
    int** f;
    f = (int**)malloc(sizeof(int*)*(n+1));
    for(i = 0; i < n+1; i++){
        f[i] = (int*)malloc(sizeof(int)*(w+1));
    }
    
    for(i = 0; i <= n; i++){
        for(j = 0; j <= w; j++){
            if (i == 0 || j == 0){
                f[i][j] = 0;
            }
            else{
                f[i][j] = -1;
            }
        }
    }

    // filling the table
    knapsack(f, weights, values, n, w, n, w);
    //printf("\nMaximum Value: %d\n", maxVal);
    printKnapsack(f, weights, values, n, w);
    /*
    printf("\nTable:\n");
    for(i = 0; i <= n; i++){
        for(j = 0; j <= w; j++){
            printf("%d ", f[i][j]);
        }
        printf("\n");
    }
    */

}

int main(){
    solve();
    return 0;
}
