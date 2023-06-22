//
//  1302.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/18.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    
    char dict[1001][51];
    int cnt[1001];
    int idx = 0;
    int sameIdx = 0;
    for (int i=0; i < n; i++) {
        char temp[51];
        scanf("%s", temp);
        int same = 0;
        for (int j=0; j<=idx; j++) {
            char x[51];
            strcpy(x, dict[j]);
            if (strcmp(x, temp) == 0) {
                sameIdx = j;
                same = 1;
                break;
            }
        }
        
        // 같은놈 찾았다면 cnt만 증가
        if (same) {
            cnt[sameIdx]++;
        }
        // 같은놈 없다면 dict 배열에 temp 문자열 추가.
        else {
            strcpy(dict[idx], temp);
            cnt[idx] = 1;
            idx++;
        }
    }

    
    
    // 제일 cnt 큰놈 출력 준비
    
    int maxCnt = 0;
    char result[51];
    for (int i=0; i<n; i++) {
        
        if (cnt[i] >= maxCnt) {
            // 사전순으로 빠른거 확인해야함
            if (cnt[i] == maxCnt) {
                if (strcmp(result, dict[i]) > 0) {
                    // result가 크면 양수, result가 작으면 음수
                    strcpy(result,dict[i]);
                }
            }
            else {
                maxCnt = cnt[i];
                strcpy(result, dict[i]);
            }
        }
    }
    
    printf("%s", result);
    
    
    return 0;
}
