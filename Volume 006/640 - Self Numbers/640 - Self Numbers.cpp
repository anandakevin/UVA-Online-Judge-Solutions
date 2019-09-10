#include <iostream>
#include <string> 
using namespace std;

bool isSelf[1000002];

int ctTtl(int num){
    int temp = num;
    while(temp > 0) {
        num += temp % 10;
        temp /= 10;
    }
    return num;
}

int main(){
    for(int i = 1; i < 1000001; i++){
        isSelf[i] = true;
    }
    for(int i = 1; i < 1000001; i++){
        int curr = i;
        if(isSelf[i]) cout << curr << endl;
        curr = ctTtl(curr);
        isSelf[curr] = false;
    }
    return 0;
}