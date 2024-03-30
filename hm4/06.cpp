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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::tuple, std::map, std::unordered_set, std::set, std::stringstream, std::forward_list, std::list, std::sort;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

int main() {
    int W, H, N, x, y;
    cin >> W >> H >> N;
    vector<pair<int, int>> tiles;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        tiles.emplace_back(x, y);
    }

    sort(tiles.begin(), tiles.end());
    vector<int> prefix_min(N + 1, H + 1), prefix_max(N + 1);
    vector<int> suffix_min(N + 1, H + 1), suffix_max(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], tiles[i - 1].second);
        prefix_max[i] = max(prefix_max[i - 1], tiles[i - 1].second);

        suffix_min[N - i] = min(suffix_min[N - i + 1], tiles[N - i].second);
        suffix_max[N - i] = max(suffix_max[N - i + 1], tiles[N - i].second);
    }

    int L = 1, R = min(W, H);
    while (L < R) {
        int mid = (L + R) / 2;
        bool flag{true};

        for (int l = 0, r = 0; r < N; ++r) {
            while (tiles[r].first - tiles[l].first >= mid) ++l;
            if (max(prefix_max[l], suffix_max[r + 1]) - min(prefix_min[l], suffix_min[r + 1]) < mid) {
                R = mid;
                flag = false;
            }
        }
        if (flag) L = mid + 1;
    }
    cout << L << endl;
}