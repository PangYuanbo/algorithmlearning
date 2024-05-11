#include <iostream>
#include <vector>
#include <algorithm>

struct Time {
    int start;
    int end;
};

// 比较函数，根据结束时间排序
bool cmp(const Time& a, const Time& b) {
    return a.end < b.end;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Time> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i].start >> a[i].end;
    }

    // 根据结束时间排序
    std::sort(a.begin(), a.end(), cmp);

    // 选择不重叠的时间段
    int count = 0;
    int last_end_time = -1;
    for (const auto& movie : a) {
        if (movie.start >= last_end_time) {
            last_end_time = movie.end;
            count++;
        }
    }

    std::cout << count;
    return 0;
}
