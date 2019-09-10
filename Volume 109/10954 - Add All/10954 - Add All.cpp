#include <iostream>
#include <queue>
using namespace std;

int main(){
    int rep;
    while(cin >> rep){
        if(rep == 0) break;
        priority_queue<long long, vector<long long>, greater<long long> > numss;
        while(rep--){
            long long temp; cin >> temp;
            numss.push(temp);
        }
        long long cost = 0;
        while(numss.size() > 1){
            int sum = numss.top();
            numss.pop();
            sum += numss.top();
            numss.pop();
            cost += sum;
            numss.push(sum);
        }
        cout << cost << endl;
    }
}