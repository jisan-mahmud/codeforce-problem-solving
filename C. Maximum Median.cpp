#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout << fixed << setprecision(a);

long long n, k;
vector<long long> arr;

long long minimunOperation(long long m){
    long long totalOperation = 0;
    for(int i = n / 2;i < n;i++){
        if(arr[i] < m) totalOperation += m - arr[i];
    }
    return totalOperation;
}


bool isOk(long long mid){
    if(minimunOperation(mid) > k) return 1;
    return 0;
}

int main(){
    optimize();
    

    cin >> n >> k;
    for(long long i =0; i < n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    long long l = 0, r = 1e9 + k + 1;

    while(l <= r){
        long long mid = (l + r) / 2;
        if(isOk(mid) == 0) l = mid + 1;
        else r = mid -1;
    }

    cout << l - 1;


    return 0;
}
