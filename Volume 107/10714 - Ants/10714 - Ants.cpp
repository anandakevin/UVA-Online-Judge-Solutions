#include <iostream>
using namespace std;

int findMin(int len, int num){
    if((len/2) < num) return len - num;
    else return num;
}

int findMax(int len, int num){
    if((len/2) < num) return num;
    else return len - num;
}

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int len, numOfAnts, minTime = 0, maxTime = 0;
        cin >> len >> numOfAnts;
        for(int j = 0; j < numOfAnts; j++){
            int num; cin >> num;        
            minTime = max(minTime, findMin(len, num));
            maxTime = max(maxTime, findMax(len, num));
        }
        cout << minTime << " " << maxTime << endl;
    }
}