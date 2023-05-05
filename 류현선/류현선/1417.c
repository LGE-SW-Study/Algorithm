//
//  1417.c
//  류현선
//
//  Created by ryu hyunsun on 2023/05/05.
//

#include <stdio.h>

// 참고: https://lsoovmee-rhino.tistory.com/48
// 접근 : 기호 1번을 뺀 나머지 입력에 대해 최대 힙을 만들고, 힙에서 pop한 값이 기호 1번보다 크다면 -1 후 다시 힙에 넣어준다.
// 힙을 어떻게 구현하지?

typedef struct NODE
{
    int data;
} Node;

typedef struct HEAP
{
    Node heap[51]; // 저장할 힙 트리의 노드 개수 설정. 50으로 하니까 아웃오브바운스 뜬다.
    int size; // 현재 힙 배열의 사이즈. 구조체 배열로 트리를 구성할 때 필요한 변수.
} Heap;

void Input(Heap *hp, int data) {
    int i = 0;
    int temp;

    hp -> size++;
    i = hp -> size;
    hp -> heap[i].data = data;

    while (i > 1)
    {
        // 부모 노드보다 새로운 노드의 데이터가 더 크면 바꿔주기.
        if (hp -> heap[i/2].data < hp -> heap[i].data)
        {
            temp = hp -> heap[i].data;
            hp -> heap[i].data = hp->heap[i/2].data;
            hp -> heap[i/2].data = temp;

            i = i/2; // 새로운 노드는 i/2번째에 저장되어 있으니까, 다시 새롭게 들어간 자리의 부모노드와 크기비교를 위해 i/2로 갱신해준다.
        }
        // 부모 노드가 더 크다면, 더 볼 필요도 없음.
        else
        {
            break;
        }
    }
}

// 루트노드를 삭제한다.
int Delete(Heap *hp) {
    int i = 1;
    int j = 0;
    int temp;

    int max;

    // 루트 노드의 값을 리턴할거다
    max = hp -> heap[i].data;
    // 제일 처음 노드의 값을 마지막 노드의 데이터로 저장하고, 사이즈 하나 빼준다.
    hp -> heap[i].data = hp -> heap[hp -> size--].data;

    // 그러고 나서, 루트 노드의 값이 가장 큰지 확인한다.
    while (i <= hp->size)
    {
        j = 2 * i; // i번째 노드의 자식 노드는 2 * i 번째 노드와 2 * i + 1번째 노드임.
        if (j > hp -> size) {
            break;
        }

        // 부모 노드의 값이 자식 노드의 값보다 크다면 더 안봐도 됨.
        if (hp -> heap[i].data >= hp -> heap[j].data && hp -> heap[i].data >= hp -> heap[j+1].data) {
            break;
        }
        // 위 경우가 아니라면, 부모가 더 작은거니까 바꿔줘야함. 두 자식 중 더 큰 값을 사용한다.
        if (hp -> heap[j].data < hp -> heap[j+1].data) {
            j++;
        }

        temp = hp -> heap[j].data;
        hp -> heap[j].data = hp -> heap[i].data;
        hp -> heap[i].data = temp;

        i = j; // 바뀐 위치의 인덱스로 i를 갱신. 이때 항상 j 번째에 트리의 가장 마지막 노드 데이터가 저장되어 있다.

    }
    
    return max;
}


int main(void) {
    int n;
    scanf("%d", &n);
    int dasom;
    scanf("%d", &dasom);
    int answer = 0;

    Heap hp;

    // 다솜이를 제외한 후보들의 득표수를 받아서 힙에 넣어준다.
    for (int i=1;i<n;i++) {
        int hubo;
        scanf("%d", &hubo);
        Input(&hp, hubo);
    }

    // 후보가 다솜이 밖에 없다면 볼 필요 없음.
    if (n == 1)
    {
        printf("%d", answer);
    }
    else
    {
        int max_value = Delete(&hp);
        while (dasom <= max_value)
        {
            // printf("%d %d %d\n", max_value, dasom, answer);
            dasom++;
            max_value--;
            answer++;
            Input(&hp, max_value);
            max_value = Delete(&hp);
        }
        // 출력에 \n 넣으면 안됨.
        printf("%d", answer);
    }

    return 0;
}
