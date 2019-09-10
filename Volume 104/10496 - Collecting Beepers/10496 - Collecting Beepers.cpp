#include <iostream>
using namespace std;

struct coord{
    int x, y;
};

int x, y, n;
struct coord arr[25];
int memo[13][(1 << 13)];

int dist(struct coord A, struct coord B){
    int dR = A.x - B.x;
    if(dR < 0) dR = -dR;
    int dC = A.y - B.y;
    if(dC < 0) dC = -dC;
    return dR + dC;
}

int solve(int currIdx, int mask){
    if(mask == 0) return dist(arr[currIdx], arr[0]);
    if(memo[currIdx][mask] != -1) return memo[currIdx][mask];
    int ans = (1 << 30);
    for(int i = 1; i <= n; i++){
        if((mask & (1 << i)) != 0){ //mask AND 2^i
            //kalau di posisi ke i nyala artinya array ke i belum dikunjungi
            ans = min(ans, solve(i, mask ^ (1 << i)) + dist(arr[currIdx], arr[i]));
        }
    }
    return memo[currIdx][mask] = ans;
}

int main(){
    int rep; cin >> rep;
    while(rep--){
        int w, l; cin >> w >> l; // w = width, l = length
        cin >> arr[0].x >> arr[0].y;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i].x >> arr[i].y;
        for(int i = 0; i <= n; i++){
            for(int k = 0; k < (1 << (n + 1)); k++) memo[i][k] = -1;
        }
        //1 << (n + 1) - 1 --> 11...11 sebanyak n + 1 buah
        //di solved masukinnya 1 << (n + 1) karena semua node belum dikunjungi
        cout << "The shortest path has length " << solve(0, ((1 << (n + 1)) - 1) ^ 1) << endl;
        //^ artinya XOR, XOR dengan 1 karena titik pertama yang dikunjungi adalah titik 0, dan titik 0 ini
        // TELAH dikunjungi barusan, sehingga harus ditandai juga bahwa ia telha dikunjungi
    }
}