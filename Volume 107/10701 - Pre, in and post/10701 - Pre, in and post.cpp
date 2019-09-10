#include <iostream>
#include <vector>
using namespace std;

struct node{
    char value;
    int left, right; // ini index, bukan value
};

int findInIdx(string in, char pre){
    for(int i = 0; in.length(); i++) {
        if(in[i] == pre) return i;
    }
    return -1;
}

int findTreeIdx(vector<node> tree, char in){
    for(int i = 0; i < (int)tree.size(); i++){
        if(tree[i].value == in) return i;
    }
    return -1;
}

node createNode(char value){
    node temp;
    temp.value = value;
    temp.left = temp.right = -1;
    return temp;
}

void constructTree(vector <node> &tree, string in, char curr, int loInIdx, int midInIdx, int hiInIdx){
    if((int)tree.size() == 0) tree.push_back(createNode(curr));
    else{
        int inIdx = findInIdx(in, curr);
        int midTreeIdx = findTreeIdx(tree, in[midInIdx]);
        if(inIdx < midInIdx){
            if(tree[midTreeIdx].left == -1){
                tree.push_back(createNode(curr));
                int currTreeIdx = findTreeIdx(tree, curr);
                tree[midTreeIdx].left = currTreeIdx;
            }
            else
            constructTree(tree, in, curr, loInIdx, findInIdx(in, tree[tree[midTreeIdx].left].value), midInIdx - 1);
        }
        else if(inIdx > midInIdx){
            if(tree[midTreeIdx].right == -1){
                tree.push_back(createNode(curr));
                int currTreeIdx = findTreeIdx(tree, curr);
                tree[midTreeIdx].right = currTreeIdx;
            }
            else
            constructTree(tree, in, curr, midInIdx + 1, findInIdx(in, tree[tree[midTreeIdx].right].value), hiInIdx);
        }
    }
}

void getPostOrder(vector<node> tree, int pos){
    if(pos >= tree.size()) return;
    if(tree[pos].left != -1) getPostOrder(tree, tree[pos].left);
    if(tree[pos].right != -1) getPostOrder(tree, tree[pos].right);
    cout << tree[pos].value;
}

int main(){
    string pre, in, reg; //preorder, inorder, regular
    vector <node> tree;
    int rep, len;
    while(cin >> rep){
        for(int i = 0; i < rep; i++){
            cin >> len >> pre >> in;
            int midIdx;
            midIdx = findInIdx(in, pre[0]);
            for(int i = 0; i < (int)pre.length(); i++) {
                constructTree(tree, in, pre[i], 0, midIdx, in.length());
            }
            getPostOrder(tree, 0);
            cout << endl;
            tree.clear();
        }
    }
    return 0;
}