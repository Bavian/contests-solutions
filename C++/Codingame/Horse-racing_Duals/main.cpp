#include <iostream>
#include <algorithm>
#include <climits>

const int N_MIN = 1,
          N_MAX = 100000,
          P_MIN = 0,
          P_MAX = 10000000,
          NO_ANSWER = 0;

int n, p[N_MAX];

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::sort(p, p + n);
    int answer = INT_MAX;
    for (int i = 1; i < n; i++) {
        answer = std::min(answer, p[i] - p[i - 1]);
    }

    std::cout << (answer < 0 ? NO_ANSWER : answer);
    return 0;
}

