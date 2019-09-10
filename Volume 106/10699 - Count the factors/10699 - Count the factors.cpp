#include <iostream>
using namespace std;

int numOfPrimeFactor[1000001];
bool isPrime[1000001];

int main(){
    for(int i = 1; i <= 1000001; i++) {
        isPrime[i] = true; numOfPrimeFactor[i] = 0;
    }
    for(int i = 2; i <= 1000001; i += ((i == 2) ? 1 : 2)){
        if(isPrime[i]) {
            numOfPrimeFactor[i] = 1;
            for(int k = 2 * i; k <= 1000001; k += i) {
                isPrime[k] = false;
                numOfPrimeFactor[k]++;
            }
        }
    }
    
    int inp;
    while(cin >> inp){
        if(inp == 0) break;
        cout << inp << " : " << numOfPrimeFactor[inp] << endl;
    }
}