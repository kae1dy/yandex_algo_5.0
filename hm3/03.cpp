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
    map<int, int> mp{};
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        mp[tmp] += 1;
    }
    int num_prev{mp.begin()->first}, count_prev{}, min{INT_MAX};
    for (const auto &[num, count]: mp) {
        if (num_prev + 1 == num) {
            min = std::min(min, N - count_prev - count);
        } else min = std::min(min, N - count);
        num_prev = num;
        count_prev = count;
    }
    cout << min << endl;
}