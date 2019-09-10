#include <iostream>
using namespace std;

int stackNum[1001], queueNum[1001], prQueueNum[1001];

void popAll(){
    for(int i = 0; i < 1001; i++) stackNum[i] = -1;
    for(int i = 0; i < 1001; i++) queueNum[i] = -1;
    for(int i = 0; i < 1001; i++) prQueueNum[i] = -1;
}

bool popStack(int num, int &ct){
    if(stackNum[ct - 1] == num && ct != 0){
        stackNum[ct - 1] = -1;
        ct--;
        return true;
    }
    else return false;
}

void moveQueue(int chc, int ct, int stIdx){
    if(chc == 1) for(int i = stIdx; i < ct; i++) queueNum[i] = queueNum[i+1];
    else if (chc == 2) for(int i = stIdx; i < ct; i++) prQueueNum[i] = prQueueNum[i+1];
}

bool popQueue(int num, int &ct){
    if(queueNum[0] == num && ct != 0){
        queueNum[0] = -1;
        ct--;
        moveQueue(1, ct, 0);
        return true;
    }
    else return false;
}

bool popPrQueue(int num, int &ct){
    int idx = -1, max = -1;
    for(int i = 0; i < ct; i++){
        if(prQueueNum[i] > max) {
            max = prQueueNum[i];
            idx = i;
        }
    }
    if(max == num) {
        prQueueNum[idx] = -1;
        ct--;
        moveQueue(2, ct, idx);
        return true;
    }
    else return false;
}

void addPrQueue(int ct, int num){
    int i = -1;
    do{
        i++;
        if(prQueueNum[i] <= num) {
            for(int j = ct; j >= i; j--) prQueueNum[j + 1] = prQueueNum[j];
            prQueueNum[i] = num;
            break;
        }
        
    } while(prQueueNum[i] > num || prQueueNum[i] == -1);
}

void printContent(int chc, int ct){
    if(chc == 1){
        cout << "Stack: " << endl;
        for(int i = 0; i < ct; i++) cout << stackNum[i] << endl;
    }
    else if(chc == 2){
        cout << "Queue: " << endl;
        for(int i = 0; i < ct; i++) cout << queueNum[i] << endl;
    }
    else for(int i = 0; i < ct; i++) cout << prQueueNum[i] << endl;
}

int main(){
    int rep;
    while(cin >> rep){
        popAll();
        bool stack = true, queue = true, prQueue = true;
        int ctS = 0, ctQ = 0, ctP = 0;
        for(int i = 0; i < rep; i++){
            int cmd, num;
            cin >> cmd >> num;
            if(cmd == 1) {
                if(stack) stackNum[ctS++] = num;
                if(queue) queueNum[ctQ++] = num;
                if(prQueue) {
                    prQueueNum[ctP++] = num;
                    //addPrQueue(ctP, num);
                    // ctP++;
                }
            }
            else if(cmd == 2){
                if(stack) stack = popStack(num, ctS);
                if(queue) queue = popQueue(num, ctQ);
                if(prQueue) prQueue = popPrQueue(num, ctP);
            }
            // cout << "Iterate " << i + 1<< ": "<< endl;
            // if(prQueue) {
            //     printContent(3, ctP);
            //     cout << endl;
            // }
            // if(queue) {
            //     printContent(2, ctQ);
            //     cout << endl;
            // }
        }
        if(stack == true && queue == false && prQueue == false) cout << "stack" << endl;
        else if(stack == false && queue == true && prQueue == false) cout << "queue" << endl;
        else if(stack == false && queue == false && prQueue == true) cout << "priority queue" << endl;
        else if(stack == false && queue == false && prQueue == false) cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }
}
