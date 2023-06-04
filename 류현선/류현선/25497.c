//
//  25497.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/29.
//

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    char st[n];
    scanf("%s", st);
    
    int lCnt = 0;
    int sCnt = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        char temp = st[i];
        if (temp == 'L') {
            lCnt++;
        } else if (temp == 'S') {
            sCnt++;
        } else if (temp == 'R') {
            if (lCnt > 0) {
                answer++;
                lCnt--;
            } else {
                break;
            }
        } else if (temp == 'K') {
            if (sCnt > 0) {
                answer++;
                sCnt--;
            } else {
                break;
            }
        } else {
            answer++;
        }
    }
    
    printf("%d", answer);
    return 0;
}
