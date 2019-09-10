#include <iostream>
#include <vector>
#include <algorithm>
#define inf -1
using namespace std;

int ways[32769];

int lis(vector<int> miss, int idx){
    int maxV = 0;
    for(int i = idx + 1; i < (int) miss.size(); i++){
        if(miss[i] >= miss[idx]){
            if(ways[i] == 0) ways[i] = lis(miss, i);
            maxV = max(ways[i], maxV);
        }
    }
    if(idx != 0) return maxV + 1;
    else return maxV;
}

void reset(int ttlNum){
    for(int i = 0; i <= ttlNum; i++) ways[i] = 0;
}

int main(){
    int currMis, rep = 0;
    while(cin >> currMis){
        if(currMis == -1) break;
        if(rep != 0) cout << endl;
        rep++;
        vector <int> missiles;
        missiles.push_back(currMis);
        while(cin >> currMis){
            if(currMis == -1) {
                missiles.push_back(inf);
                reverse(missiles.begin(), missiles.end());
                cout << "Test #" << rep << ":" << endl;
                cout << "  maximum possible interceptions: " << lis(missiles, 0) << endl;
                break;
            }
            missiles.push_back(currMis);
        }
        reset((int) missiles.size() - 1);
    }
}