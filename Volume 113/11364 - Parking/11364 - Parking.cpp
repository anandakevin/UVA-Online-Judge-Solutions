#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int rep;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        int numOfStores; cin >> numOfStores;
        int coords[numOfStores];
        for(int j = 0; j < numOfStores; j++) cin >> coords[j];
        sort(coords, coords + numOfStores);
        cout << 2*(coords[numOfStores - 1] - coords[0]) << endl;
    }
}