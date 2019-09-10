#include <iostream>
using namespace std;

int main(){
    int rep; cin >> rep; 
    for(int i = 0; i < rep; i++){
        int l, h, w;
        cin >> l >> h >> w;
        if(l > 20 || h > 20 || w > 20) cout << "Case " << i + 1 << ": bad" << endl;
        else cout << "Case " << i + 1 << ": good" << endl;
    }
    return 0;
}