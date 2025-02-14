#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout << fixed << setprecision(a);

string s, t;
int n;
vector< int > seq;

bool canConvert(int op){

    if(op > n) return 0;

    vector<int> delet_detected(n);

    for(int i = 0;i < op;i++){
        delet_detected[seq[i]] = 1;
    }

    int cnt = 0;
    for(int i = 0;i < s.length();i++){
        if(cnt == t.length()) break;
        if(!delet_detected[i] && s[i] == t[cnt]) cnt++;
    }
    if(cnt == t.length()) return 1;
    else return 0;
}

bool isOk(int m){
    if(canConvert(m)) return 0;
    return 1;
}

int main(){
    optimize();
    cin >> s >> t;
    n = s.length();

    for(int i =0;i < n;i++){
        int temp;
        cin >> temp;
        seq.push_back(temp - 1);
    }

    int l = 0, r = n;

    while(l <= r){
        int mid = (l + r) / 2;
        if(isOk(mid) == 0) l = mid + 1;
        else r = mid - 1;
    }

    cout << l - 1;
    
    return 0;
}
