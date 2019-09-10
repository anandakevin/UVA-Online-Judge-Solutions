#include <iostream>
using namespace std;

int main(){
    string inp;
    int i = 0;
    do{
        string temp;
        cin >> inp;
        if(inp == "#") break;
        else if(inp == "HELLO") temp = "ENGLISH";
        else if(inp == "HOLA") temp = "SPANISH";
        else if(inp == "HALLO") temp = "GERMAN";
        else if(inp == "BONJOUR") temp = "FRENCH";
        else if (inp == "CIAO") temp = "ITALIAN";
        else if (inp == "ZDRAVSTVUJTE") temp = "RUSSIAN";
        else temp = "UNKNOWN";
        cout << "Case " << ++i << ": " << temp << endl;
    } while(inp != "#");
    return 0;
}