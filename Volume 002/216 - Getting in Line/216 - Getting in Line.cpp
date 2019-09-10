#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct pos{
    int x, y;
};

struct nextNode{
    int nextN, nextM; //next Mask
};

struct pos comps[9];
double memo[9][(1 << 10)];
nextNode node[9][(1 << 10)];
int ttlEdge;

double dist(pos a, pos b){
    double distX = max(a.x, b.x) - min(a.x, b.x);
    double distY = max(a.y, b.y) - min(a.y, b.y);
    distX *= distX;
    distY *= distY;
    double sum = distX + distY;
    return sqrt(sum);
}

double solve(int currIdx, int mask){
    if(mask == 0) return 0;
    if(memo[currIdx][mask] != -1) return memo[currIdx][mask];
    double ans = (1 << 10);
    int minIdx = -1;
    for(int i = 0; i < ttlEdge; i++){
        if((mask & (1 << i)) != 0){
            double res = solve(i, mask ^ (1 << i)) + dist(comps[currIdx], comps[i]);;
            if(res < ans){
                ans = res;
                minIdx = i;
            }
        }
    }
    if(minIdx != -1){
        node[currIdx][mask].nextN = minIdx;
        node[currIdx][mask].nextM = mask ^ (1 << minIdx);
    }
    return memo[currIdx][mask] = ans;
}

void resetComp(){
    for(int i = 0; i < 9; i++){
        comps[i].x = 0;
        comps[i].y = 0;
    }
}

void reset(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j <= (1 << 9); j++) {
            memo[i][j] = -1;
            node[i][j].nextN = -1;
            node[i][j].nextM = -1;
        }
    }
}

void getOutput(int idx, int mask){
    double temp = dist(comps[idx], comps[node[idx][mask].nextN]) + 16;
    cout << fixed << setprecision(2);
    if(mask != 0){
        cout << "Cable requirement to connect (" << comps[idx].x << "," << comps[idx].y << ") to (" << comps[node[idx][mask].nextN].x << "," << comps[node[idx][mask].nextN].y << ") is " << temp << " feet." << endl;
        getOutput(node[idx][mask].nextN, node[idx][mask].nextM);
    }
}

int main(){
    int rep = 0;
    while(cin >> ttlEdge){
        if(ttlEdge == 0) break;
        rep++;
        resetComp();
        for(int i = 0; i < ttlEdge; i++) cin >> comps[i].x >> comps[i].y;
        cout << "**********************************************************" << endl;
        cout << "Network #" << rep << endl;
        double minTSP = (1 << 10);
        int idx = -1;
        for(int i = 0; i < ttlEdge; i++) {
            reset();
            double res = solve(i, ((1 << ttlEdge) - 1) ^ (1 << i));
            if(res < minTSP){
                minTSP = res; idx = i;
            }
        }
        minTSP = solve(idx, ((1 << ttlEdge) - 1) ^ (1 << idx)) + (ttlEdge - 1) * 16;
        getOutput(idx, ((1 << ttlEdge) - 1) ^ (1 << idx));
        cout << "Number of feet of cable required is " << fixed << setprecision(2) << minTSP << "."<< endl;
    }
    return 0;
}