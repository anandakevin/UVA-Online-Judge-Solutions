#include <iostream>
#include <malloc.h>
#include <vector>
using namespace std;

struct node{
    int num, nextNum;
    bool visited;
};

struct queue{
    int num;
    queue *next, *prev;
};

node getNode(int num, int nextNum){
    node temp;
    temp.num = num;
    temp.nextNum = nextNum;
    temp.visited = false;
    return temp;
}

int getIdx(vector<node> con[], int num){
    for(int i = 0; i < 31; i++){
        if(con[i].size() != 0 && con[i][0].num == num) return i;
    }
    return -1;
}

void addCon(vector<node> con[], int num1, int num2, int &ttl) 
{
    int idx1 = getIdx(con, num1);
    if(idx1 == -1) {
        con[ttl++].push_back(getNode(num1, num2));
    }
    else{
        con[idx1].push_back(getNode(num1, num2));
    }
    int idx2 = getIdx(con, num2);
    if(idx2 == -1) {
        con[ttl++].push_back(getNode(num2, num1));
    }
    else{
        con[idx2].push_back(getNode(num2, num1));
    }
} 

void resetValue(vector<node> con[]){
    for(int i = 0; i < 31; i++){
        for(int j = 0; j < con[i].size(); j++) con[i][j].visited = false;
    }
}

void resetAll(vector<node> con[]){
    for(int i = 0; i < 31; i++) con[i].clear();
}

void printGraph(vector<node> con[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex " << con[v][0].num << "\n head "; 
        for (int i = 0; i < con[v].size(); i++) cout << " -> " << con[v][i].nextNum; 
        cout << endl;
    } 
} 

queue *createNode(){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp -> next = temp -> prev = NULL;
    return temp;
}

queue *createNode(int val){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp -> num = val;
    temp -> next = temp -> prev = NULL;
    return temp;
}

queue *createNode(queue* del){
    queue *temp = (queue*)malloc(sizeof(queue));
    temp -> num = del -> num;
    temp -> next = temp -> prev = NULL;
    return temp;
}

void pushback(queue *&head, queue *&tail, int idx){
    if(!tail){
        head = tail = createNode(idx);
    }
    else{
        queue *temp = createNode(idx);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

queue * removeQueue(queue *&queueHead, queue *&queueTail){
    if(!queueHead) return NULL;
    else{
        queue *temp;
        if(queueHead == queueTail){
            temp = createNode(queueHead);
            free(queueHead);
            queueHead = queueTail = NULL;
        }
        else{
            temp = createNode(queueHead);
            queueHead = queueHead -> next;
            free(queueHead -> prev);
            queueHead -> prev = NULL;
        }
        return temp;
    }
}

void enQueue(vector<node> con[], int idx, queue *&head, queue *&tail, int ttl){
    for(int i = 0; i < con[idx].size(); i++){
        int newIdx = getIdx(con, con[idx][i].nextNum);
        if(con[newIdx][0].visited == false){
            con[newIdx][0].visited = true;
            con[idx][i].visited = true;
            pushback(head, tail, newIdx);
        }
    }
}

void visit(vector<node> con[], int from, int ttl, int ttlNode){
    queue *queueHead = NULL, *queueTail = NULL, *tempHead = NULL, *tempTail = NULL;
    int idx = getIdx(con, from);
    if(idx == -1) return;
    con[idx][0].visited = true;
    pushback(queueHead, queueTail, idx);
    while(ttl > 0){
        while(queueHead){
            if(queueHead) idx = queueHead -> num;
            enQueue(con, idx, tempHead, tempTail, ttl);
            queue * curr = removeQueue(queueHead, queueTail);
        }
        if(!queueTail){
            queueHead = tempHead;
            queueTail = tempTail;
        }
        else{
            queueTail -> next = tempHead;
            tempHead -> prev = queueTail;
            queueTail = tempTail;
        }
        tempTail = tempHead = NULL;
        ttl--;
    }
    return;
}

int ctUr(vector<node> con[], int ttlNode){
    int ctTrue = 0;
    for(int i = 0; i < ttlNode; i++){
        if(con[i][0].visited == true) ctTrue++;
    }
    return ttlNode - ctTrue;
}

int main(){
    int conCt, ct = 0;
    while(cin >> conCt){
        if(conCt == 0) break;
        vector<node> con[31];
        resetAll(con);
        int ttlNode = 0;
        resetValue(con);
        for(int i = 0; i < conCt; i++){
            int num1, num2; 
            cin >> num1 >> num2;
            addCon(con, num1, num2, ttlNode);
        }
        int from, ttl;
        while(cin >> from >> ttl){
            if(from == 0 && ttl == 0) break;
            resetValue(con);
            ct++;
            visit(con, from, ttl, ttlNode);
            cout << "Case " << ct << ": " << ctUr(con, ttlNode) << 
            " nodes not reachable from node " << from <<
             " with TTL = " << ttl << "." << endl;
        }
    }
    return 0;
}