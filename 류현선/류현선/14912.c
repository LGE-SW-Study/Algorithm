//
//  14912.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    // n <= 100,000 자연수
    // d <= 9 양의 정수
    
    int n;
    int d;
    
    scanf("%d %d", &n, &d);
    
    // 정수 -> 문자열 변경
    // 문자열 인덱싱을 통해 하나씩 정수로 바꿔서 개수를 체크한다.
    // 결과 출력한다.
    int result = 0;
    for (int i=1; i<=n; i++) {
        char str[1000002];
        sprintf(str, "%d", i);
        for (int j=0; j<strlen(str)-1; j++) {
            int x = i / 10;
            if (x == d) {
                result += 1;
            }
        }
        if (i % 10 == d) {
            result += 1;
        }
    }
    
    printf("%d", result);
    
    return 0;
}
