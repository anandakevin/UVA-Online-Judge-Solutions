#include <iostream>
#include <vector>
using namespace std;

int matrix[10001][10001];

void reset(){
    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < 10001; j++){
            matrix[i][j] = -100000;
        }
    }
}

void getOutput(int row, int col){
    int ttlNonZero;
    cout << row << " " << col << endl;
    for(int i = 0; i < row; i++){
        ttlNonZero = 0;
        vector<int> pos;
        vector<int> values;
        for(int j = 0; j < col; j++){
            if(matrix[j][i] != 0){
                ttlNonZero++;
                values.push_back(matrix[j][i]);
                pos.push_back(j + 1);
            }
        }
        if(ttlNonZero > 0) cout << ttlNonZero << " ";
        else cout << ttlNonZero;
        for(int i = 0; i < (int)pos.size(); i++){
            cout << pos[i];
            if(i != (int)pos.size() - 1) cout << " ";
        } 
        cout << endl;
        for(int i = 0; i < (int)values.size(); i++) {
            cout << values[i];
            if(i != (int)values.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
}

int main(){
    int row, col;
    while(cin >> row >> col){
        reset();
        for(int i = 0; i < row; i++){ // i = row
            int nonzero; cin >> nonzero;
            int positions[nonzero];
            for(int j = 0; j < nonzero; j++) cin >> positions[j];
            for(int j = 0; j < nonzero; j++) 
                cin >> matrix[i][positions[j] - 1];
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == -100000) matrix[i][j] = 0;
            }
        }
        getOutput(col, row);
    }
    return 0;
}