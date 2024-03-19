#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <cstdint>
#include <chrono>
#include <climits>

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long


inline int idx_rotate(const int& idx, const int& N) {
    return (N - idx) % N;
}

int main() {
    int N;
    ll a, b, k;
    cin >> N;
    vector<int> v(N), v_rev(N);

    for (auto &x: v) {
        cin >> x;
    }
    v_rev[0] = v[0];
    for (int i = 1; i < N; ++i) {
        v_rev[i] = v[N - i];
    }
    cin >> a >> b >> k;
    int min = (a % k == 0) ? a / k - 1 : a / k;
    int max = (b % k == 0) ? b / k - 1 : b / k;

    if (max - min >= N) {
        min = 0;
        max = N - 1;
    }
    int res{};
    for (int i = min; i <= max; ++i) {
        res = std::max(std::max(v[i % N], v_rev[i % N]), res);
    }
    cout << res << endl;    
}
