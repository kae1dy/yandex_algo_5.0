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

    vector<vector<bool>> v(8, vector<bool>(8, false));

    int N, i{}, j;
    cin >> N;

    for (int _ = 0; _ < N; ++_) {
        cin >> i >> j; 
        v[i - 1][j - 1] = true;
    }
    ll sum{};
    for (i = 0; i < 8; ++i) { 
        for (j = 0; j < 8; ++j) {
            if (!v[i][j]) continue;
            
            int walls{4};
            if (i > 0 && v[i - 1][j]) { --walls; }
            if (i < 7 && v[i + 1][j]) { --walls; }
            if (j > 0 && v[i][j - 1]) { --walls; }
            if (j < 8 && v[i][j + 1]) { --walls; }
            sum += walls;
        }
    }
    cout << sum << endl;
    return 0;
}
