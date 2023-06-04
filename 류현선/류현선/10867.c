//
//  10867.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/22.
//

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    // 양의 정수 확인용
    int plus_cnt[1001] = { 0, };
    // 음의 정수 확인용
    int minus_cnt[1001] = { 0, };
    int now;
    
    // 입력 받은 애들 하나하나씩 카운팅 어차피 -1000 ~ 1000까지 범위니까 별거 없다.
    // 해서 cnt 증가된 애들만 출력한다. 사실 배열 한개로 해도 될거 같은데
    for (int i=0; i<n; i++) {
        scanf("%d", &now);
        if (now >= 0) {
            plus_cnt[now]++;
        } else {
            minus_cnt[now * (-1)]++;
        }
    }
    
    for (int i = 1000; i > 0; i--) {
        if (minus_cnt[i] != 0) {
            printf("%d ", i * (-1));
        }
    }
    
    for (int i = 0; i < 1001; i++) {
        if (plus_cnt[i] != 0) {
            printf("%d ", i);
        }
    }
    
    return 0;
}
