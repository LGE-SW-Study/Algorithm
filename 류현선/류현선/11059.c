//
//  11059.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/06.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    char s[1001];
    scanf("%s", s);
//    printf("%s\n", s);
    
    // 짤라서 보자. 앞의 절반과 뒤의 절반 -> 앞 문자열과 뒤 문자열의 길이가 같다.
    // 즉, 각 문자열의 최대 길이 -> 전체 문자열의 절반. 6789367893라면 67893이 제일 긴 문자열이다.
    // 연속된 부분 문자열 -> 하나의 변수로 통제해서 반 잘라서 보는 느낌.
    // 답은 무조건 있다라는 조건.
    for (int i=strlen(s)/2; i>=0 ; i--) {
//        printf("%d\n",i);
        int num = 0;
        bool same = false;
        while (num + i*2 <= strlen(s)) {
            int sum1 = 0;
            int sum2 = 0;

            for (int j=num; j<num+i; j++) {
                sum1 += s[j] - '0';
            }
            for (int j=num+i; j<num+2*i; j++){
                sum2 += s[j] - '0';
            }
//            printf("%d %d %d %d \n", i,num, sum1, sum2);

            if (sum1 == sum2) {
                same = true;
                break;
            }
            else {
                num += 1;
            }
        }
        if (same == true) {
            printf("%d",i*2);
            break;
        }
    }
    
    return 0;
}
