#include <iostream>
using namespace std;

int countHalfMax(int coins[], int ttlCoins, int half){
    int res[25001];
    for(int i = 0; i <= half; i++) res[i] = 0;
    for(int i = 0; i < ttlCoins; i++){
        for(int j = half; j > 0; j--){
            if(coins[i] <= j) res[j] = max(res[j], res[j - coins[i]] + coins[i]);
        }
    }
    return res[half];
}

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int numOfCoins; cin >> numOfCoins;
        int coins[numOfCoins], sum = 0;
        for(int j = 0; j < numOfCoins; j++) {
            int temp; cin >> temp;
            coins[j] = temp;
            sum += temp;
        }
        cout << sum - 2*countHalfMax(coins, numOfCoins, sum / 2) << endl;
    }
    return 0;
}