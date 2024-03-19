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
    int N{}, tmp, max{INT_MIN};
    cin >> N;

    ll sum{};
    
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        max = std::max(max, tmp);
        sum += tmp;
    }
    cout << ((sum - max < max) ? max + max - sum: sum) << endl;
    return 0;
}
