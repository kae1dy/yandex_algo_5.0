#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs;

int main() {
    int x1, x2, y1, y2, flag, res{};
    char buf;
    cin >> x1 >> buf >> x2 >> y1 >> buf >> y2 >> flag;

    int tmp = x2 + y2 - y1 - x1;

    if (tmp >= 0) {
        res = tmp;
        if ((flag == 1 && res + y1 <= x2) ||
            (flag == 2 && x1 <= y2)) res += 1;
    }
    cout << res << endl;
    return 0;
}