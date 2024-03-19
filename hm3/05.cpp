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
    int N, x, y, idx1{}, idx2{}, x_max{}, y_max{};
    ll h{};
    cin >> N;

    queue<int> good, bad;
    for (int i = 1; i <= N; ++i) { 
        int counter{i};
        cin >> x >> y;
        
        if (x > y) {
            if (y > y_max) {
                y_max = y;
                swap(counter, idx1);
            }
            h += x - y;
            if (counter) good.push(counter);
        } else { 
            if (x > x_max) { 
                x_max = x;
                swap(counter, idx2);
            }
            if (counter) bad.push(counter);
        }
    }
    cout << max(h + x_max, h + y_max) << endl;
    while (!good.empty()) { 
        cout << good.front() << ' ';
        good.pop();
    }
    if (idx1) cout << idx1 << ' ';
    if (idx2) cout << idx2 << ' ';
    while (!bad.empty()) { 
        cout << bad.front() << ' ';
        bad.pop();
    }
    cout << endl;
    return 0;
}
