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

static inline bool issquare(const vector<vector<int>> &prefix, const int i, const int j, const int k, const int N, const int M) {
    if (i > N || j > M || i <= 0 || j <= 0 || i < k || j < k) return false;
    return (prefix[i][j] - prefix[i - k][j] - prefix[i][j - k] + prefix[i - k][j - k]) == (k * k);
}

int main() {
    int N, M;
    cin >> N >> M;
    char c;
    vector<vector<bool>> field(N, vector<bool>(M));
    vector<vector<int>> prefix(N + 1, vector<int>(M + 1));

    for (int i = 0; i < N; ++i) { 
        int sum{};
        for (int j = 0; j < M; ++j) {
            cin >> c;
            if (c == '#') {
                field[i][j] = true;
                ++sum;
            }
            prefix[i + 1][j + 1] = prefix[i][j + 1] + sum;
        }
    }
    int max{0};
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < M; ++j) { 
            if (field[i][j]) {
                int L{1}, R{N / 3};
                while (L <= R) {
                    int k = (L + R) / 2;
                    if (issquare(prefix, i, j + k, k, N, M) &&
                        issquare(prefix, i + k, j + k, k, N, M) &&
                        issquare(prefix, i + k, j + 2 * k, k, N, M) &&
                        issquare(prefix, i + 2 * k, j + k, k, N, M) &&
                        issquare(prefix, i + k, j, k, N, M)) L = k + 1;
                    else R = k - 1;
                }
                max = std::max(max, L);
            }
        }
    }
    // for (const auto &v: prefix) {
    //     for (const auto &x: v) {
    //         cout << x << '\t';
    //     }
    //     cout << endl;
    // }
    cout << max - 1 << endl;
    return 0;
}
