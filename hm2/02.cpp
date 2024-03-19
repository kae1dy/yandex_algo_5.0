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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

int main() {
    ll N, K, res{};
    cin >> N >> K;

    vector<long long> v(N);
    deque<long long> q_max, q_min;

    for (auto &x: v) { cin >> x; }

    for (int l = 0, r = 0; r < (int) v.size(); ++r) {
        while (!q_max.empty() && q_max.back() < v[r]) { q_max.pop_back(); }
        q_max.push_back(v[r]);

        while (!q_min.empty() && q_min.back() > v[r]) { q_min.pop_back(); }
        q_min.push_back(v[r]);

        res = std::max(res, q_max.back() - q_min.front());
        if (r - l == K) {
            if (v[l] == q_max.front()) q_max.pop_front();
            if (v[l] == q_min.front()) q_min.pop_front();
            ++l;
        }
    }
    cout << res << endl;
    return 0;
}
