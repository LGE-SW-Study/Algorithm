#include <stdio.h>
#define REM 1000000007
#define ull unsigned long long 

int N;
ull nums[500005];
ull presum[500005];


int main(){
  scanf("%d", &N);

  for(int i = 0; i < N ; i++){
    scanf("%lld", &nums[i]);
  }
    // skip presum[0]

  unsigned int prev = 0 ;
  for(int i = N-1; i > 0 ; i--){
    presum[i] = (prev + nums[i]) % REM;
    prev = presum[i];
  }

  unsigned long long  ans = 0; 
  for(int i = 0; i < N-1 ; i++){
    ans = (ans + (presum[i+1] * nums[i]) % REM ) % REM;
  }

  printf("%llu", ans);

  return 0;
}
