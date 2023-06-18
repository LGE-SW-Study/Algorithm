//
//  1158.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/18.
//

#include <stdio.h>

int main(void) {
    int n;
    int k;
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    int arr[5001] = {0,};
    
    int now = k;
    arr[now] = 1;
    
    printf("<%d", now);
    
    for (int i=0; i <n-1; i++) {
        for (int j=0; j<k; j++) {
            while (1) {
                now++;
                if (now > n) {
                    now = 1;
                }
                if (arr[now] == 0) {
                    break;
                }
            }
        }
        printf(", %d", now);
        arr[now] = 1;
    }
    printf(">");
    
    return 0;
}
