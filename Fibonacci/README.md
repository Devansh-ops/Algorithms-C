# Question
In 1202, Fibonacci introduced the sequence to Western European mathematics. Consider the
Fibonacci sequence.
where, F0 = 0, F1 = 1.
0, 1, 1, 2, 3, 5, 8, 13, 21, . . .
1. Write a procedure to find Fn using recursive definition of the Fibonacci numbers. Discuss
the time complexity of the algorithm.
2. Write a iterative procedure to find Fn. Discuss the time complexity of the algorithm.
3. Design an efficient procedure to find Fn using Binet’s formula. Discuss the time complexity
and implementation issue if any.

# Code
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

    long long iterFib(int n){
        int f0 = 0;
        int f1 = 1;
        int k;
        if (n <= 0){
            return f0;   
        }
        if (n == 1){
            return f1;
        }

        int i;

        for(i = 2; i <= n; i++){
            k = f1+f0;
            f0 = f1;
            f1 = k;
        }

        return k;
        
    }

    long long binetFib(int n){
        long long a = (pow((1+sqrt(5))/2, n) - pow((1-sqrt(5))/2, n)) / sqrt(5);
        return a;
    }

    int main(){
        int ch, n;
        while(1){
            printf("\nProgram to Print the nth Fibonacci number");
            printf("\n\tMENU\n");
            printf("\n1. Recursive");
            printf("\n2. Iterative");
            printf("\n3. Binet's formula");
            printf("\n4. Exit");
            printf("\n>>");
            scanf("%d", &ch);
            
            if (ch == 4){
                exit(0);
            }

            printf("\nInput n: ");
            scanf("%d", &n);
            printf("\nAns: ");

            switch (ch)
            {
            case 1:
                printf("%lld\n", recFib(n));
                break;
            case 2:
                printf("%lld\n", iterFib(n));
                break;
            case 3:
                printf("%lld\n", binetFib(n));
                break;
            default:
                printf("\nWrong Choice, try again!\n");
                break;
            }
        }
        return 0;
    }