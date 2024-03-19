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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;


int main() {
    int N, y, m, d;
    string tmp;
    vector<int> holidays(7, 52);
    vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    cin >> N >> y;

    year ye{y};
    year_month_day ymd{ye/1/1};
    weekday wd{sys_days(ymd)};
    holidays[wd.c_encoding()] += 1;
    if (ye.is_leap()) {
        holidays[(wd.c_encoding() + 1) % 7] += 1;
    }

    while (N-- > 0) { 
        cin >> d >> tmp;
        if (tmp == "January") {
            m = 1;
        } else if (tmp == "February") { 
            m = 2;
        } else if (tmp == "March") {
            m = 3;
        } else if (tmp == "April") {
            m = 4;
        } else if (tmp == "May") {
            m = 5;
        } else if (tmp == "June") {
            m = 6;
        } else if (tmp == "July") {
            m = 7;
        } else if (tmp == "August") {
            m = 8;
        } else if (tmp == "September") {
            m = 9;
        } else if (tmp == "October") {
            m = 10;
        } else if (tmp == "November") {
            m = 11;
        } else if (tmp == "December") {
            m = 12;
        } else return -1;
        year_month_day ymd{ye/m/d};
        weekday wd{sys_days(ymd)};
        holidays[wd.c_encoding()] -= 1;
    }
    cin >> tmp;
    int min_w{53}, max_w{-1}, min_idx{}, max_idx{};
    for (size_t i = 0; i < holidays.size(); ++i) {
        if (holidays[i] < min_w) {
            min_w = holidays[i];
            min_idx = i;
        }
        if (holidays[i] > max_w) {
            max_w = holidays[i];
            max_idx = i;
        }
    }
    cout << week[max_idx] << ' ' << week[min_idx];
    return 0;
}