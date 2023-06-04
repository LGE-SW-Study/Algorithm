//
//  1049.c
//  류현선
//
//  Created by ryu hyunsun on 2023/06/01.
//

#include <stdio.h>

// min를 정의하지 않았다면.
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#include <stdio.h>

int main(void) {
    
    int n;
    int m;
    scanf("%d %d", &n, &m);
    
    // 제일 싼 애들만 보면 된다.
    // 패키지에서 제일 싼 애와 낱개에서 제일 싼 애 * 6을 비교해서 보자.
    int package_min = 6001;
    int single_min = 1001;
    for (int i=0; i<m; i++) {
        int package;
        int single;
        scanf("%d %d", &package, &single);
        
        package_min = min(package_min, package);
        single_min = min(single_min, single);
    }
    
    int answer = 0;
    if (package_min > single_min * 6) {
        answer = single_min * 6;
    } else {
        answer += (n / 6) * package_min;
        int mod = n % 6;
        if (mod * single_min > package_min) {
            answer += package_min;
        } else {
            answer += mod * single_min;
        }
    }
    
    printf("%d", answer);
    return 0;
}
