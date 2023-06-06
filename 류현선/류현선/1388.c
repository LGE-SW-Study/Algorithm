//
//  1388.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/06.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    
    char arr[n][m];
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%c", &arr[i][j]);
        }
    }
    
    // 2차원 배열 동적 할당. (입력받은 n행, m열 만큼 배열 생성하기)
    int **visited = malloc(sizeof(int *) * n);
    for (int i=0; i<n; i++){
        visited[i] = malloc(sizeof(int) * m);
    }
    
    int result = 0;
    // printf("%c\n", arr[0][1]);
    // printf("%c\n", arr[0][0]);
    // printf("%c\n", arr[0][1]);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j] == 0) {
                visited[i][j] = 1;
                // printf("%d %d %c\n", i,j,arr[i][j]);
                if (arr[i][j] == '-') {
                    
                    int nj = j;
                    while (nj < m) {
                        nj++;
                        if (arr[i][nj] == '-') {
                            
                            visited[i][nj] = 1;
                        } else {
                            break;
                        }
                    }
                } else {
                    int ni = i;
                    while (ni < n) {
                        ni++;
                        if (arr[ni][j] == '|') {
                            visited[ni][j] = 1;
                        } else {
                            break;
                        }
                    }
                }
                result++;
            }
        }
    }
    
    printf("%d", result);
    
    
    return 0;
}
