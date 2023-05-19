//
//  10815.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/05.
//

#include <stdio.h>
#include <stdbool.h>

// m * n = 500000 * 20000000 -> n^2은 시간초과. 이분탐색.

// 이거도 시간초과.

int main(void) {
    int n;
    scanf("%d", &n);
    
    int cards[n];
    for (int i=0;i<n;i++) {
        scanf("%d", &cards[i]);
    }

    int m;
    scanf("%d", &m);

    int all_cards[m];
    int answer[m];
    for (int i=0;i<m;i++) {
        scanf("%d", &all_cards[i]);
    }

    // 1. 상근이가 가지고 있는 카드를 오름차순 정렬한다.
    for (int i=0; i < n; i++) {
        for (int j=i+1; j < n; j++) {
            if (cards[i] > cards[j]) {
                int temp = cards[j];
                cards[j] = cards[i];
                cards[i] = temp;
            }
        }
    }
//    for (int i=0;i<n;i++) {

//        printf("%d ", cards[i]);

//    }

    // 2. 전체 카드를 가지고 상근이 카드를 이분탐색한다.
    for (int i=0; i < m; i++) {
        int l=0;
        int r=n-1;
        bool find = false;
        int temp = all_cards[i];
        
        while (l <= r) {
            int middle;
            if ((l+r)%2 == 1) {
                middle = (l + r) / 2 + 1;
            } else {
                middle = (l + r) / 2;
            }
            if (temp > cards[middle]) {
                l = middle+1;
            } else if (temp < cards[middle]) {
                r = middle-1;
            } else if (temp == cards[middle]) {
                find = true;
                break;
            }
//            printf("%d", middle);
        }

        if (find == true) {
            answer[i] = 1;
        } else {
            answer[i] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", answer[i]);
    }
    
    return 0;
}
