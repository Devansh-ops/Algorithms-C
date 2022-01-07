#include <stdio.h>
#include <stdlib.h>

int main(){
    int k = 5;
    int *arr = (int*)malloc(sizeof(int)*k);
    
    char name[50];
    scanf("%s", name);

    int sum = 0;
    int i;

    for(i = 0; i < k; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%d ", sum);
    if ((float)sum / k >= 50){
        printf("pass");
    }
    else{
        printf("fail");
    }

    return 0;
}