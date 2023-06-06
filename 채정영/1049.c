#include <stdio.h>

int N, M;
int nums_6[105];
int nums_1[105];

void swap_idx(int * nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

// selection sort
void selectionSort(int * nums){
    for(int i = 0 ; i < M-1; i++){
        for(int j = i + 1 ; j < M ; j++){
            if(nums[i] > nums[j]){
                swap_idx(nums, i, j);
            }
        }
    }
}
// Greedy Knapsack PRobelm
int main(){

    scanf("%d %d", &N, &M);

    for(int i = 0 ; i < M; i++)
    {
        scanf("%d %d", &nums_6[i], &nums_1[i]);
    }
    selectionSort(nums_6);
    selectionSort(nums_1);

    //printf(">%d %d", nums_6[0], nums_1[0]);
    int min_6 = nums_6[0];
    int min_1 = nums_1[0];
    int cost = 0 ;
    
    if(min_6 > min_1 * 6){
        cost += min_1 * N;
        
    } else{
        cost += (N / 6) * min_6;
        if((N%6) * min_1 < min_6)
            cost += min_1 * (N%6);
        else
            cost += min_6;
    }
    printf("%d", cost);
    return 0;
}