#include <stdio.h>

int N;
int dp[400005];
int nums[200005];

int main(){

    scanf("%d", &N);
    for(int i = 0 ; i < N; i++){
        scanf("%d", &nums[i]);
    }

    dp[N-1] = 1;
    for(int i = N-2; i >= 0; i--){
        if(nums[i]){
            dp[i] = dp[i + 1 + nums[i]] + 1;
        }else {
            dp[i] = dp[i+1] + 1;
        }
    }
    
    for(int i = 0 ; i < N; i++){
        printf("%d ", dp[i]);
    }


    return 0;

}