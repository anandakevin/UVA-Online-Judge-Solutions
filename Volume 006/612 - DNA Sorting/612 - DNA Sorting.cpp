#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct strings{
    int sortedness = 0;
    char theString[51];
};

int getSortedness(char theString[]){
    int num = 0;
    for(int i = 0; i < strlen(theString); i++){
        for(int j = i+1; j < strlen(theString); j++){
            if(theString[i] > theString[j]) num++;
        }
    }
    return num;
}

bool compareSortedness(strings prev, strings next){ return prev.sortedness < next.sortedness; }

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int len, ttl;
        cin >> len; cin >> ttl;
        strings newString[ttl];
        for(int j = 0; j < ttl; j++) cin >> newString[j].theString;
        for(int j = 0; j < ttl; j++) newString[j].sortedness = getSortedness(newString[j].theString);
        stable_sort(newString, newString+ttl, compareSortedness);
        for(int j = 0; j < ttl; j++) cout << newString[j].theString << endl;
        if(i != rep - 1) cout << endl;
    }
}