#include <iostream>
using namespace std;

int movement[][2] = {
    {1,1},
    {1,0},
    {1,-1},
    {0,1},
    {0,-1},
    {-1,1},
    {-1,0},
    {-1,-1},
};


int countBomb(int x, int y, int height, int width, char map[][101]){
    int bomb = 0;
    for(int k = 0; k < 8; k++){
        int xtemp = x + movement[k][0];
        int ytemp = y + movement[k][1];
        if(xtemp >= 0 && xtemp <= (height - 1) && ytemp >= 0 && ytemp <= (width - 1) && map[xtemp][ytemp] == '*') bomb++;
    }
    return bomb;
}

int main(){
    int width, height, ct = 0;
    char map[101][101];
    cin >> height >> width;
    while(width != 0 && height != 0){
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++) cin >> map[i][j];
        }
        cout << "Field #" << ++ct << ":" << endl;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(map[i][j] == '*') cout << "*";
                else cout << countBomb(i, j, height, width, map);
            }
            cout << endl;
        }
        cin >> height >> width;
        if(width != 0 && height != 0) cout << endl;
    }
    return 0;
}