# Question
Write a C program for the following problem. Some players play a game and their scores (positive integers) are recorded in the form of an array. A player who scores more is the winner. Design an algorithm to find out the winner, next winner, worst player, next worst player by scanning the score sheet only once.

**Example:** Consider the following 5 players whose score sheet is given by 7,3,5,8,4. Winner: Player 4. Next winner: Player 1. Worst player: Player 2, Next worst player: Player 5.

**Note :** Read how many players and scores. Print the winner, next winner, worst player and next worst player.

## Test cases
| Input       | Result                                                    |
|-------------|-----------------------------------------------------------|
| 5<br>7 3 5 8 4 | Winner 4<br>Next winner 1<br>Worst player 2<br>Next worst player 5 |

# Code
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