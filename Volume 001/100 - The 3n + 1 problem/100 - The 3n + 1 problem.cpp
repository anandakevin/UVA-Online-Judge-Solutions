#include <iostream>
using namespace std;

int ctTtl(int num){
    int ttl = 1;
    while(num != 1){
        if(num % 2 == 1) num = 3*num + 1;
        else num /= 2;
        ttl++;
    }
    return ttl;
}

int main() {
    int a, b;
    while(cin >> a >> b){
        int largest = 0;
        for(int i = min(a, b); i <= max(a, b);i++){
            int temp = ctTtl(i);
            if(temp > largest) largest = temp;
        }
        cout << a << " " << b << " " << largest << endl;
    }
    return 0;
}