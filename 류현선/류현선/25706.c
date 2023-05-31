//
//  25706.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/31.
//

#include <stdio.h>

int main(void) {
    
    int n;
    scanf("%d", &n);
    
    // 이거 문제다 문제
    int h[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &h[n]);
    }
    
    for (int i=0; i<n; i++) {
        printf("%d ", h[n]);
    }
    
    int dp[n];
    for (int i=0; i<n; i++) {
        dp[i] = 1;
    }
    for (int j=n-2; j>=0; j--) {
        if (h[j] == 0) {
            dp[j] += dp[j+1];
        } else {
            if (j + h[j] + 1 < n) {
                printf("%d %d\n", j, h[j]);
                
                //dp[j] += dp[j + h[j] + 1];
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        printf("%d ", dp[i]);
    }
    
    return 0;
}
