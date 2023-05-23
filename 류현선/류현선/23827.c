//
//  23827.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/23.
//

#include <stdio.h>

int main(void) {
    // n 입력 받기
    int n;
    scanf("%d", &n);
    
    // 수열 입력 받기
    int a[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    // 모든 값 다 더하기
    int total = 0;
    for (int i=0; i<n; i++) {
        total += a[i];
    }
    
    // 앞에서 부터 하나씩 빼면서, 현재 값 * 남은 값을 answer에 더해주기.
    int answer = 0;
    for (int i=0; i<n; i++) {
        total -= a[i];
        answer += (a[i] * total) % 1000000007;
    }
    
    // answer 출력하기
    printf("%d", answer % 1000000007);
    return 0;
}
