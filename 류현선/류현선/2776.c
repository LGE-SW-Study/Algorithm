//
//  2776.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/08.
//

#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    
    for (int y=0; y<t; y++) {
        int n;
        scanf("%d", &n);
        int book1[n];
        for (int j=0; j<n; j++) {
            scanf("%d", &book1[j]);
        }
        
        int m;
        scanf("%d", &m);
        int book2[m];
        for (int k=0;k<m;k++) {
            scanf("%d", &book2[k]);
        }
        
        // 정렬
        for (int i=0; i < n; i++) {
            for (int j=0; j<n-1; j++ ) {
                if (book1[j] > book1[j+1]) {
                    int temp = book1[j];
                    book1[j] = book1[j+1];
                    book1[j+1] = temp;
                }
            }
        }
        
        // 이분탐색
        for (int j = 0; j < m; j++) {
            int x = book2[j];
            
            int l = 0;
            int r = n;
            int check = 0;
            
            while (l<r) {
                int middle = (l+r) / 2;
                if (x == book1[middle]) {
                    check = 1;
                    break;
                }
                
                if (x < book1[middle]) {
                    r = middle - 1;
                } else {
                    l = middle + 1;
                }
                
            }
            if (check == 1) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        }
    }
    return 0;
}
