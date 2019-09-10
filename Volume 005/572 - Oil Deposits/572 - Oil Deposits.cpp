#include <iostream>
using namespace std;    

int row, col;

void checkList(int area [][100], int row, int col, int ttlRow, int ttlCol){
    if(row - 1 >= 0){
        if(col - 1 >= 0 && area[row-1][col-1] == 1) checkList(area, row-1, col-1, ttlRow, ttlCol);
        if(area[row-1][col] == 1) checkList(area, row-1, col, ttlRow, ttlCol);
        if(col + 1 <= ttlCol && area[row-1][col+1] == 1) checkList(area, row-1, col+1, ttlRow, ttlCol);    
    }
    else if(row + 1 <= ttlRow){
        if(col - 1 >= 0 &&area[row][col-1] == 1) checkList(area, row, col-1, ttlRow, ttlCol);
        if(col + 1 <= ttlCol && area[row][col+1] == 1) checkList(area, row, col+1, ttlRow, ttlCol);
    }
    else{
        if(col - 1 >= 0 && area[row+1][col-1] == 1) checkList(area, row+1, col-1, ttlRow, ttlCol);
        if(area[row+1][col] == 1) checkList(area, row+1, col, ttlRow, ttlCol);
        if(col + 1 <= ttlCol && area[row+1][col+1] == 1) checkList(area, row+1, col+1, ttlRow, ttlCol);
    }
    area[row][col] = 2;
    
}

int main() {
    int rep;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        int row, col;
        cin >> row >> col;
        int area[row][col];
        for(int j = 0; j < row; j++) {
            string temp;
            cin >> temp;
            for(int k = 0; k < temp.length(); k++) {
                if(temp[k] == '*') area[j][k] = 0;
                else if(temp[k] == '@') area[j][k] = 1;
            }
        }
        int shapes = 0;
        for(int j = 0; j < row; j++){
            for(int k = 0; k < col; k++){
                if(area[j][k] == 1){
                    checkList(area, j, k, row, col);
                    shapes++;
                }
            }
        }
        cout << shapes << endl;
    }
    return 0;
}