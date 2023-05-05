#include <stdio.h>


// max cap => 50  
// 1 -> 2,3 -> 4,5,6,7-> 8,9,10,11,12,13,14,15,16
int heap[200];
int size;

// swaps elements in heap by idx
void swap_heap(int a, int b)
{
    int c = heap[a];
    heap[a] = heap[b];
    heap[b] = c;
}

// needs to be called after an element is removed...
void heapify(){

    int idx = 1;

    while(1)
    {
        int left = idx*2;
        int right = idx*2 + 1;
        if(heap[left] == -1 && heap[right] == -1 )
        {
            break;
        }
        
        if(heap[idx] >= heap[left] && heap[idx] >= heap[right])
        {
            break;
        }

        // if equal, select right
        if(heap[left] > heap[right])
        {
            swap_heap(left, idx);
            idx = left;
        } 
        else 
        {
            swap_heap(right, idx);
            idx = right;
        }
    }

}

void print_heap()
{
    printf("HEAP :: \n");
    for(int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
}

void insertElem(int elem)
{
    size++;
    int idx = size;
    heap[idx] = elem;
    // check until parent exist
    while(idx/2 >= 1 && heap[idx/2] < elem)
    {
        swap_heap(idx, idx/2);
        idx = idx/2;
    }
}

int popElem()
{
    
    int ret = heap[1];
    heap[1] = -1;
    // swaps last elem with first elem.
    swap_heap(size, 1);
    heapify();
    size--;

    return ret;
}

int n;
// Priority Queue
int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= (n << 1); i++)
    {
        heap[i] = -1;
    }

    // initial votes
    int d;
    scanf("%d", &d);
    
    for(int i = 1 ; i < n ; i++)
    {
        int m;
        scanf("%d", &m);

        insertElem(m);
        //print_heap();
    }

    int cnt = 0;
    while(d <= heap[1])
    {
        int elem = popElem();
        elem--;
        d++;
        cnt++;
        insertElem(elem);
        //print_heap();
    }
    printf("%d", cnt);

    return 0;
}