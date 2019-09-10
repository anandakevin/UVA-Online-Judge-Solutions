#include <iostream>
using namespace std;

int main(){
    int lines = 0;
    for(int i = 1;lines >= 0 ;i++){
        cin >> lines;
        if(lines < 0) break;
        int pastes = 0, currLines = 1;
        while(currLines < lines){
            if(currLines * 2 <= lines) {currLines *=2; pastes++;}
            else {currLines = lines; pastes++;}
        }
        cout << "Case " << i << ": " << pastes << endl;
    }
    return 0;
}