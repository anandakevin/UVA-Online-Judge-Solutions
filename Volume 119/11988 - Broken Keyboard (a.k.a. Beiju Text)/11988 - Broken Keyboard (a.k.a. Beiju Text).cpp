#include <iostream>
#include <malloc.h>
using namespace std;
#include <vector>

struct node{
    char val;
    node *next, *prev;
};

node * createNode(int val){
    node *temp = (node*)malloc(sizeof(node));
    temp -> val = val;
    temp -> next = temp -> prev = NULL;
    return temp;
}

node * createNode(){
    node *temp = (node*)malloc(sizeof(node));
    temp -> next = temp -> prev = NULL;
    return temp;
}

node * pushback(node *&head, node *&tail, int val){
    node *temp = createNode(val);
    if(!tail){
        head = tail = temp;
    }
    else{
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    return tail;
}

node * pushfront(node *&head, node *&tail, int val){
    node *temp = createNode(val);
    if(!head){
        head = tail = temp;
    }
    else{
        head -> prev = temp;
        temp -> next = head;
        head = temp;
    }
    return head;
}

void print(node *head, node *tail){
    for(node *curr = head; curr != NULL; curr = curr -> next) cout << curr -> val;
}

void merge(node *& head, node *& tail, node *& tempHead, node *& tempTail){
    if(tempHead != NULL){
        if(!head){
            head = tempHead;
            tail = tempTail;
            tempHead = tempTail = NULL;
        }
        else{
            tempTail -> next = head;
            head -> prev = tempTail;
            head = tempHead;
            tempHead = tempTail = NULL;
        }
    }
}

void popBack(node *&head, node *&tail){
    if(head == tail){
        free(tail); head = tail = NULL;
    }
    else{
        tail = tail -> prev;
        free(tail -> next);
    }

}

void popAll(node *&head, node *tail){
    while(head){
        popBack(head, tail);
    }
}

int main(){
    string inp, out;
    bool back;
    while(getline(cin, inp)){        
        node *tempHead = NULL, *tempTail = NULL, *head = NULL, *tail = NULL;
        back = true;
        for(int i = 0; i < (int) inp.length(); i++){
            if(inp[i] == '[') {
                if(back == false) merge(head, tail, tempHead, tempTail);
                else back = false;
            }
            else if(inp[i] == ']') {
                if(back == false) merge(head, tail, tempHead, tempTail);
                back = true;
            }
            else{
                if(back == false) pushback(tempHead, tempTail, inp[i]);
                else pushback(head, tail, inp[i]);
            }
        }
        if(back == false) merge(head, tail, tempHead, tempTail);
        print(head, tail);
        cout << endl;
    }
    return 0;
}
