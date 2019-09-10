#include <iostream>
#include <algorithm>
using namespace std;

long int getMin(long int a,long int b){
    if(a > b) return b;
    else return a;
}

long int getMax(long int a,long int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int rep;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        int numOfProd, numOfCust;
        cin >> numOfProd >> numOfCust;
        long int prodPrice[numOfProd], custPrice[numOfCust];
        for(int j = 0; j < numOfProd; j++) cin >> prodPrice[j];
        for(int j = 0; j < numOfCust; j++) cin >> custPrice[j];
        sort(prodPrice, prodPrice + numOfProd);
        sort(custPrice, custPrice + numOfCust);
        int numOfAngryPeople = 0;
        long int okayPrice = 0;
        for(int j = -1; j < numOfProd; j++){
            int temp = 0;
            long int num;
            if(j == -1) num = 0;
            else num = prodPrice[j];
            for(int k = 0; k < numOfProd; k++) if(prodPrice[k] > num) temp++; // producer
            for(int k = 0; k < numOfCust; k++) if(custPrice[k] < num) temp++; // customer
            if(j == -1) {numOfAngryPeople = temp; okayPrice = 0;}
            else if(numOfAngryPeople > temp){
                okayPrice = num;
                numOfAngryPeople = temp;
            }
        }
        for(int j = 0; j < numOfCust; j++){
            int temp = 0;
            long int num = custPrice[j];
            for(int k = 0; k < numOfProd; k++) if(prodPrice[k] > num) temp++; // producer
            for(int k = 0; k < numOfCust; k++) if(custPrice[k] < num) temp++; // customer
            if(numOfAngryPeople > temp){
                okayPrice = num;
                numOfAngryPeople = temp;
            }
        }
        cout << okayPrice << " " << numOfAngryPeople << endl;
    }
    return 0;
}