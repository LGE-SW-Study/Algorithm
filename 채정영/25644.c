#include <stdio.h>

int main(){
    int N;
    int nums[200000];
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d", &nums[i]);
    }

    int lowest = nums[0];
    int highest = nums[0];
    int biggest = 0;
    for(int i = 1; i < N; i++){
        if(lowest > nums[i] || highest < nums[i]){
            if(lowest > nums[i]){
                lowest = nums[i];
                highest = nums[i];
            }
            if(highest < nums[i]){
                highest = nums[i];
            }
            if(biggest < highest - lowest){
                biggest = highest - lowest;
            }
        } 
        //printf("%d %d", highest, lowest);    
    }
    printf("%d", biggest);

    return 0;
}