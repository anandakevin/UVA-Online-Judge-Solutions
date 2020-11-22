#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;



int main() {
    int towers[10001][2];
    memset(towers, 0, sizeof(towers));
    int l, h, r;
    while(cin >> l >> h >> r) {
        for(int i = l; i <= r; i++) {
            int max1 = max(h, towers[i][0]);
            int max2 = max(h, towers[i][1]);
            int max3 = max(max1, max2);
            
        }
    }
    int currheight = 0;
    /*
    for(int i = 1; i < 10001; i++) {
        if(currheight > towers[i]) cout << i - 1 << " " << towers[i] << " ";
        else if(currheight < towers[i]) cout << i << " " << towers[i] << " ";
        if((currheight == 0 && towers[i] != 0)) cout << i << " ";
        currheight = towers[i];
    }
    */
    for(int i = 1; i < 10001; i++) {
        if(towers[i] != towers[i - 1]) cout << towers[i] << " ";
    }
    return 0;
}