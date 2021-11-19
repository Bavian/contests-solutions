#include <iostream>

// CONSTANTS
const int   W_MIN = 1,
            W_MAX = 20000,
            H_MIN = 1,
            H_MAX = 20000,
            AXIS_MIN = 1,
            AXIS_MAX = 500;

// VARIABLES
int width, height;
int n, m;
int xAxis[AXIS_MAX + 2];
int yAxis[AXIS_MAX + 2];
int answer;

// INPUT
void in() {
    std::cin >> width >> height >> n >> m;

    xAxis[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> xAxis[i];
    }
    xAxis[n + 1] = width;

    yAxis[0] = 0;
    for (int i = 1; i <= m; i++) {
        std::cin >> yAxis[i];
    }
    yAxis[m + 1] = height;
}

// SOLUTION
void solution() {
    int ySegmentsCount[height + 1];
    for (int i = 0; i <= height; i++) {
        ySegmentsCount[i] = 0;
    }

    for (int i = 0; i < m + 2; i++) {
        for (int j = i + 1; j < m + 2; j++) {
            ySegmentsCount[yAxis[j] - yAxis[i]]++;
        }
    }

    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            auto xSize = xAxis[j] - xAxis[i];
            if (xSize <= height) {
                answer += ySegmentsCount[xSize];
            }
        }
    }
}

// OUTPUT
void out() {
    std::cout << answer << '\n';
}

// ENTRY
int main() {
    in();
    solution();
    out();
    return 0;
}

