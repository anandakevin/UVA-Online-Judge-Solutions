#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int inp;
    do{
        cin >> inp;
        int age[inp];
        for(int i = 0; i < inp; i++) cin >> age[i];
        sort(age, age+inp);
        for(int i = 0; i < inp; i++) {
            cout << age[i];
            if(i != (inp-1)) cout << " ";
        }
        if(inp != 0) cout << endl;
    } while(inp != 0);
    return 0;
}