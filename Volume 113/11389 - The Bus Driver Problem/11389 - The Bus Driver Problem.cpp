#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int numOfDriver, maxHours, extraPrice;
    do{
        cin >> numOfDriver >> maxHours >> extraPrice;
        if(numOfDriver == 0 && maxHours == 0 && extraPrice == 0) break;
        int mDist[numOfDriver], eDist[numOfDriver];
        for(int i = 0; i < numOfDriver; i++) cin >> mDist[i];
        for(int i = 0; i < numOfDriver; i++) cin >> eDist[i];
        sort(mDist, mDist + numOfDriver);
        sort(eDist, eDist + numOfDriver);
        int overTime = 0;
        for(int i = 0; i < numOfDriver; i++) {
            if((mDist[i] + eDist[numOfDriver - 1 - i]) > maxHours) 
                overTime += (mDist[i] + eDist[numOfDriver - 1 - i]) - maxHours;
        }
        cout << overTime*extraPrice << endl;
    } while(numOfDriver != 0 || maxHours != 0 || extraPrice != 0);
    return 0;
}