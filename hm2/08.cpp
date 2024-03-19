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
    int N, M, i_max, j_max, ii_max, jj_max;
    ll max{}, tmp, max1{}, max2{};

    cin >> N >> M;
    vector<vector<ll>> matrix(N, vector<ll>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> tmp;
            matrix[i][j] = tmp;
            if (max < tmp) {
                max = tmp;
                i_max = i;
                j_max = j;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i != i_max && max1 < matrix[i][j]) {
                max1 = matrix[i][j];
                jj_max = j;
            }
            if (j != j_max && max2 < matrix[i][j]) {
                max2 = matrix[i][j];
                ii_max = i;
            }
        }
    }

    max1 = 0, max2 = 0;
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < M; ++j) {
            if (i != i_max && j != jj_max && max1 < matrix[i][j]) {
                max1 = matrix[i][j];
            }
            if (i != ii_max && j != j_max && max2 < matrix[i][j]) {
                max2 = matrix[i][j];
            }
        }
    }
    if (max1 > max2) {
        cout << ii_max + 1 << ' ' << j_max + 1 << endl;
    } else {
        cout << i_max + 1 << ' ' << jj_max + 1 << endl;
    }
    return 0;
}
