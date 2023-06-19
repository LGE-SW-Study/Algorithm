#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_Q 500


int T;
int queue[MAX_Q+1];
int front = -1;
int rear = -1;

int pop(){
  int nextTop = (front + 1) % MAX_Q ;
  if(front == rear){
    printf("q empty\n");
    return -1;
  }
  front = nextTop;
  return queue[nextTop];
}

void insert(int num){
  int nextRear = (rear + 1) % MAX_Q ;

  if( nextRear == front){
    printf("q full\n");
    return;
  }
  rear = nextRear;
  queue[nextRear] = num;
}

int main(){
  scanf("%d", &T);
  while(T--){
    int priority[10];
    int numP[105];
    int N, M;
    int mp;
    int p;

    memset(priority, 0, sizeof(priority));
    memset(queue, 0, sizeof(queue));
    front = -1;
    rear = -1;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
      scanf("%d", &p);
      insert(i);
      numP[i] = p;
      priority[p]++;

      if(M == i){
        mp = p;
      }
    }
  
    int j = 9;
    int count = 0;
    while(j > 0){
      if(priority[j]){
        int idx = pop();

        // priority == priority
        if(numP[idx] == j){
          priority[j]--;
          count++;
          if(idx == M){
            printf("%d\n", count);
            break;
          }
        }else {
          insert(idx);
        }
      } else{
        j--;
      }
    }
  }

  return 0;
}
