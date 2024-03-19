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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

int main() {
    ll N, x_min{LLONG_MAX}, y_min{LLONG_MAX}, y_max{LLONG_MIN}, x_max{LLONG_MIN}, x{}, y{};
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        x_min = min(x_min, x);
        y_min = min(y_min, y);

        x_max = max(x_max, x);
        y_max = max(y_max, y);        
    }
    cout << x_min << ' ' <<  y_min << ' ' << x_max << ' ' << y_max << endl;
}
