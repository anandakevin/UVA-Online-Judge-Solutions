#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct node{
    int price, flavour;
};

int n, x, t, k, maxDimsum;
double maxPrice;
node dimsum[101];
double memo[1001][21][101];

double solve(int ttlPrice, int ttlDimsum, int ttlLeft){
    int currDimsum = k - ttlLeft;
    if(ttlPrice > maxPrice || ttlDimsum > maxDimsum) return -20000;
    //cout << "masuk " << ttlPrice << " " << ttlDimsum << " " << ttlLeft << endl;
    if(ttlPrice == maxPrice || ttlDimsum == maxDimsum || ttlLeft == 0) return 0;
    if(memo[ttlPrice][ttlDimsum][ttlLeft] != -1) return memo[ttlPrice][ttlDimsum][ttlLeft];
    //cout << "kembaliin " << ttlPrice << " " << ttlDimsum << " " << ttlLeft << " " << flavorVal << endl;
    return memo[ttlPrice][ttlDimsum][ttlLeft] = max(solve(ttlPrice + dimsum[currDimsum].price, ttlDimsum + 1, ttlLeft - 1) + dimsum[currDimsum].flavour, 
           max((solve(ttlPrice + (2 * dimsum[currDimsum].price), ttlDimsum + 2, ttlLeft - 1) + (dimsum[currDimsum].flavour * 2)), 
           solve(ttlPrice, ttlDimsum, ttlLeft - 1)));
}

void reset(){
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 21; j++){
            for(int k = 0; k < 101; k++) memo[i][j][k] = -1;
        }
    }
}

int main(){
    while((cin >> n >> x >> t >> k) && (n || x || t || k)){
        reset();
        for(int i = 0; i < k; i++){
            maxPrice = (x * (n + 1) + 1e-6)/ (1.1) - (n + 1) * t;
            maxDimsum = 2 * (n + 1);
            int ttl = 0, temp;
            cin >> dimsum[i].price;
            for(int j = 0; j < (n + 1); j++) {
                cin >> temp; ttl += temp;
            }
            dimsum[i].flavour = ttl;
        }
        cout << fixed << setprecision(2) << solve(0, 0, k) / (n + 1) << endl;
    }
    
}