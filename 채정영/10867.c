#include <stdio.h>

int heap[100005];
int N;
int heapSize = 0;

void swap_idx(int i, int j){
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}
void heapify(){

    int idx = 1;
    while(idx <= heapSize/2){
        int l = heap[idx * 2];
        int r = heap[idx * 2 + 1];
        if(heap[idx] < l && heap[idx] < r)
            break;

        if(l < r){
            swap_idx(idx * 2, idx);
            idx = idx * 2;
        }else{
            swap_idx(idx * 2+1, idx);
            idx = idx * 2 + 1;
        }
    }
}


void insert(int num){
    heap[++heapSize] = num;
    int idx = heapSize;
    while(idx > 1){        
        if(heap[idx] < heap[idx/2])
            swap_idx(idx, idx/2);
        else
            break;
        idx = idx/2;
    }
}

int pop(){
    int smallest = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    heapify();

    return smallest;
}
void printheap(){
    printf("\n------heap------\n" );
    for(int i = 1; i <= N; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n----------\n");
}

// n lg n

int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        int num;
        scanf("%d", &num);

        insert(num);
        //printheap();
    }

//    printf("DONE\n");
    int prev = 1e9;
    int i = 0;
    while(i++ < N){
        
  //      printheap();
        int num = pop();
        if(num == prev)
            continue;
        prev = num;
        printf("%d ", num);
        
    }
    
    return 0;
}
