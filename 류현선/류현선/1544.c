//
//  1544.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/10.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    char answer[50][50];
    int k = 0;
    int result = 0;
    for (int i=0; i<n; i++) {
        char str[50];
        scanf("%s", str);
        
        if (k == 0) {
            strcpy(answer[k], str);
            k++;
        }
        else {
            for (int j=0; j < k; j++) {
                char temp[50];
                strcpy(temp, answer[j]);
                
                // 왼쪽으로 이동시키면서 비교
                bool sameFlag = false;
                int x=0;
                while (x < strlen(temp)) {
                    if (strcmp(temp, str) == 0) {
                        sameFlag = true;
                        break;
                    }
                    
                    char c = temp[0];
                    for (int l=0;l<strlen(temp)-1;l++) {
                        temp[l] = temp[l+1];
                    }
                    temp[strlen(temp)-1] = c;
                    
                    x++;
                }
                
                // 같은 문자열이 있다면
                if (sameFlag) {
                    result++;
                }
                // 같은 문자열이 없으면 배열에 추가.
                else {
                    strcpy(answer[k], str);
                    k++;
                }
            }
            
        }
        
    }
    
    printf("%d", result-k);
    return 0;
}
