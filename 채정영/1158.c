#include <stdio.h>
#include <stdlib.h>


// linked list
typedef struct NODE{
  int num;
  struct NODE * next;
} node;

typedef struct {
  int len;
  node * top;
  node * last;
} queue;

queue q;

void insert(int a){

  node * new = (node *)malloc(sizeof(node));
  new->num = a;
  new->next = 0x0;

  if(q.len == 0){
    q.top = new;
  } else{
    q.last->next = new;
  }
  q.last = new;

  q.len++;
  //printf("Inserting %d\n", a);
}

int pop(){

  if(q.len <= 0 || q.top == 0x0){
    printf("can't pop, q empty\n");
    return -1;
  }

  q.len--;

  node * gonner = q.top;
  int num = gonner->num;
  q.top = gonner->next;
  free(gonner);
  //printf("popping %d\n", num);
  return num;
}

void traversal()
{
  node * n = q.top;

  while(n != 0x0){
    printf(">> %d\n", n->num);
    n = n->next;
  }
}
// create circular queue

int N, K;
int arr[5005];
int main()
{
  q.len = 0;
  
  scanf("%d %d", &N, &K);

  for(int i = 1 ; i <= N; i++){
    insert(i);
    //traversal();
  }

  //traversal();


  int i = 0;
  printf("<");
  while(q.len > 0){
    i++;
    int num = pop();
    if(i == K){
     
      if(q.len != 0)
        printf("%d, ", num);
      else
        printf("%d", num);
      
      i = 0;
    } else {
      insert(num);
    }
  }
  printf(">");



  

  return 0 ;
}
