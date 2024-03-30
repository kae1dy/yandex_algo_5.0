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
#include <tuple>
#include <unordered_set>
#include <set>
#include <sstream>
#include <forward_list>
#include <list>

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::tuple, std::map, std::unordered_set, std::set, std::stringstream, std::forward_list, std::list;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

static inline ull height(const vector<ull> &v, const ull w) {
    ull h{}, still{};
    for (const auto &x: v) {
        if (still < x + 1) {
            if (x > w) return ULLONG_MAX;
            still = w - x;
            ++h;
        } else {
            still -= x + 1;
        }
    }
    return h;
}

int main() {
    ull w, a, b, L{}, R{};
    cin >> w >> a >> b;

    vector<ull> v1(a), v2(b);
    for (auto &x: v1) {
        cin >> x;
        L = max(x, L);
    }
    for (auto &x: v2) {
        cin >> x;
        R = max(x, R);
    }
    R = w - R;
    while (L <= R) {
        ull mid = (L + R) / 2;
        if (height(v1, mid) <= height(v2, w - mid)) R = mid - 1;
        else L = mid + 1;
    }
    cout << min(height(v2, w - L), max(height(v1, L - 1), height(v2, w - L + 1))) << endl;
    return 0;
}
