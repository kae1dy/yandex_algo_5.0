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
#define INF 1000000000


int main() {
    int N, vote, price;
    cin >> N;
    vector<pair<int, pair<int, int>>> v;
    
    for (int i = 0; i < N; ++i) {
        cin >> vote >> price;
        v.push_back({vote, {price, i}});
    }
    if (N == 1) { 
        cout << price << endl;
        cout << 1 << endl;
        cout << vote << endl;
        return 0;
    }
    sort(v.begin(), v.end(), [&](auto x, auto y) { return x.first > y.first; });
    vector<ll> prefix(N);

    ll sum{};
    for (int i = 0; i < N; ++i) {
        sum += v[i].first;
        ll tmp = sum - (i + 1) * ((ll) v[i].first);
        prefix[i] = (tmp > INF) ? INF : tmp;
    }

    int min{(v[0].second.first != -1) ? v[0].second.first : INF}, min_idx{}, min_change{};
    for (int i = 0; i < N; ++i) {
        int vote{v[i].first}, price{v[i].second.first};
        if (price == -1) continue;

        int L{}, R{i}; 
        while (L + 1 < R) { 
            int mid = (L + R) / 2;
            if (v[mid].first < prefix[mid] + vote) R = mid;
            else L = mid;
        }
        int cur = v[i].first + prefix[L];
        int diff = v[L].first - cur;
        int k = L + 1;

        int t = diff / (k + 1);
        int rest = diff % (k + 1);
        cur = cur + t * k + ((rest < k) ? (rest + 1) : k);

        // cout << cur - vote + price << endl;
        if (cur - vote + price <= min) { 
            min = cur - vote + price;
            min_idx = i; 
            min_change = L;
        }
    }
    // cout << "idxes min, change: " << min_idx << ' ' << min_change << endl;
    vote = min - v[min_idx].second.first;
    v[min_idx].first += vote;
    for (int i = 0; i <= min_change && vote > 0; ++i) {
        vote -= v[i].first - v[min_idx].first + 1;
        v[i].first = v[min_idx].first - 1;
    }
    if (!min_change || vote > 0) { 
        for (int i = 0; i < vote && i < N; ++i) {
            if (min_idx != i) v[i].first -= 1;
        }
    }

    // for (const auto &[vote, _]: v) { 
    //     cout << vote << ' ';
    // }
    // cout << endl;
    for (int i = 0; i < N; ++i) {
        if (i != min_idx && v[min_idx].first == v[i].first) { 
            min += 1;
            v[i].first -= 1;
            v[min_idx].first += 1;
            break;
        }
    }
    // cout << "idxes min, change: " << min_idx << ' ' << min_change << endl;
    cout << min << endl;
    cout << v[min_idx].second.second + 1 << endl;
    sort(v.begin(), v.end(), [&](auto x, auto y) { return x.second.second < y.second.second; });

    for (int i = 0; i < N; ++i) { 
        cout << v[i].first << ' ';
    }
    cout << endl;
    return 0;
}
