//
//  1966.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/20.
//

#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);

    for (int try=0; try<t; try++) {
        int n,m;
        scanf("%d %d", &n, &m);
        int queue[100] = {0,};
        for (int i=0; i<n; i++) {
            scanf("%d", &queue[i]);
        }
        int result = 1;
        int f=0;
        int importance=0;
        
        while (1) {
            for (int j=0; j<n; j++) {
                if (queue[j] > importance) {
                    importance = queue[j];
                }
            }
            
            while (queue[f] != importance) {
                if (f >= n) {
                    f = 0;
                } else {
                    f++;
                }
            }
            
            if (f == m) {
                break;
            }
            
            queue[f] = 0;
            if (f >= n) {
                f = 0;
            } else {
                f++;
            }
            importance = 0;
            result++;
        }
        
        printf("%d", result);
    }
    
    return 0;
}
