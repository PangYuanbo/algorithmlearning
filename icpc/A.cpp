#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // 输入参数
    int n, k, d, q;
    cin >> n >> k >> d >> q;

    vector<int> a(n);
    vector<int> b(n);

    // 读取列表 a
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 读取列表 b
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // 创建字典 c，使用 map 和 set
    map<int, set<int> > c;
    for (int i = 0; i < n; ++i) {
        c[a[i]].insert(b[i]);
    }

    // 处理每个查询
    for (int j = 0; j < q; ++j) {
        int count = 0;
        int d_q, k_q, n_q;
        cin >> d_q >> k_q >> n_q;

        int i = d_q;
        int k_i = k_q;

        while (n_q >= 1) {
            // 确认 i 在字典 c 的键中
            if (c.find(i) != c.end()) {
                // 在对应的 set 中查找 k_i 及其之后的值
                auto it = c[i].lower_bound(k_i);
                if (it != c[i].end()) {
                    n_q -= 1;
                    k_i = *it + 1;
                    if (k_i == k) {
                        k_i = 0;
                    }
                } else {
                    count += 1;
                    i += 1;
                    if (i == d) {
                        i = 0;
                    }
                }
            } else {
                count += 1;
                i += 1;
                if (i == d) {
                    i = 0;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
