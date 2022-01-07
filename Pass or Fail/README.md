# Question
Write a C program to read the following details of a student such as student's name and marks in 5 courses from the user and print the total marks obtained with pass/fail information. If the average percentage of total secured is greater than or equal to 50, print ‘pass’ else print ‘fail’. 

## Test cases

| Input                 | Result   |
|-----------------------|----------|
| Latha 78 67 56 99 88  | 388 pass |
| Kala 34 44 45 67 45   | 235 fail |

# Code
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