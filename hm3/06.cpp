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
    string buf, str;
    unordered_set<string> prefix{};

    getline(cin, buf);
    stringstream ss(buf);
    while (ss >> str) prefix.insert(str);

    getline(cin, buf);  
    ss = stringstream(buf);
    while (ss >> str) {
        bool flag = true;
        for (size_t i = 1; i < str.size(); ++i) {
            if (string substr = str.substr(0, i); prefix.contains(substr)) {
                cout << substr << ' ';
                flag = false;
                break;
            }
        }
        if (flag) cout << str << ' ';
    }
    cout << endl;
}