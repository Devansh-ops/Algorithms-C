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