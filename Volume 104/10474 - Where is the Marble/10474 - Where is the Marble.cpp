#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int numOfMarble, numOfQuery;
    for(int i = 1;;i++){
        cin >> numOfMarble; cin >> numOfQuery;
        if(numOfMarble != 0 && numOfQuery != 0){
            int marbles[numOfMarble];
            for(int i = 0; i < numOfMarble; i++) cin >> marbles[i];
            sort(marbles, marbles+numOfMarble);
            cout << "CASE# " << i << ":" << endl;
            for(int i = 0; i < numOfQuery; i++){
                int currentlySearched, flag = 0;
                cin >> currentlySearched;
                for(int j = 0; j < numOfMarble; j++) {
                    if(marbles[j] == currentlySearched) {
                        cout << currentlySearched << " found at " << j+1;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) cout << currentlySearched << " not found";
                cout << endl;
            }
        }
        else break;
    }
}