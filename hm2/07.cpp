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


int main() {
    int test, N, min, tmp;
    cin >> test;
    for (int _ = 0 ; _ < test; ++_) { 
        cin >> N >> min;
        int len{1};
        vector<int> res{};
        for (int i = 1; i < N; ++i) {
            cin >> tmp;
            if (min == len || tmp <= len) {
                res.push_back(len);
                min = tmp;
                len = 1;
            } else {
                min = std::min(min, tmp);
                ++len;
            }
        }
        res.push_back(len);
        cout << res.size() << endl;
        for (const auto &x: res) {
            cout << x << ' ';
        }
        cout << endl;
    }
}
