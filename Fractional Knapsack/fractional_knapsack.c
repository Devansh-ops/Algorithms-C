#include <stdio.h>
#include <stdlib.h>

struct Item {
    int id;
    int weight;
    int value;
    float density;
};

void fractionalKnapsack(struct Item items[], int n, int W);

void solve() {
    int n;
    struct Item* items;
    int W;
    //printf("\nInput Weight limit of knapsack: ");
    scanf("%d", &W);
    //printf("\nInput number of items: ");
    scanf("%d", &n);
    items = (struct Item*)malloc(sizeof(struct Item)*n);
    //printf("\nInput item weight and value: ");
    int i, j;

    for(i=0;i<n;i++){
        items[i].id = i+1;
        //printf("\nweight = ");
        scanf("%d", &items[i].weight);
    }
    for(i=0;i<n;i++){
        //printf("value = ");
        scanf("%d", &items[i].value);
        items[i].density = (float)(items[i].value) / items[i].weight;
    }
    //temp item
    struct Item temp;
    //sort by density in descending order
    for(i = 1; i < n; i++) {
        for(j = 0; j < n - i; j++) {
            if(items[j+1].density > items[j].density) {
                temp = items[j+1];
                items[j+1] = items[j];
                items[j] = temp;
            }
        }
    }

    fractionalKnapsack(items, n, W);
}

void fractionalKnapsack(struct Item items[], int n, int W) {
    int i, wt;
    float value;

    float totalWeight = 0, totalBenefit = 0;

    for(i = 0; i < n; i++) {
        if(items[i].weight + totalWeight <= W) {

            totalWeight += items[i].weight;
            totalBenefit += items[i].value;

            //printf("Selected Item: %d\tWeight: %d\tValue: %d\tTotal Weight: %f\tTotal Benefit: %f\n", items[i].id, items[i].weight, items[i].value, totalWeight, totalBenefit);
            //printf("%d ", items[i].weight);
            printf("1.0 ");

        }
        else {
            wt = (W - totalWeight);
            value = wt * ((float)(items[i].value) / items[i].weight);

            totalWeight += wt;
            totalBenefit += value;

            //printf("Selected Item: %d\tWeight: %d\tValue: %f\n\nTotal Weight: %f\tTotal Benefit: %f\n", items[i].id, wt, value, totalWeight, totalBenefit);
            //printf("%d/%d", wt, items[i].weight);
            printf("%0.1f", (1.0*wt)/items[i].weight);

            break;
        }
    }
}

int main(){
    solve();
    return 0;
}