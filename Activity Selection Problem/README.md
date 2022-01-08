# Question
Write a C program to solve activity selection problem using finishing time strategy. Collect the required input from the user and schedule maximum number of activities without clashing.

**Example 1 :** Consider the following 3 activities sorted by finish time.


start[] = {10, 12, 20};

finish[] = {20, 25, 30};

A person can perform at most two (k)activities: {0, 2} Note: [These are indexes in start[] ]

**Example 2 :** Consider the following 6 activities sorted by by finish time.

start[] = {1, 3, 0, 5, 8, 5};

finish[] = {2, 4, 6, 7, 9, 9};

A person can perform at most four(k) activities: {0, 1, 3, 4}

**Note:** Read number of activities given, how many activities (k) to be selected at most, followed by start and finish times in arrays from the user. Print the solution.

## Test cases
| Input                                | Result  |
|--------------------------------------|---------|
| 3<br>2<br>10 12 20<br>20 25 30       | 0 2     |
| 6<br>4<br>1 3 0 5 8 5<br>2 4 6 7 9 9 | 0 1 3 4 |

# Code
    #include <stdio.h>
    #include <stdlib.h> 

    void solve(){
        //selectActivities(int s[], int f[], int n)
        int* s;
        int* f;
        int n;
        //printf("\nInput number of activities: ");
        scanf("%d", &n);
        // printf("\nInput the maximum number of activities ")
        int m;
        scanf("%d", &m);
        s = (int*)malloc(sizeof(int)*n);
        f = (int*)malloc(sizeof(int)*n);
        int i, j;
        //printf("Input the start and end times of the activities,\nsorted by end time:");
        for(i = 0; i < n; i++){
            //printf("\nstart: ");
            scanf("%d", &s[i]);
        }
        for(i = 0; i < n; i++){
            //printf("end: ");
            scanf("%d", &f[i]);
        }

        //printf ("Following activities are selected: ");
    
        // The first activity always gets selected
        i = 0;
        printf("%d ", i);
        m--;
        // greedy approach
        for (j = 1; j < n && m>0; j++){
            if (s[j] >= f[i]){
                printf ("%d ", j);
                i = j;
                m--;
            }
        }
    }

    int main()
    {
        solve();
        return 0;
    }