#include <stdio.h>

char exist[2005];

int main(){
    int N;
    
    scanf("%d", &N);
    
    for(int i = 0 ; i < N; i++){
        int num;
        scanf("%d", &num);
        exist[num + 1000] = 1;
    }

    for(int i = 0; i <= 2000; i++){
        if(exist[i])
            printf("%d ", i - 1000);
    }
    return 0;
}
