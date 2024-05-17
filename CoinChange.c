#include<stdio.h>
void printArray(int n[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}

int min(int a, int b) {
    return a < b ? a : b;
}

int findDenominations(int size, int amount, int ccp[size][amount + 1], int coins[]) {
    int i = size - 1;
    int j = amount;
    int k = 0;
    int ans[10];

    while (i >= 0 && j > 0) { 
        if (ccp[i][j] != ccp[i - 1][j]) {
            ans[k] = coins[i];
            j = j - coins[i];
            k++;
        } 
		else{
            i--;
        }
    }
    printf("The denominations used are: ");
    printArray(ans, k);
}

void coinChange(int coins[], int amount, int size) {
    int ccp[size][amount + 1];

    for (int i = 0; i < size; i++) {
        ccp[i][0] = 0;
    }

    for (int j = 1; j <= amount; j++) {
        ccp[0][j] = j / coins[0];
    }

    for (int i = 1; i < size; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i] <= j) {
                ccp[i][j] = min(1 + ccp[i][j - coins[i]], ccp[i - 1][j]);
            } else {
                ccp[i][j] = ccp[i - 1][j];
            }
        }
    }
	printf("The minimum number of coins required is: %d\n",ccp[size-1][amount+1]);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= amount; j++) {
            printf("%d ", ccp[i][j]);
        }
        printf("\n");
    }
    findDenominations(size, amount, ccp, coins);
}

int main() {
    int coins[] = {1, 2, 5};
    int size = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;
    coinChange(coins, amount, size);
    return 0;
}

