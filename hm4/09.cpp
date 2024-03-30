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
#define EPS 0.00001

static vector<double> x, y, v;

bool intersection(double x1, double y1, double r1, double x2, double y2, double r2, double &xi1, double &yi1, double &xi2, double &yi2) {
    double a, b, c;
    a = -2 * x2,
    b = -2 * y2,
    c = x2 * x2 + y2 * y2 + r1 * r1 - r2 * r2;

    double x0 = -a * c/(a * a + b * b) - x1, y0 = -b * c / (a * a + b * b) - y1;
    if (c*c > r1*r1*(a*a+b*b)+EPS) return false;
    else if (abs (c*c - r1*r1*(a*a+b*b)) < EPS) {
        xi1 = x0;
        xi2 = x0;
        yi1 = y0;
        yi2 = y0;
        return true;
    }
    else {
        double d = r1*r1 - c*c/(a*a+b*b);
        double mult = sqrt (d / (a*a+b*b));
        xi1 = x0 + b * mult;
        xi2 = x0 - b * mult;
        yi1 = y0 - a * mult;
        yi2 = y0 + a * mult;
        return true;
    }
}


static bool checktime(double time, double D, double &x_res, double &y_res) {
    vector<double> x_tmp = {0.0}, y_tmp = {D};
    for (size_t i = 0; i < x.size(); ++i) { 
        for (size_t j = i + 1; j < x.size(); ++j) {
            double x1{}, y1{}, x2{}, y2{};
            if (intersection(x[i], y[i], v[i], x[j], y[j], v[j], x1, y1, x2, y2)) { 
                bool flag = sqrt(x1 * x1 + y1 * y1) <= D;
                for (size_t k = 0; flag && k < x.size(); ++k) { 
                    if (sqrt((x1 - x[k]) * (x1 - x[k]) + (y1 - y[k]) * (y1 - y[k])) / v[k] <= time) {
                        flag = false;
                        break;
                    } 
                }
                if (flag) {
                    x_res = x1;
                    y_res = y1;
                    return true;
                }
                flag = sqrt(x2 * x2 + y2 * y2) <= D;
                for (size_t k = 0; flag && k < x.size(); ++k) { 
                    if (sqrt((x2 - x[k]) * (x2 - x[k]) + (y2 - y[k]) * (y2 - y[k])) / v[k] <= time) {
                        flag = false;
                        break;
                    } 
                }
                if (flag) {
                    x_res = x2;
                    y_res = y2;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int D, N;
    cin >> D >> N;
    x = vector<double>(N);
    y = vector<double>(N);
    v = vector<double>(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> v[i];
    }

    double L{}, r1{4000.0}, x_res{}, y_res{};
    while (r1 - L > EPS) { 
        double mid = (L + r1) / 2;
        if (checktime(mid, D, x_res, y_res)) {
            L = mid;
        } else r1 = mid;
    }
    cout << L << endl;
    cout << x_res << ' ' << y_res << endl;
}
