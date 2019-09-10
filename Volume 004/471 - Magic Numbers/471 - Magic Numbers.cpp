#include <iostream>
using namespace std;

const long long theLimit = 9999999999;

bool checkDouble(long long num){
    string theDigits;
    theDigits = to_string(num);
    for(int i = 0; i < theDigits.length(); i++){
        for(int j = i+1; j < theDigits.length(); j++) {
            if(theDigits[i] == theDigits[j]) return false;
        }
    }
    return true;
}

int main() {
    int rep; cin >> rep;
    long long n, m;
    for(int i = 0; i < rep; i++){
        cin >> n;
        checkDouble(n);
        for(int i = 1; i*n <= theLimit; i++){
            m = i*n;
            if(checkDouble(i) && checkDouble(m)){
                cout << m << " / " << i << " = " << n << endl;
            }
        }
        if(i != rep - 1) cout << endl;
    }
    return 0;
}