#include <stdio.h>
#include <stdlib.h>

#define ll long long

int N;
ll nums[100005];
ll diffs[100005];

// find 최대 공약수

ll gcd(ll a, ll b)
{
    if(a % b == 0){
        return b;
    } else{
        return gcd(b%a, a);
    }
}

int cmp(const void *first, const void * second){

    ll a = *(ll*) first;
    ll b = *(ll*) first;

    if(a > b){
        return 1;
    } else if( a < b) {
        return -1;
    } else {
        return 0;
    }
}

int main(){
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++){
        scanf("%lld", &nums[i]);
    }
    qsort(nums, N, sizeof(ll), cmp);
    for(int i = 1; i < N; i++){
        diffs[i-1] = nums[i] - nums[i-1];
    }
    ll smallest = gcd(diffs[0], diffs[1]);
    for(int i = 2; i < N-1; i++){
        smallest = gcd(smallest, diffs[i]);
    }

    ll ans = 0 ;


    for(int i = 0 ; i < N-1; i++){
        ans += (diffs[i] / smallest) - 1;
        //printf(">%lld\n", diffs[i]);
    }
    printf("%lld", ans);


    return 0;
}