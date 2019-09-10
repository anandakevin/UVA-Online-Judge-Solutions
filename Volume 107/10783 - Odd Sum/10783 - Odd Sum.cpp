#include <iostream>
using namespace std;

int main() {
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++) {
        int a, b, sum = 0; cin >> a >> b;
        if(a % 2 == 0) a += 1;
        if(b % 2 == 0) b -= 1;
        for(int j = a; j <= b; j += 2) sum += j;
        cout << "Case " << i << ": " << sum << endl;
    }
}