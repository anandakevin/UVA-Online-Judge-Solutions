#include <iostream>
using namespace std;

int main() {
    int rep, trains, trainSeq[50];
    cin >> rep;
    for(int i = 0; i < rep; i++){
        cin >> trains;
        int swaps = 0;
        for(int j = 0; j < trains; j++) cin >> trainSeq[j];
        for(int j = 0; j < trains; j++){
            for(int k = j+1; k < trains; k++){
                if(trainSeq[j] > trainSeq[k]){
                    int temp = trainSeq[k];
                    trainSeq[k] = trainSeq[j];
                    trainSeq[j] = temp;
                    swaps+=1;
                }
            }
        }
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
    cin.get();
    return 0;
}