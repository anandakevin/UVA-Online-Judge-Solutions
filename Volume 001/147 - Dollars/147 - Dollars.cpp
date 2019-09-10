#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int change[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    long long ttlWays[30001];
    for(int i = 0; i < 30001; i++) ttlWays[i] = 0;
    ttlWays[0] = 1;
    for(int i = 0; i < 11; i++){
        for(int j = change[i]; j < 30001; j++) ttlWays[j] += ttlWays[j - change[i]];
    }
    float num;
    cout << fixed << setprecision(2);
    do{
        cin >> num; if(num == 0) break;
        int newNum = (num * 100);
        if(newNum % 5 != 0) newNum += 1;
        cout << setw(6) << right << num << setw(17) << right << ttlWays[newNum] << endl;
    } while (num != 0);
    return 0;
}
