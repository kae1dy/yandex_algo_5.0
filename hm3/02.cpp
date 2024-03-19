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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::tuple, std::map;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

int main() {
    map<char, int> mp1{}, mp2{};
    string str1, str2;
    cin >> str1 >> str2;

    for (const auto sym: str1)  mp1[sym] += 1;
    for (const auto sym: str2)  mp2[sym] += 1;

    cout << ((mp1 == mp2) ? "YES" : "NO") << endl;
}