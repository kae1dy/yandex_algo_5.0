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


using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::tuple, std::map, std::unordered_set, std::set, std::stringstream, std::forward_list, std::list, std::sort;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

static int lbinsearch(const vector<int> &v, int elem) {
    int L{0}, R{(int) v.size() - 1};

    while (L <= R) {
        int mid = (L + R) / 2;
        if (elem > v[mid]) L = mid + 1;
        else R = mid - 1;
    }
    return L;
}

static int rbinsearch(const vector<int> &v, int elem) {
    int L{0}, R{(int) v.size() - 1};

    while (L <= R) {
        int mid = (L + R) / 2;
        if (elem < v[mid]) R = mid - 1;
        else L = mid + 1;
    }
    return L;
}


int main() {
    int N, K, L, R;
    cin >> N;
    vector<int> v(N);
    for (auto &x: v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    cin >> K;
    while (K--) {
        cin >> L >> R;
        // cout << rbinsearch(v, R) << lbinsearch(v, L) << endl;
        cout << rbinsearch(v, R) - lbinsearch(v, L) << ' ';
    }
    cout << endl;
    return 0; 
}