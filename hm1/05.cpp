#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <cstdint>

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs;

int main() {
    uint64_t n, k, d, tmp;
    cin >> n >> k >> d;
    n *= 10;
    tmp = (n % k == 0) ? 0 : k - n % k;
    if (tmp >= 10) {
        cout << "-1" << endl;
        return 0;
    }
    n += tmp;
    cout << n;
    while (--d > 0) { cout << '0'; }
    cout << endl;
}