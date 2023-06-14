#include <stdio.h>

char map[55][55];
int N, M;

int main(){
    
    scanf("%d %d\n", &N, &M);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            scanf(" %c", &map[i][j]);
        }
    }

    int cnt = 0;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M; j++)
        {
            cnt++;
            if((i-1 >= 0 && map[i][j] == '|') && map[i-1][j] == '|'){
                cnt--;
            } else if( (j - 1 >= 0 && map[i][j] == '-') && map[i][j-1] == '-'){
                cnt--;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}
