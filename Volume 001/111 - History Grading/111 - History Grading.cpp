#include <iostream>
#include <stdio.h>
using namespace std;

int search(int arr[], int searched, int len){
    for(int i = 0; i < len; i++) if(arr[i] == searched) return i;
}

int count(int arr[], int defArr[], int len){
    int currLen[len];
    for(int i = 0; i < len; i++) currLen[i] = 1;
    int maxVal = 0;
    for(int i = 1; i < len; i++){
        for(int j = 0; j < i; j++){
            int left = search(defArr, arr[j], len);
            int right = search(defArr, arr[i], len);
            if(left < right && currLen[i] < currLen[j] + 1) currLen[i] = currLen[j] + 1;
        }
    }
    for(int i = 0; i < len; i++) maxVal = max(maxVal, currLen[i]);
    return maxVal;
}

int main(){
    int len; cin >> len;
    int def[len];
    for(int i = 0; i < len; i++) {
        int temp; cin >> temp;
        def[temp - 1] = i + 1;
    }
    //for(int i = 0; i < len; i++) cout << def[i] << " ";
    //cout << endl;
    
    int currSeq[len], firstNum;
    while(cin >> firstNum){
        currSeq[firstNum - 1] = 1;
        for(int i = 1; i < len; i++) {
            int curr; cin >> curr;
            currSeq[curr - 1] = i + 1;
        }
        //for(int i = 0; i < len; i++) cout << currSeq[i] << " ";
        //cout << endl;
        cout << count (currSeq, def, len) << endl;
    }
    return 0;
}