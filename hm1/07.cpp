#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <cstdint>
#include <climits>
#include <chrono>

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs;


class Solution {
public:
    static int min_step;

    static bool dfs(int x, int y, int p, int t, int step) {
        if (y <= 0 && t <= 0) {
            min_step = min(min_step, step);
            return true;
        }
        if (x <= 0) return false;
        
        bool flag = false;
        if (x > t) {
            int over = x - t;
            flag = dfs(x, y - over, p, (y - over) > 0 ? p : 0, step + 1);
        }
        if (x > y) {
            int over = x - y;
            flag |= dfs(x - t + over, 0, p, t - over, step + 1);
        }
        return flag;
    }
};

int Solution::min_step = INT_MAX;

int main() {
    int x, y, p;
    cin >> x >> y >> p;
    if (Solution::dfs(x, y, p, 0, 0)) {
        cout << Solution::min_step << endl;
    } else {
        cout << "-1" << endl;
    }
}