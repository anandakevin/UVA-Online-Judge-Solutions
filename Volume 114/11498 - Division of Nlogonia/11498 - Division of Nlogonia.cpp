#include <iostream>
using namespace std;

int main(){
    int rep;
    do{
        cin >> rep;
        if(rep == 0) break;
        int orX, orY, coorX, coorY;
        cin >> orX >> orY;
        for(int i = 0; i < rep; i++){
            cin >> coorX >> coorY;
            if(coorX == orX || coorY == orY) cout << "divisa" << endl;
            else if(coorX > orX){
                if(coorY > orY) cout << "NE" << endl;
                else if(coorY < orY) cout << "SE" << endl;
            }
            else if(coorX < orX){
                if(coorY > orY) cout << "NO" << endl;
                else if(coorY < orY) cout << "SO" << endl;
            }
        }
    } while(rep != 0);
    return 0;
}