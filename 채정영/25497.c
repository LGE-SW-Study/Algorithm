#include <stdio.h>

int SK = 0 ;
int LR = 0 ;
int N;
char str[200005];
int cnt = 0 ;

int main()
{
    scanf("%d %s", &N, str);

    for(int i = 0; i < N ; i++){
        
        char c = str[i];
        if( c >= '0' && c <= '9'){
            cnt++;
        } else if(c == 'L'){
            LR++;
        } else if(c == 'R'){
            if(LR > 0)
            {
                cnt++;
                LR--;
            }else {
                break;
            }
        } else if(c == 'S'){
            SK++;
        } else if(c == 'K'){
            if(SK > 0)
            {
                cnt++;
                SK--;
            }else {
                break;
            }
        } else {
            ;
        }   
        //printf("%c, %d\n", c, cnt);
    }
    
    printf("%d", cnt);


    
    return 0;
}
