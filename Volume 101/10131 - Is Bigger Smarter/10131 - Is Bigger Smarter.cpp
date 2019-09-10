#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data{
    int w, iq, idx;
};

struct byIQ { 
    bool operator()(data const &a, data const &b) const noexcept { 
        return a.iq < b.iq;
    }
};

int main(){
    int w, i, idx = 0;
    vector <data> elephants;
    while(cin >> w >> iq){
        data currEl = {w, iq, ++idx};
        elephants.push_back(currEl);
    }
    sort(data.begin(), data.end(), byIQ());
    for(int i = 0; i < elephants.size(); i++)
    //for(int i = 0; i < elephants.size(); i++){
        //    if(!(elephants[i].w == elephants[i-1].w) && !(elephants[i].iq == elephants[i-1].iq)) cout << "
    //}
}