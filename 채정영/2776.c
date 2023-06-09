#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int seen[1000000];

int T, N, M;

int cmp(const void * a, const void *b)
{
    int na = *(int*) a;
    int nb = *(int*) b;
    
    if(na > nb)
        return 1;
    else if (na < nb)
        return -1;
    else
        return 0;
}

int main()
{
    scanf("%d", &T);

    while(T--){

        memset(seen, sizeof(seen), 0);
        scanf("%d", &N);
        for(int i = 0; i < N ; i++){
            int tmp;
            scanf("%d", &seen[i]);
        }

        qsort(seen,N,sizeof(int), cmp);
        
        scanf("%d", &M);

        for(int i = 0; i < M; i++){
            int tmp;
            scanf("%d", &tmp);
            if(bsearch(&tmp, seen, N, sizeof(int), cmp))
                printf("1\n");
            else
                printf("0\n");
        }
    }

    return 0;
}