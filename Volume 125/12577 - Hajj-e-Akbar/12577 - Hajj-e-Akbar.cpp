#include <iostream>
using namespace std;

int main(){
    string temp;
    int i = 0;
    do{
        cin >> temp;
        if(temp == "*") break;
        else if(temp == "Umrah") cout << "Case " << ++i << ": Hajj-e-Asghar" << endl;
        else cout << "Case " << ++i << ": Hajj-e-Akbar" << endl;
        } while(temp != "*");
    return 0;
}