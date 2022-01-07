#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long fact(int n){
    int i;
    long long ans = 1;
    for(i = n; i >= 1; i--){
        ans *= i;
    }

    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    long long f = fact(n);
    printf("%lld", f);
    return 0;
}