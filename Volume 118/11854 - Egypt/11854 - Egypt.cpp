#include <iostream>
using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

string checkright(int a, int b, int c) {
    if(a*a + b*b == c*c) return "right\n";
    else return "wrong\n";
}

int main() {
    int a, b, c;
    while(cin >> a >> b >> c) {
        if(a == 0 && b == 0 && c == 0) break;
        int maxSide = max(a, b);
        maxSide = max(maxSide, c);
        if(maxSide == a) {
            cout << checkright(b, c, a);
        } else if(maxSide == b) {
            cout << checkright(a, c, b);
        } else if(maxSide == c) {
            cout << checkright(a, b, c);
        }
    };
}