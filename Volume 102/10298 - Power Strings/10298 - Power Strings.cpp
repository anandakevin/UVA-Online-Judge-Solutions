//Ini cara KMP
#include <iostream>
#include <math.h>
using namespace std;

int f[1000001];

void calculateFailureTable(string str){
    int len = 0, i = 1;
    f[0] = 0;
    while(i < (int)str.length()){
        if(str[i] == str[len]) f[i++] = ++len;
        else{
            if(len != 0) len = f[len - 1];
            else f[i++] = 0;
        }
    }
}

int checkPow(string inp){
    int lastIdx = inp.length() - 1;
    int firstIdx = f[lastIdx] - 1;
    if(firstIdx == -1 || inp[firstIdx] != inp[lastIdx]) firstIdx = 0;
    if(inp.length() == 2 && inp[0] != inp[1]) lastIdx++;
    int len = lastIdx - firstIdx;
    if(len == 0) len = inp.length();
    return (int)inp.length() / len;
}

int main()
{
    string inp;
    while(cin >> inp && inp != "."){
        calculateFailureTable(inp);
        cout << checkPow(inp) << endl;
    }
    return 0;
}