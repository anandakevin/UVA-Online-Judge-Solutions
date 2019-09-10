#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int sal[3];
        cin >> sal[0] >> sal[1] >> sal[2];
        sort(sal, sal + 3);
        cout << "Case " << i + 1 << ": " << sal[1] << endl;
    }
    return 0;
}