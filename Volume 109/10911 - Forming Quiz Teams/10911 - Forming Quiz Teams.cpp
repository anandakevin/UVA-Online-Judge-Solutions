#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct pos{
    int x, y;
};

int ttlEdge;
double minRes, memo[1 << 17];
pos ppl[17];
double distP[17][17];

void resetCt(){
    for(int i = 0; i < (1 << 17); i++) memo[i] = -1;
}

void reset(){
    minRes = (1 << 20);
    for(int i = 0; i < 17; i++) {
        ppl[i].x = -1;
        ppl[i].y = -1;
    }
}

double dist(int a, int b){
    int distX = ppl[a].x - ppl[b].x;
    int distY = ppl[a].y - ppl[b].y;
    distX *= distX;
    distY *= distY;
    return sqrt(distX + distY);
}

double solve(int fIdx, int f2Idx, int firstStud, int secStud, int mask){
    if(mask == 0) return 0;
    if(memo[mask] != -1) return memo[mask];
    double minLRes = (1 << 20);
    for(int i = 0; i < ttlEdge * 2; i++){
        if(mask & (1 << i)){   
            for(int j = i + 1; j < ttlEdge * 2; j++) {
                if(mask & (1 << j)) {
                    minLRes = min(minLRes, solve(fIdx, f2Idx, i, j, (mask ^ ((1 << i) + (1 << j)))) + distP[i][j]);
                }
            }
        }
    }
    if(mask == (((1 << (ttlEdge * 2)) - 1) ^ ((1 << fIdx) + (1 << f2Idx)))) minLRes += distP[firstStud][secStud];
    return memo[mask] = minLRes;
}

int main(){
    int rep = 0;
    while(cin >> ttlEdge && ttlEdge){
        rep++;
        reset();
        string name;
        for(int i = 0; i < (ttlEdge * 2) ; i++) cin >> name >> ppl[i].x >> ppl[i].y;
        for(int i = 0; i < ttlEdge * 2; i++){
            for(int j = i + 1; j < ttlEdge * 2; j++) distP[i][j] = dist(i, j);
        }
        resetCt();
        if(ttlEdge == 1) minRes = distP[0][1];
        else {
            for(int i = 0; i < ttlEdge * 2; i++){
                for(int j = i + 1; j < ttlEdge * 2; j++) {
                    double res = solve(i, j, i, j, ((1 << (ttlEdge * 2)) - 1) ^ ((1 << i) + (1 << j)));
                    minRes = min(minRes, res);
                }
            }
        }
        cout << fixed << setprecision(2) << "Case " << rep << ": " << minRes << endl;
    }
}