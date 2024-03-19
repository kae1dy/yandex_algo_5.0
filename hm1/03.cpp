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
    int N;
    int64_t tmp, res{};
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        res += tmp / 4;
        if (tmp % 4 == 1) res += 1;
        else if (tmp % 4) res += 2;
    }
    cout << res << endl; 
}