#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
// binsearch??
int n;

int main(){

    cin >> n;
    int d;
    cin >> d;
    for(int i = 1 ; i < n; i++){
        int m;
        cin >> m;

        pq.push(m);
    }
    int cnt = 0;

    while(!pq.empty() && pq.top() >= d){
        d++;
        int prev = pq.top();
        pq.pop();

        pq.push(prev - 1);
        cnt++;
    }
    cout << cnt;
    return 0;
}