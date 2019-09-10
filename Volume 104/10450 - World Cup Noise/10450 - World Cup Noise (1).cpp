#include <iostream>
using namespace std;

long long pos[52][2];

int main(){
    for(int i = 0; i < 52; i++){
        pos[i][0] = 0;
        pos[i][1] = 0;
    }
    pos[1][0] = 1;
    pos[1][1] = 1;
    for(int i = 2; i < 52; i++){
        pos[i][0] = pos[i - 1][0] + pos[i - 1][1];
        pos[i][1] = pos[i - 1][0];
    }
    int rep, tc = 0;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        int inp;
        cin >> inp;
        cout << "Scenario #" << ++tc << ":" << endl;
        cout << pos[inp][0] + pos[inp][1] << endl << endl;
    }
}