#include <iostream>
using namespace std;

int findDiff(int a, int b){
    return max(a, b) - min(a, b);
}

int main(){
    int a, b, c, d;
    do{
        cin >> a >> b >> c >> d;
        int degree = 720;
        degree += findDiff(a, b)*9;
        degree += findDiff(b, c)*9;
        degree += findDiff(c, d)*9;
        cout << degree << endl;
    } while(a != 0 || b != 0 || c != 0 || d != 0);
    
}