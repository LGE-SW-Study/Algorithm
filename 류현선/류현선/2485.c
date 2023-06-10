//
//  2485.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/10.
//

#include <stdio.h>

int findGCD(int x, int y) {
    if (y==0) {
        return x;
    }
    else {
        return findGCD(y, x%y);
    }
}


int main(void) {
    int n;
    scanf("%d", &n);
    // 각 간격마다 최소공배수 -> 그 간격마다 나무 심기
    // 1,3,7,13 -> 간격은 2,4,6 -> 최소 간격: 2.
    
    int trees[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &trees[i]);
    }
    
    int arr[n];
    for (int i=1; i<n; i++) {
        arr[i] = trees[i] - trees[i-1];
    }
    
    int gcd = arr[1];
    for (int i=2; i<n;i++) {
        gcd = findGCD(gcd, arr[i]);
    }
    
    int answer = 0;

    for (int i=1; i<n; i++) {
        
        int temp = arr[i];
        
        answer = answer + (temp / gcd) - 1;
    }
    
    printf("%d", answer);

    return 0;
}
