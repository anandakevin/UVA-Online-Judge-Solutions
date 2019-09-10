#include <iostream>
#include <vector>
using namespace std;

int res[1121][15];
bool isPrime[1121];

int main(){
    for(int i = 1; i <= 1120; i++){
        for(int j = 0; j <= 14; j++) res[i][j] = 0;
        isPrime[i] = true;
    }
    res[0][0] = 1;
    int ttlPrime = 0;
    vector<int> primes;
    for(int i = 2;  i <= 1120; i += ((i == 2) ? 1 : 2)){ 
        if(isPrime[i]){
            ttlPrime++;
            primes.push_back(i);
            for(int j = i * i; j <= 1120; j += i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 0; i < (int)primes.size(); i++) {
        for(int j = 1120; j >= 0; j--){
            for(int k = 1; k <= 14; k++){
                if(j - primes[i] == 0){
                    res[j][k] += res[j - primes[i]][k - 1];
                }
                else if(j - primes[i] > 0 && res[j - primes[i]][k - 1] > 0){
                    res[j][k] += res[j - primes[i]][k - 1];
                }
            }
        }
    }
    int primeNum, ttlNum;
    while(cin >> primeNum >> ttlNum){
        if(primeNum == 0 && ttlNum == 0) break;
        cout << res[primeNum][ttlNum] << endl;
    }
}