#include <iostream>
using namespace std;

int main() {
    int rep; cin >> rep;
    int total = 0;
    while(rep--) {
        string inp; cin >> inp;
        if(inp == "donate") {
            int temp; cin >> temp;
            total += temp;
        } else if(inp == "report") cout << total << endl;
    }
}