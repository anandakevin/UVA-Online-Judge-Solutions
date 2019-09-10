#include <iostream>
using namespace std;

struct people{
    string name;
    int giveDiff;
};

void reset(people ppl[]){
    for(int i = 0; i < 11; i++){
        ppl[i].name = "";
        ppl[i].giveDiff = 0;
    }
}

int findPeople(people ppl[], string name, int ttlPeople){
    for(int i = 0; i < ttlPeople; i++){
        if(ppl[i].name == name) return i;
    }
    return -1;
}

int main(){
    int numOfPeople;
    people ppl[11];
    while(cin >> numOfPeople){
        reset(ppl);
        for(int i = 0; i < numOfPeople; i++) cin >> ppl[i].name;
        for(int i = 0; i < numOfPeople; i++){
            string currName; cin >> currName;
            int give, ttlPplGiven;
            cin >> give >> ttlPplGiven;
            int currIdx = findPeople(ppl, currName, numOfPeople);
            //ppl[currIdx].giveDiff += give;
            if(ttlPplGiven != 0) {
                ppl[currIdx].giveDiff -= (give - give % ttlPplGiven);
                for(int j = 0; j < ttlPplGiven; j++){
                    string currGiven; cin >> currGiven;
                    int currGivenIdx = findPeople(ppl, currGiven, numOfPeople);
                    ppl[currGivenIdx].giveDiff += give/ttlPplGiven;
                }
            }
        }
        for(int i = 0; i < numOfPeople; i++) cout << ppl[i].name << " " << ppl[i].giveDiff << endl;
        cout << endl;
    }
    return 0;
}
