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
    int tmp1{}, tmp2{}, N{};
    cin >> N >> tmp1;
    while (--N > 0) {
        cin >> tmp2;
        if ((tmp1 & 1) && (tmp2 & 1)) {
            cout << 'x';
            tmp1 = 1;
        }
        else if (!(tmp1 & 1) && !(tmp2 & 1)) {
            cout << '+';
            tmp1 = 0;
        }
        else {
            cout << '+';
            tmp1 = 1;
        }
    }
    cout << endl;
}