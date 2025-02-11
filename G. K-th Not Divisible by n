#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout << fixed << setprecision(a);

bool isOk(int mid, int n, int k){
    if((mid - mid / n) < k) return 0;
    else return 1;
}

int main(){
    optimize();
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        long long left = 0, right = 2 * k + 1;

        while(left <= right){
            long long mid = (left + right) / 2;
            if(isOk(mid, n, k) == 0) left = mid + 1;
            else right = mid - 1;
        }

        cout << left << endl;
    }
    return 0;
}
