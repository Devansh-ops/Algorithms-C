#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long recFib(int n){
    int f0 = 0;
    int f1 = 1;
    if (n <= 0){
        return f0;   
    }
    if (n == 1){
        return f1;
    }

    return recFib(n-1)+recFib(n-2);
}

int main(){
    int n;
    scanf("%d", &n);
    long long f = recFib(n-1);
    printf("%lld", f);
    return 0;
}