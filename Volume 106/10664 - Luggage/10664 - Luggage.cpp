#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void countAbleTo(vector <int> nums, int half){
    int res[4001];
    for(int i = 0; i <= half; i++) res[i] = 0;
    for(int i = 0; i < (int)nums.size(); i++){
        for(int j = half; j > 0; j--){
            if(nums[i] <= j) res[j] = max(res[j], nums[i] + res[j - nums[i]]);
        }
    }
    if(half == res[half]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int rep; cin >> rep;
    string nums;
    getline(cin, nums);
    for(int i = 0; i < rep; i++){
        getline(cin, nums);
        stringstream ss;
        vector <int> theNumbers;
        ss << nums;
        int temp, sum = 0;
        while(ss >> temp){
            theNumbers.push_back(temp);
            sum += temp;
        }
        if(sum % 2 == 0) countAbleTo(theNumbers, sum /2);
        else cout << "NO" << endl;
    }
    return 0;
}