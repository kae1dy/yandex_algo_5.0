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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::min_element, std::tuple, std::map, std::unordered_set, std::set, std::stringstream, std::forward_list, std::list, std::sort;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

static constexpr double DBL_EPS{1e-7};
static vector<int> x, y;

class Solution { 
public:

    static double calculate_sq(int L, int R, double h) {
        double sq{};
        for (int i = L; i < R; ++i) {
            if (y[i] > h && y[i + 1] > h) continue;
            
            if (y[i] < h && y[i + 1] < h) {
                sq += (x[i + 1] - x[i]) * (h - y[i] + h - y[i + 1]) / 2;
            } else { 
                double tmp = x[i] + (h - y[i]) / (y[i + 1] - y[i]) * (x[i + 1] - x[i]);
                if (y[i] < h) sq += (tmp - x[i]) * (h - y[i]) / 2;
                else sq += (x[i + 1] - tmp) * (h - y[i + 1]) / 2;
            }
        }
        return sq;
    }

    static double bsearch(int L, int R, double sq) {
        if (abs(sq) < DBL_EPS) return *min_element(y.begin() + L, y.begin() + R + 1);
        double hL = -3e9, hR = 3e9;
        while (abs(hR - hL) > DBL_EPS) {
            double mid = (hR + hL) / 2;
            if (calculate_sq(L, R, mid) < sq) hL = mid;
            else hR = mid;
        }
        return hL;
    }

    static double height(int L, int R, double sq, double sqL, double sqR) {
        int y_max{INT_MIN}, i_max{-1};

        for (int i = L + 1; i < R; ++i) {
            if (y[i] > y[i - 1] && y[i] > y[i + 1] && y[i] > y_max) {
                y_max = y[i];
                i_max = i;
            }
        }
        if (i_max == -1) return bsearch(L, R, sq + sqL + sqR) - *min_element(y.begin() + L, y.begin() + R + 1);

        double sqL_new = calculate_sq(L, i_max, y_max);
        double sqR_new = calculate_sq(i_max, R, y_max);

        double xL = (x[i_max] - (double)x[L]) / (x[R] - x[L]) * sq;
        double xR = (x[R] - (double) x[i_max]) / (x[R] - x[L]) * sq;

        if ((sqL_new > xL + sqL) &&
            (sqR_new > xR + sqR)) {
            double sq1 = height(L, i_max, xL, sqL, 0);
            double sq2 = height(i_max, R, xR, 0, sqR);
            if (sq1 > sq2) return sq1;
            return sq2;
        }
        else if (sqL_new > xL + sqL && xR + sqR > sqR_new &&
                sqL_new + sqR_new > xL + xR + sqL + sqR) {
            double sq1 = height(L, i_max, xL, sqL, sqR + xR - sqR_new);
            double sq2 = y_max - *min_element(y.begin() + i_max, y.begin() + R + 1);
            if (sq1 > sq2) return sq1;
            return sq2;
        }
        else if (sqL_new < xL + sqL && sqR_new > xR + sqR &&
                sqL_new + sqR_new > xL + xR + sqR + sqL) {
            double sq1 = y_max - *min_element(y.begin() + L, y.begin() + i_max + 1);
            double sq2 = height(i_max, R, xR, sqL + xL - sqL_new, sqR);
            if (sq1 > sq2) return sq1;
            return sq2;
        }
        return bsearch(L, R, sq + sqR + sqL) - *min_element(y.begin() + L, y.begin() + R + 1);
    }
};

int main() {
    int N;
    double h0;
    cin >> N >> h0;
    x = vector<int>(N + 1);
    y = vector<int>(N + 1);
    for (int i = 0; i <= N; ++i) { 
        cin >> x[i] >> y[i];
    }
    double sq = (x.back() - x.front()) * h0;
    cout << Solution::height(0, N, sq, 0, 0) << endl;
}
