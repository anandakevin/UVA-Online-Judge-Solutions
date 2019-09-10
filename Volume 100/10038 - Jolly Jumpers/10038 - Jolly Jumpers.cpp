#include <iostream>
using namespace std;

bool jolly[3001];

void checkTF(int a, int b){
    int diff = max(a, b) - min(a, b);
    jolly[diff - 1] = true;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void reset(){
    for(int i = 0; i < 3001; i++) jolly[i] = false;
}

bool checkJolly(int rep){
    bool check = true;
    for(int i = 0; i < rep; i++) {
        if(jolly[i] == false) check = false;
    }
    return check;
}

int main(){
    int rep, a, b;
    while(cin >> rep){
        cin >> a;
        reset();
        for(int i = 0; i < rep - 1; i++) {
            cin >> b;
            checkTF(a, b);
            swap(a, b);
        }
        if(checkJolly(rep - 1)) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
    return 0;
}