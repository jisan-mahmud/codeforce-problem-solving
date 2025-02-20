#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction(a) cout << fixed << setprecision(a);

void solve() {
    string s;
    cin >> s;

    queue<char> q;
    for (char c : s) {
        q.push(c);
    }

    deque<char> wnd;
    map<char, int> cnt;

    for (int i = 0; i < s.size(); i++) {
        wnd.push_back(q.front());
        cnt[q.front()]++;
        q.pop();

        if (cnt.size() == 3) break;
    }

    if(cnt.size() != 3) {
        cout << 0 << endl;;
        return;
    }

    int mn = wnd.size();
    while (true) {
        mn = min(mn, (int)wnd.size());
        char v = wnd.front();
        if (cnt[v] == 1) {
            while (!q.empty()) {
                wnd.push_back(q.front());
                cnt[q.front()]++;
                q.pop();

                if(cnt[v] > 1) break;
            }
        }
        wnd.pop_front();
        cnt[v]--;
        if (cnt[v] == 0) break;
    }

    cout << mn << endl;
}

int main() {
    optimize();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
