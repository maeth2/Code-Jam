/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const ll nano = 1e9;
const ll M = 12 * 360 * 1e10;
const ll H = 3600 * 1e9;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

ll isValid(vector<ll> c){
    for(int i = 0; i < 12; i++){
        ll t = c[0] - c[1] - i * H;
        if(t % 11 == 0){
            t = (i * H + t / -11) % M;
            if(t < 0) continue;
            vector<ll> c1 = {t, t * 12, t * 720};
            for(int i = 0; i < 3; i++){
                ll shift = c[i] - c1[i];
                if((c1[0] + shift) % M == c[0] % M && (c1[1] + shift) % M == c[1] % M && (c1[2] + shift) % M == c[2] % M){
                    return t;
                }
            }
        }
    }
    return -1;
}

void solve(int cn){
    vector<ll> hands(3);
    for(int i = 0; i < 3; i++){
       cin >> hands[i];
    }
    ll ah, as, am, an;
    sort(hands.begin(), hands.end()); 
    do{
        ll t = isValid(hands);
        if(t != -1){
            an = t % nano;
            t /= nano;
            as = t % 60;
            t /= 60;
            am = t % 60;
            t /= 60;
            ah = t % 60;
            break;
        }
    }while(next_permutation(hands.begin(), hands.end()));
    
    cout << "Case #" << cn << ": " << ah << " " << am << " " << as << " " << an << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve(i + 1);
    }
    return 0;
}