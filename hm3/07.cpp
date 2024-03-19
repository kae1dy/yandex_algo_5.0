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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::tuple, std::map, std::unordered_set, std::set, std::stringstream;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

int main() {
    int N;
    ll x, y;
    set<pair<ll, ll>> s{};
    vector<pair<ll, ll>> v, points_min(4);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        if (!s.contains({x, y})) {
            s.emplace(x, y);
            v.emplace_back(x, y);
        }
    }
    for (size_t i = 0; i < v.size(); ++i) {
        const auto &[x1, y1] = v[i];

        for (size_t j = i + 1; j < v.size(); ++j) {
            const auto &[x2, y2] = v[j];
            vector<pair<ll, ll>> points1, points2;
            
            ll dif_pos = abs(x1 - x2) + abs(y1 - y2);
            ll dif_neg = abs(x1 - x2) - abs(y1 - y2);

            int flag_x = (x2 > x1) ? -1 : 1;
            int flag_y = (y2 > y1) ? -1 : 1;

            pair tmp = {x1 - flag_x * dif_neg, y1 - flag_y * dif_pos};
            if (!s.contains(tmp)) points1.push_back(std::move(tmp));
            tmp = {x2 + flag_x * dif_pos, y2 - flag_y * dif_neg};
            if (!s.contains(tmp)) points1.push_back(std::move(tmp));

            if (points_min.size() > points1.size()) points_min = std::move(points1);

            tmp = {x1 - flag_x * dif_pos, y1 + flag_y * dif_neg};
            if (!s.contains(tmp)) points2.push_back(std::move(tmp));
            tmp = {x2 + flag_x * dif_neg, y2 + flag_y * dif_pos};
            if (!s.contains(tmp)) points2.push_back(std::move(tmp));

            if (points_min.size() > points2.size()) points_min = std::move(points2);
        }
    }
    cout << points_min.size() << endl;
    for (const auto &[x, y]: points_min) {
        cout << x << ' ' << y << endl;
    }
}