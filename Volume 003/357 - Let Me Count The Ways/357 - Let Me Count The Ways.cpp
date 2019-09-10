#include <iostream>
using namespace std;

int main(){
    int num;
    int change[] = {1, 5, 10, 25, 50};
    long long ttlWays[30001];
    for(int i = 0; i < 30001; i++) ttlWays[i] = 0;
    ttlWays[0] = 1;
    for(int i = 0; i < 5; i++){
        for(int j = change[i]; j < 30001; j++) ttlWays[j] += ttlWays[j - change[i]];
    }
    while(cin >> num){
        if(ttlWays[num] == 1) cout << "There is only 1 way to produce " << num << " cents change." << endl;
        else cout << "There are " << ttlWays[num] << " ways to produce " << num << " cents change." << endl;
    }
    return 0;
}
