#include <stdio.h>
#include <stdlib.h>


int N;
int A[105];
int B[105];



int lcmp(const void * a, const void * b){
  int l = *(int*) a;
  int r = *(int*) b;

  return r - l;
}

int rcmp(const void * a, const void * b){
  return lcmp(b, a);
}
// B is not meant to be sorted but qquestion is aksing for the minimum value,
// so it doesnt matter
int main()
{
  scanf("%d", &N);

  for(int i = 0 ; i < N ; i++){
    scanf("%d", &A[i]);
  }
  for(int i = 0 ; i < N ; i++){
    scanf("%d", &B[i]);
  }

  qsort(A, N, sizeof(int), lcmp);
  qsort(B, N, sizeof(int), rcmp);

  int ans = 0;
  for(int i = 0 ; i < N ; i++){
    ans += A[i] * B[i];
  }

  printf("%d", ans);
  

  return 0;
}
