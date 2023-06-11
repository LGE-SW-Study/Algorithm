//
//  2740.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/03.
//

#include <stdio.h>

int main(void) {
    int n;
    int m;
    
    scanf("%d %d", &n, &m);
    
    int matrixA[n][m];
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    int k;
    scanf("%d %d", &m, &k);
    int matrixB[m][k];
    for (int i=0; i < m; i++) {
        for (int j=0; j < k; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    int result[n][k];
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            int s=0;
            for (int l=0; l<m; l++) {
                s += (matrixA[i][l] * matrixB[l][j]);
            }
            result[i][j] = s;
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < k; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
