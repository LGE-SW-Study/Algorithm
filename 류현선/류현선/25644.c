//
//  25644.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/21.
//

#include <stdio.h>

// max를 정의하지 않았다면.
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    int i = n-1;
    int j = i-1;
    int answer = 0;
    
    while (i >= 0 && j >= 0) {
        if (a[i] <= a[j]) {
            i = j;
            j = i-1;
        } else {
            answer = max(answer,a[i]-a[j]);
            j--;
        }
    }
    
    printf("%d", answer);
    return 0;
}
