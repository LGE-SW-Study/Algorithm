#include <stdio.h>
int N, M, K;

int mat1[105][105];
int mat2[105][105];
int mat3[105][105];

void printMat(){

    for(int i = 0; i < N; i++){
        for(int j=0 ; j < K; j++){
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i =0 ; i < N ;i++){
        for(int j= 0; j < M; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    scanf("%d %d", &M, &K);
    
    for(int i =0 ; i < M ;i++){
        for(int j= 0; j < K; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            for(int k = 0; k < M ; k++){
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printMat();

        
    return 0;
}
