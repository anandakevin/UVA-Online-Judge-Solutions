#include <iostream>
using namespace std;

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int toPay, ttlCoin; cin >> toPay >> ttlCoin;
        int coins[ttlCoin];
        for(int j = 0; j < ttlCoin; j++) cin >> coins[j];
        int ctCoins[20001];
        for(int j = 0; j <= 20000; j++) ctCoins[j] = 20000;
        ctCoins[0] = 0;
        for(int j = 0; j < ttlCoin; j++){
            for(int k = 20000; k >= 0; k--) {
                if(k - coins[j] >= 0) ctCoins[k] = min(ctCoins[k - coins[j]] + 1, ctCoins[k]);
            }
        }
        int resNum = 0;
        int coinCt = 20000;
        for(int j = toPay; j < 20001; j++){
            if(ctCoins[j] < 20000) {
                resNum = j;
                coinCt = ctCoins[j];
                break;
            }
        }
        cout << resNum << " " << coinCt << endl;
    }
}