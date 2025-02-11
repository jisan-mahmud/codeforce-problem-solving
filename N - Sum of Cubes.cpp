#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout << fixed << setprecision(a);

bool isOk(long long mid, long long y){
    if(mid * mid * mid < y) return 0;
    else return 1;
}

int main(){
    optimize();
    int t;
    cin >> t;
    while(t--){

        long long x;
        cin >> x;

        bool got = false;

        for(long long a = 1; a * a * a <= x;a++){
            long long y = x - a * a * a;
            long long l = 1, r = 10000;

            while(l <= r){
                long long mid = (l + r) / 2;
                if(isOk(mid, y) == 0) l = mid + 1;
                else r = mid - 1;
            }

            if(l * l * l == y){
                got = true;
                break;
            }
        }

        if(got){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    return 0;
}
