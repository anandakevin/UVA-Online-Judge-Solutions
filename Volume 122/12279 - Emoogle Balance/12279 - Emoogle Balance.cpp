#include <iostream>
using namespace std;

int main(){
    int rep, idx = 0;
    do{
        cin >> rep;
        if(rep == 0) break;
        int bal = 0;
        for(int i = 0; i < rep; i++){
            int temp; cin >> temp;
            if(temp > 0) bal++;
            else bal--;
        }
        cout << "Case " << ++idx << ": " << bal << endl;
    } while(rep != 0);
    return 0;
}