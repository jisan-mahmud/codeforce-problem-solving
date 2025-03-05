#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > a(705, vector<int>(705));
int n, m;

bool isValid(int x, int i, int j){
    if(i > 0 && a[i-1][j] == x) return false;
    if(i < n-1 && a[i+1][j] == x) return false; 
    if(j > 0 && a[i][j-1] == x) return false;
    if(j < m-1 && a[i][j+1] == x) return false;
    return true;
}

void solve() {

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }

    vector<int> cnt(n * m + 1, 0);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(isValid(a[i][j], i, j)){
                if(cnt[a[i][j]] == 0) cnt[a[i][j]] = 1; 
            }else{
                cnt[a[i][j]] = 2;
            }
        }
    }

    int sum = accumulate(cnt.begin(), cnt.end(), 0);
    int mx = *max_element(cnt.begin(), cnt.end());

    cout << abs(sum - mx) << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        solve();
    }

    return 0;
}
