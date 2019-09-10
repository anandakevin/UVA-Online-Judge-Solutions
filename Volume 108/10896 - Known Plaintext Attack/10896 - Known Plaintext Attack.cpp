#include <iostream>
#include <vector>
using namespace std;

vector <char> op;

int main(){
    int rep; cin >> rep;
    string in;
    for(int i = 0; i < rep; i++){
        //op.push_back('(');
        getline(cin, in);
        string pre = "";
        for(int i = 0; i < in.length(); i++){
            cout << i << " ";
            if((in[i] >= 'a' && in[i] <= 'z') || in[i] >= 'A' && in[i] <= 'Z'){
                cout << in[i];
            }
            else if(in[i] != ')'){
                while(op[op.size() - 1] != '('){
                    cout << op[op.size() - 1];
                    op.pop_back();
                }
                op.pop_back();
            }
            else{
                op.push_back(in[i]);
            }
        }
    }
    return 0;
}