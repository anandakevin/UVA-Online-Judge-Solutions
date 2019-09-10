#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int ttlChambers, ttlNum;
    vector<int> nums;
    while(cin >> ttlChambers >> ttlNum){
        int mean = 0;
        cout << ttlChambers << " " << ttlNum << endl;
        for(int i = 0; i < ttlNum; i++) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
            mean += nums.at(nums.size()-1);
        }
        mean /= ttlChambers;
        int empty = ttlChambers*2 - ttlNum;
        for(int i = 0; i < empty; i++) nums.push_back(0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size(); i++) cout << nums[i] << " ";
        cout << endl << endl;
        nums.clear();
    }
}