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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::tuple, std::map;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

int main() {
    map<ll, int> mp{};
    int N, K;

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        ll tmp;
        cin >> tmp;
        if (mp.count(tmp)) {
            if (i - mp[tmp] <= K) {
                cout << "YES" << endl;
                return 0;
            }
        }
        mp[tmp] = i;
    }
    cout << "NO" << endl;
}