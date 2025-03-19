#include<bits/stdc++.h>
using namespace std;


#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout << fixed << setprecision(a);


int main() {
    optimize();
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); 
    int hidden = 0;
    int l = 0, r = n / 2; 

    while (l < n / 2 && r < n) {
        if (arr[l] * 2 <= arr[r]) { 
            hidden++; 
            l++;
        }
        r++; 
    }

    cout << n - hidden << endl; 
    return 0;
}
