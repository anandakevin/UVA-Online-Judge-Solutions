#include <iostream>
using namespace std;

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        string temp; cin >> temp;
        int num1 = 0, num2 = 0;
        if(temp.length() == 3){
            if(temp[0] == 'o') num1++;
            else if(temp[0] == 't') num2++;
            if(temp[1] == 'n') num1++;
            else if(temp[1] == 'w') num2++;
            if(temp[2] == 'e') num1++;
            else if(temp[2] == 'o') num2++;
            if(num1 > num2) cout << "1" << endl;
            else cout << "2" << endl;
        }
        else cout << "3" << endl;
    }
    return 0;
}