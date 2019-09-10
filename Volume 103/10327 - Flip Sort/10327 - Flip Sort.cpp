#include <iostream>
using namespace std;

void bubbleSort(int len, int arr[]){
    int ct = 0;
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(arr[i] > arr[j]) ct++;
        }
    }
    cout << "Minimum exchange operations : " << ct << endl;
}

int main() {
    int ttl;
    while(cin >> ttl){
        int nums[ttl];
        for(int i = 0; i < ttl; i++) cin >> nums[i];
        bubbleSort(ttl, nums);
    }
    return 0;
}