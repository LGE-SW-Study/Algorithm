#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
int numUniqbooks = 0;
char books[1005][55];
char uniqbooks[1005][55];
char bestsellers[1005][55];
int bought[1005];
int maxBought = 1;


// returns 1 if a comes earlier in dictionary 
// else return 0
int isEarlyInDict(char * a, char * b){
  int alen = strlen(a);
  int blen = strlen(b);

  int i = 0 ;
  while(i < alen && i < blen){
    if(b[i] > a[i] ){ // b comes latter
      return 1;
    } else if (b[i] < a[i]){
      return 0;
    } else {
      i++;
    }
  }

  if(alen < blen){
    return 1;
  } else{
    return 0;
  }

}

// hash is probably most easy way.. but i dont know how to implement that in c
int main()
{
  scanf("%d ", &N);

  // 5000 ^ 2 
  for(int i = 0; i < N ; i++){
    
    char tmp[55];
    scanf("%s", tmp);

    char isUniq = 1;
    for(int j = 0; j < numUniqbooks; j++){
      if(strcmp(tmp, uniqbooks[j]) == 0){
        isUniq = 0;
        bought[j]++;
        if(bought[j] > maxBought){
          maxBought = bought[j];
        }
        break;
      }
    }

    if(isUniq)
    {
      bought[numUniqbooks]++;
      strcpy(uniqbooks[numUniqbooks], tmp);
      numUniqbooks++;
    }
  }

  int j = 0;
  char firstMax[55];

  firstMax[0] = 'z' + 1 ;
  firstMax[1] = 0;

  for(int i = 0 ; i < numUniqbooks; i++){
    if(bought[i] == maxBought){
      if(isEarlyInDict(uniqbooks[i], firstMax)){
        strcpy(firstMax, uniqbooks[i]);
        //printf("%s", firstMax);
      }
    }
  }
  printf("%s", firstMax);

  return 0;
}
