#include <iostream>
#include <vector>
using namespace std;

int merge(int num[], int low, int mid, int high){
    int l = low, r = mid + 1;
    long swap = 0;
    int size = high - low + 1;
    int temp[size];
    int currIdx = 0;
    while(l <= mid - 1 && r <= high) {
        if(num[r] >= num[l]){
            //cout << num[l] << " ke " << num[r] << " --> " << l << " ke " << r << endl;
            temp[currIdx++] = num[l++];
            
        }
        else {
            temp[currIdx++] = num[r++];
            swap += (long) (mid - l) + 1;
        }
    }
    while(l <= mid) temp[currIdx++] = num[l++];
    while(r <= high) temp[currIdx++] = num[r++];
    for(int i = low, j = 0; i <= high; i++, j++) num[i] = temp[j];
    return swap;
}

int mergeSort(int num[], int low, int high){
   if(low >= high) return 0;
   int mid = low + (high - low) / 2;
   return mergeSort(num, low, mid) + mergeSort(num, mid + 1, high) + merge(num, low, mid, high);
}

int main(){
    int rep;
    while(cin >> rep){
        if(rep == 0) break;
        int num[rep];
        int ttl = 0;
        for(int i = 0; i < rep; i++) {
            cin >> num[ttl++];
        }
        //mergeSort(num, 0, ttl - 1);
        cout << mergeSort(num, 0, ttl - 1) << endl << endl;
        //for(int i = 0; i < ttl; i++) cout << num[i] << endl;
        cout << endl;
    }
}