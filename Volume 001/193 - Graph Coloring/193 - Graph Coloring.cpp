#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int adjMatrix[101][101], vertex, maxRes;
int colors[101];
vector<int> blackies;

void reset(){
    for(int i = 0; i < 101; i++){
        colors[i] = -1;
        maxRes = 0;
        for(int j = 0; j < 101; j++) adjMatrix[i][j] = 0;
    }
}

bool blackable(int currNode){
    for(int i = 0; i < vertex; i++){
        if(i != currNode && adjMatrix[currNode][i] == 1 && colors[i] == 1) return false;
    }
    return true;
}

vector<int> ctBlack(){
    vector<int> blacks;
    for(int i = 1; i <= vertex; i++) {
        if(colors[i] == 1) blacks.push_back(i);
    }
    return blacks;
}

int solve(int currNode){
    int ttlBlack = 0;
    if(currNode == vertex) {
        if(blackable(currNode)) colors[currNode] = 1;
        else colors[currNode] = 0;
        vector<int> currBlacks = ctBlack();
        if(maxRes < (int)currBlacks.size()) {
            maxRes = currBlacks.size();
            blackies = currBlacks;
        }
        ttlBlack = currBlacks.size();
        colors[currNode] = -1;
        return ttlBlack;
    }
    for(int i = 0; i < 2; i++){
        if(i == 1 && !blackable(currNode)) continue;
        colors[currNode] = i;
        int res = solve(currNode + 1);
        if(ttlBlack < res) ttlBlack = res;
        colors[currNode] = -1;
    }
    return ttlBlack;
}

int main(){
    int rep; cin >> rep;
    while(rep--){
        reset();
        int edge; cin >> vertex >> edge;
        while(edge--){
            int fEdge, sEdge; cin >> fEdge >> sEdge;
            adjMatrix[fEdge][sEdge] = 1;
            adjMatrix[sEdge][fEdge] = 1;
        }
        cout << solve(1) << endl;
        for(int i = 0; i < (int)blackies.size(); i++) {
            cout << blackies[i];
            if(i != (int)blackies.size() - 1) cout << " ";
        }
        cout << endl;
        blackies.clear();
    }
    return 0;
}