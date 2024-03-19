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
    int64_t P, V, Q, M;
    cin >> P >> V >> Q >> M;

    if (P > Q) {
        swap(P, Q);
        swap(V, M);
    }
    
    if (P + V >= Q + M) {
        cout << V * 2 + 1 << endl;
    } else if (P == Q) {
        cout << max(V, M) * 2 + 1 << endl;
    }
    else if (P + V >= Q - M) {
        cout << 2 * (V + M + 1) - abs(P + V - Q + M + 1);
    }
    else {
        cout << 2 * (V + M + 1);
    }
    return 0;
}