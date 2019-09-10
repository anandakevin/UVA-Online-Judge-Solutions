#include <iostream>
using namespace std;

int boardSize, bishops;
long long memo[65][2]; 
int row[9], ttlBishops;
//memo untuk menyimpan jumlah kombinasi yg mungkin untuk state dengan i bishop dan warna hitam atau putih
//memo[i][j] --> i jumlah bishop, j warna yg sedang dipilih untuk diletakkan
//j 0 putih, j 1 hitam

int diff(int a, int b){
    int res = a - b;
    if(res < 0) res *= -1;
    return res;
}

void reset(){
    for(int i = 0; i < 65; i++) {
        for(int j = 0; j < 2; j++) memo[i][j] = 0;
    }
    memo[0][0] = memo[0][1] = 1;
    ttlBishops = 0;
    for(int i = 0; i < 9; i++){
        row[i] = -1;
    }
}

int count(){
    int ttlPermute = 0;
    for(int i = 1; i < bishops; i++){
        ttlPermute += memo[i][0] * memo[bishops - i][1];
    }
    ttlPermute += memo[bishops][0] + memo[bishops][1];
    return ttlPermute;
}

void solve(int currNum, int color){
    if(boardSize % 2 == 0 && currNum >= boardSize) return;
    else if(boardSize % 2 == 1){
        if(color == 1 && currNum >= boardSize) return; //hitam
        else if(color == 0 && currNum >= (boardSize - 1)) return;
    }
    int maxRow;
    if(boardSize % 2 == 1 && color == 0) maxRow = ((currNum + 1) % 2 == 0) ? (currNum + 2) : (currNum + 1);
    else maxRow = ((currNum + 1) % 2 == 0) ? currNum : (currNum + 1);
    for(int i = 1; i <= maxRow; i++){
        if(row[i] != 1 && (ttlBishops + 1) <= bishops){
            row[i] = 1;
            ttlBishops++;
            memo[ttlBishops][color]++;
            solve(currNum + 1, color); // ini buat ambil
            row[i] = -1;
            ttlBishops--;
        }
    }
    solve(currNum + 1, color); // ini buat tidak ambil
}

int main(){
    while(cin >> boardSize >> bishops){
        if(boardSize == 0 && bishops == 0) break;
        reset();
        if(boardSize != 1 && bishops > (boardSize * 2 - 2)) cout << 0 << endl;
        else if(bishops == 0) cout << 1 << endl;
        else{
            solve(0, 0);
            solve(0, 1);        
            cout << count() << endl;
        }       
    }
}
