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

int main() {

    ull N, M, sum{}, tmp, target, k;
    cin >> N >> M;
    vector<ull> prefix_sum(N + 1);

    for (size_t i = 1; i <= N; ++i) {
        cin >> tmp;
        sum += tmp;
        prefix_sum[i] = sum;
    }

    while (M--) {
        cin >> k >> target;
        bool flag{false};
        ull L{}, R{N - k + 1};
        while (L < R) {
            ll mid = (L + R) / 2;
            if (prefix_sum[mid + k] - prefix_sum[mid] == target) {
                cout << mid + 1 << endl;
                flag = true;
                break;
            }
            else if (prefix_sum[mid + k] - prefix_sum[mid] < target) L = mid + 1;
            else R = mid;
        }
        if (!flag) {
            cout << -1 << endl;
        }
    }

}
