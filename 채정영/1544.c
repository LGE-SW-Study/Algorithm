#include <stdio.h>
#include <string.h>

int N;
char strs[55][55] ;
int ans = 0;

int checkSame(char * s1, char * s2){
    

    int s1len = strlen(s1);
    int s2len = strlen(s2);

    if(s1len != s2len)
        return 0;

    // s2 start idx
    char found = 0;
    for(int i = 0; i < s2len ; i++){
        int s1_idx = 0;
        int s2_idx = i;
        
        while(s1_idx < s1len){
            if(s1[s1_idx] != s2[s2_idx]){
                break;
            }
            s1_idx++;
            s2_idx++;

            if(s2_idx >= s2len)
                s2_idx = 0;
        }
        if(s1_idx == s1len)
            found = 1;
    }
    return found;
}
int main() {
    scanf("%d", &N);

    for(int i = 0 ; i < N; i++){
        char str[55];
        scanf("%s", str);
  
        int foundNew = 1;
        for(int j = 0; j < ans; j++){
            if(checkSame(strs[j], str)){
                foundNew = 0;
                break;
            }
        }
        if(foundNew){
            strcpy(strs[ans], str);
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}