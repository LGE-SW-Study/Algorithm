#include <stdio.h>


// nlog10(n) => 600000
int main(){
    
    int n, d;
    int cnt = 0;
    
    scanf("%d %d", &n, &d);

    for(int i = 1; i <= n; i++){
        int num = i;
        while( num != 0){
            if( num % 10 == d)
                cnt++;
            num /= 10;
        }
    }
    printf("%d", cnt);

    return 0;
}
