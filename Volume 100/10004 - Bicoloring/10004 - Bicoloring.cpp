#include <iostream>
#include <queue>
using namespace std;

int ttlVertex, ttlEdge;
int adjMatrix[201][201];
int colors[201];
bool visited[201];

void reset(){
    for(int i = 0; i < 201; i++){
        colors[i] = -1;
        visited[i] = false;
        for(int j = 0; j < 201; j++) adjMatrix[i][j] = 0;
    }
}

int main(){
    while(cin >> ttlVertex && ttlVertex){
        reset();
        cin >> ttlEdge;
        for(int i = 0; i < ttlEdge; i++){
            int a, b; cin >> a >> b;
            adjMatrix[a][b] = adjMatrix[b][a] = 1;
        }
        bool colorAble = true;
        queue<int> q;
        colors[0] = 0;
        int available[2];
        q.push(0);
        int currIdx, ttlColor = 1;
        while((int)q.size()){
            currIdx = q.front();
            for(int i = 0; i < 2; i++) available[i] = true;
            for(int i = 0; i < ttlEdge; i++){
                if(adjMatrix[currIdx][i] != 0 && visited[i] == false){
                    q.push(i);
                    visited[i] = true;
                    int currColor = 3;
                    for(int j = 0; j < ttlEdge; j++) {
                        if(adjMatrix[i][j] != 0) available[colors[j]] = false;
                    }
                    for(int j = 0; j < 2; j++){
                        if(available[j]) {
                            currColor = j; break;
                        }
                    }
                    if(currColor > 2) {colorAble = false; break;}
                    colors[i] = currColor;
                }
            }
            q.pop();
        }
        if(colorAble) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
}