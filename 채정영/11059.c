#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char num_str[1005];
// Brute Force O(N^2)

// from : from idx
// len : lengh of the substring
int sum_substr(int idx, int len){
  //if()

  int sum = 0;
  for(int i = idx ; i < idx + len ; i++){
    if(num_str[i] == 0){
      printf("overflow at i = %d\n", i);
      break;
    }
    sum += num_str[i] - '0';
  }

  //printf("sum : %d\n", sum);
  return sum;
}

int main(){
  
  scanf("%s", num_str);
  int n = strlen(num_str);
  
  // start idx
  int ans = 0;
  for(int i = 0 ; i < n; i++){
    int len = 1;
    int j =  i + len;
    while(j + len < n){
      
      j = i + len;

      int l = sum_substr(i, len);
      int r = sum_substr(j, len);

      if(l == r && len > ans){
        ans = len;
        //printf("bigger at %d, len = %d\n", i , len);
      }
      len++;

    }
  }

  printf("%d", ans*2);

  
  return 0;
}
