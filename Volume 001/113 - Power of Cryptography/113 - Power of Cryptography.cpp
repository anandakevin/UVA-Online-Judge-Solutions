#include <iostream>
#include <string.h>
using namespace std;

long long getUp(int num){
    string temp = to_string(num);
    int idx = -1;
    for(int i = 0; i < temp.length(); i++){
        if((temp[i] - '0') % 2) {
            idx = i; break;
        }
    }
    string res = "";
    for(int i = 0; i < idx; i++) res += temp[i];
    int lowestNum = 0;
    while(lowestNum < (temp[idx] - '0')) lowestNum += 2;
    res += (lowestNum + '0');
    for(int i = idx; i < temp.length(); i++) res += "0";
    int resNum = stoi(res);
    return resNum - num;
}

long long getDown(int num){
    string temp = to_string(num);
    int idx = -1;
    for(int i = 0; i < temp.length(); i++){
        if((temp[i] - '0') % 2) {
            idx = i; break;
        }
    }
    string res = "";
    for(int i = 0; i < idx; i++) res += temp[i];
    int highestNum = 10;
    while(highestNum > (temp[idx] - '0')) highestNum -= 2;
    res += (highestNum + '0');
    for(int i = idx; i < temp.length(); i++) res += "0";
    int resNum = stoi(res);
    return resNum - num;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        long long num; cin >> num;
        cout << "Case #" << i << ": " << min(getDown(num), getUp(num)) << endl;
    }
}