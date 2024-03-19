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

using std::cin, std::cout, std::endl, std::string, std::vector, std::pair, std::unordered_map, std::queue, std::priority_queue, std::min, std::max, std::swap, std::abs, std::deque, std::max_element, std::tuple;
using std::chrono::year_month_day, std::chrono::year, std::chrono::month, std::chrono::day, std::chrono::sys_days, std::chrono::weekday;

#define ll long long
#define ull unsigned long long

template <typename T>
inline void print_matrix(const vector<vector<T>> &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

template <typename T>
inline bool is_rectangle(const vector<vector<T>> &matrix, const tuple<int, int, int, int> &t, T elem) {
    const auto [i_min, j_min, i_max, j_max] = t;

    for (int i = i_min; i <= i_max; ++i) {
        for (int j = j_min; j <= j_max; ++j) {
            if (matrix[i][j] != elem) return false;
        }
    }
    return true;
}

template <typename T>
inline void set_rectangle(vector<vector<T>> &matrix, const tuple<int, int, int, int> &t, T elem) {
    const auto [i_min, j_min, i_max, j_max] = t;
    for (int i = i_min; i <= i_max; ++i) {
        for (int j = j_min; j <= j_max; ++j) {
            matrix[i][j] = elem;
        }
    }
}

template <typename T>
inline tuple<int, int, int, int> valid_rectangle(vector<vector<T>> &matrix, const tuple<int, int, int, int> &t, T elem) {
    const auto [i_min, j_min, i_max, j_max] = t;
    int i_new_min{i_max}, j_new_min{j_max}, i_new_max{0}, j_new_max{0};
    for (int i = i_min; i <= i_max; ++i) {
        for (int j = j_min; j <= j_max; ++j) {
            if (matrix[i][j] == elem) {
                i_new_min = min(i_new_min, i);
                j_new_min = min(j_new_min, j);

                i_new_max = max(i_new_max, i);
                j_new_max = max(j_new_max, j);
            }
        }
    }
    return {i_new_min, j_new_min, i_new_max, j_new_max};
}


template <typename T>
static bool divide_into_rectangles(vector<vector<T>> &matrix, const tuple<int, int, int, int> &t) {
    const auto [i_min, j_min, i_max, j_max] = t;

    if (is_rectangle(matrix, t, 'a')) {
        if (i_min < i_max) {
            set_rectangle(matrix, {i_max, j_min, i_max, j_max}, 'b');
        } else {
            set_rectangle(matrix, {i_min, j_max, i_max, j_max}, 'b');
        }
        return true;
    }
    int di, dj, start_i, start_j;
    if (matrix[i_min][j_min] == 'a') {
        di = 1, dj = 1;
        start_i = i_min, start_j = j_min;
    }
    else if (matrix[i_max][j_min] == 'a') {
        di = -1, dj = 1;
        start_i = i_max, start_j = j_min;
    }
    else if (matrix[i_min][j_max] == 'a') {
        di = 1, dj = -1;
        start_i = i_min, start_j = j_max;
    }
    else if (matrix[i_max][j_max] == 'a') {
        di = -1, dj = -1;
        start_i = i_max, start_j = j_max;
    } else return false;

    for (int i = start_i; i_min <= i && i <= i_max; i += di) {
        for (int j = start_j; matrix[start_i][j] != '.' && j_min <= j && j <= j_max; j += dj) {
            if (matrix[i][j] == 'a') matrix[i][j] = 'b';
            else {
                for (int k = start_j; matrix[i][k] != '.' && matrix[start_i][k] != '.' && j_min <= k && k <= j_max; k += dj) {
                    matrix[i][k] = 'a';
                }
                auto tt = valid_rectangle(matrix, t, 'a');
                return is_rectangle(matrix, tt, 'a');
            }
        }
    }
    return true;
}


template <typename T>
static tuple<int, int, int, int> bfs(vector<vector<T>> &matrix, int i_start, int j_start, T elem) {

    int i_min{i_start}, j_min{j_start}, i_max{i_start}, j_max{j_start};
    int N{static_cast<int>(matrix.size())}, M{static_cast<int>(matrix[0].size())};

    queue<pair<int, int>> q;
    q.emplace(i_start, j_start);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        const auto [i, j] = now;

        if (i > 0 && matrix[i - 1][j] == '#') { 
            q.emplace(i - 1, j);
        }
        if (i < N - 1 && matrix[i + 1][j] == '#') { 
            q.emplace(i + 1, j);
        }
        if (j > 0 && matrix[i][j - 1] == '#') { 
            q.emplace(i, j - 1);
        }
        if (j < M - 1 && matrix[i][j + 1] == '#') { 
            q.emplace(i, j + 1);
        }
        matrix[i][j] = elem;
        i_min = min(i_min, i);
        j_min = min(j_min, j);
        i_max = max(i_max, i);
        j_max = max(j_max, j);
    }
    return {i_min, j_min, i_max, j_max};
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M));

    int counter{};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char sym;
            cin >> sym;
            if (sym == '#') {
                matrix[i][j] = 'a';
                ++counter;
            } else {
                matrix[i][j] = sym;
            }
        }
    }
    if (counter <= 1) {
        cout << "NO" << endl;
        return 0;
    }
    auto t = valid_rectangle(matrix, {0, 0, N - 1, M - 1}, 'a');

    if (divide_into_rectangles(matrix, t)) {
        cout << "YES" << endl;
        print_matrix(matrix);
    } else cout << "NO" << endl;
    return 0;
}