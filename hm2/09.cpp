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
    int N, x, y;
    ll steps{};

    cin >> N;
    vector<pair<int, int>> pirates{};
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        pirates.emplace_back(x, y);
    }
    vector<int> used(N + 1);
    for (int i = 0; i < N; ++i) { 
        used[pirates[i].first] += 1;
    }
    for (int i = 1; i <= N; ++i) {
        if (used[i] >= 1) continue;

        for (int j = 1; j <= N; ++j) {
            if (used[j] > 1) {
                used[j] -= 1;
                used[i] += 1;
                steps += abs(i - j);
                break;
            } 
        }
    }
    ll min{LLONG_MAX};
    for (int i = 1; i <= N; ++i) {
        ll sum{};
        for (int j = 0; j < N; ++j) {
            sum += abs(i - pirates[j].second);
        }
        min = std::min(min, sum);
    }
    cout << steps + min << endl;
}
