#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int numOfItems; cin >> numOfItems;
        int items[numOfItems];
        for(int j = 0; j < numOfItems; j++) cin >> items[j];
        sort(items, items + numOfItems);
        int ttl = 0;
        int startingIdx = numOfItems % 3;
        for(int j = startingIdx; j < numOfItems;j += 3) ttl += items[j];
        cout << ttl << endl;
    }
    return 0;
}