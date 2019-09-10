#include <iostream>
using namespace std;

int main(){
    string real, encoded;
    while(cin >> real >> encoded){
        int idx = 0;
        for(int i = 0; i < (int)encoded.length(); i++) {
            if(real[idx] == encoded[i]) idx++;
        }
        if(idx == (int)real.length()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}