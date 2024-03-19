#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <cstdint>
#include <chrono>

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::ceil, std::floor, std::fixed, std::setprecision;


int main() {
    long long L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;

    if (x1 == x2) {
        cout << "YES\n0.0" << endl;
        return 0;
    }
    if (v1 == 0 && v2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    double n, t1{__DBL_MAX__}, t2{__DBL_MAX__};

    if (v1 != v2) {
        n = (x1 - x2) / (double) L;
        t1 = (v1 > v2) ? (L * ceil(n) + x2 - x1) / (double) (v1 - v2) : (L * floor(n) + x2 - x1) / (double) (v1 - v2);
    }

    if (v1 != -v2) {
        n = (x1 + x2) / (double) L;
        t2 = (v1 > -v2) ? (L * ceil(n) - x1 - x2) / (double) (v1 + v2) : (L * floor(n) - x1 - x2) / (double) (v1 + v2);
    }
    cout << fixed << setprecision(10) << "YES\n" << min(t1, t2) << endl;
}