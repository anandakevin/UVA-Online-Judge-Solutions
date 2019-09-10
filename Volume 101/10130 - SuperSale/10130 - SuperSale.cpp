#include <iostream>
using namespace std;

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int numOfItems; cin >> numOfItems;
        int items[numOfItems][2];
        for(int j = 0; j < numOfItems; j++) cin >> items[j][0] >> items[j][1];
        int dp [35];
        for(int j = 0; j < 35; j++) dp[j] = 0;
        for ( int j = 0; j < numOfItems; j++ ) {
            for ( int k = 32; k >= 0; k-- ) {
                if ( items [j][1] <= k && dp [k] < dp [k - items [j][1]] + items [j][0] )
                    dp [k] = dp [k - items [j][1]] + items [j][0];
            }
        }
        int numOfPersons, maxRes = 0; cin >> numOfPersons;
        for(int i = 0; i < numOfPersons; i++){
            int weightMax;
            cin >> weightMax;
            maxRes += dp [weightMax];
        }
        cout << maxRes << endl;
    }
    return 0;
}