#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout << fixed << setprecision(a);

using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree <T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
    optimize()

    int n;
    cin >> n;

    vector<int> avec(n), bvec(n), cvec(n), dvec(n);

    for(int i = 0;i < n;i++){
        cin >> avec[i];
    }

    for(int i = 0;i < n;i++){
        cin >> bvec[i];
    }

    for(int i = 0;i < n;i++){
        cvec[i] = avec[i] - bvec[i];
        dvec[i] = bvec[i] - avec[i];
    }

    long long ans = 0;

    ordered_set<int> oset;

    for(int i = 0;i < n;i++){
        ans += oset.order_of_key(dvec[i]);
        oset.insert(cvec[i]);
    }

    cout << ans;
    
    return 0;
}
