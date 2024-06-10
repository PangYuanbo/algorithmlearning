#include <iostream>
#include<vector>
#include <map>
using namespace std;

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] != a[i]) {
            cnt[b[i]]++;
        }
    }

    int m;
    cin >> m;
    vector<int> d(m);
    for(int i = 0; i < m; i++) {
        cin >> d[i];
    }

    bool found = false;

    for(int i = 0; i < n; i++) {
        if(b[i] == d[m - 1]) {
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "NO\n";
        return;
    }

    for(int i = m - 1; i >= 0; i--) {
        if(cnt[d[i]] > 0) {
            cnt[d[i]]--;
        }
    }

    for(auto &[k, v] : cnt) {
        if(v > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "Yes\n";

}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}
