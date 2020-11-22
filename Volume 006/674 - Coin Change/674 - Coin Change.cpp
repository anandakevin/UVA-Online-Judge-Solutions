#include <iostream>
#include <cstring>
using namespace std;

int coins[5] = {1, 5, 10, 25, 50};
int ways[7490][5];

/*
long long splitcoin(int amountleft) {
    if(amountleft < 0) {
        return 0;
    }
    if(ways[amountleft] != 0) return ways[amountleft];
    else if(amountleft == 0) {
        cout << amountleft << " " << 1 << endl;
        return ways[amountleft] = 1;
    }
    else {
        long long total = splitcoin(amountleft - 50) + splitcoin(amountleft - 25) + splitcoin(amountleft - 10) + splitcoin(amountleft - 5) + splitcoin(amountleft - 1);
        cout << amountleft << " " << total << endl;
        return ways[amountleft] = total;
    }
}
*/
//function ini untuk yang 5 + 5 + 1 dan 5 + 1 + 5 terhitung beda

int count(int money, int index) {
    if(money == 0) return 1;
    if(ways[money][index] != -1) return ways[money][index];
    int total = 0;
    for(int i = index; i < 5; i++) {
        if(money >= coins[i]) total += count(money - coins[i], i);
    }
    return ways[money][index] = total;
}

int main() {
    int currVal;
    memset(ways, -1, sizeof ways);
    while(cin >> currVal) {
        cout << count(currVal, 0) << endl;
    }
    return 0;
}

