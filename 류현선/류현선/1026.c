//
//  1026.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/14.
//

#include <stdio.h>
#include <stdlib.h>

// 정영이꺼 들고오기.
int cmp(const void *first, const void * second){

    int a = *(int *) first;
    int b = *(int *) second;

    if(a > b){
        return 1;
    } else if( a < b) {
        return -1;
    } else {
        return 0;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    int a[51];
    int b[51];
    
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }
    
    // 파라미터 의미 알아야할듯.
    qsort(a, n, sizeof(int), cmp);
    qsort(b, n, sizeof(int), cmp);
    
    int answer = 0;
    for (int i=0; i<n; i++) {
        answer += a[i] * b[n-1-i];
    }
    
    printf("%d", answer);
    
    return 0;
}
