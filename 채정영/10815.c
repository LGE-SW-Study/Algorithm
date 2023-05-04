#include <stdio.h>
#define BIAS 10000000

char check[(BIAS << 1) + 5];
int N, M;
int main()
{
    int tmp;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &tmp);
        check[tmp + BIAS] = 1;
    }
    scanf("%d", &M);
    
    for(int i = 0 ; i < M ; i++){
        scanf("%d", &tmp);
        printf("%d ", check[tmp + BIAS]);
    }
        
    return 0;
}