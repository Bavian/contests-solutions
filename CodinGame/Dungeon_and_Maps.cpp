#include <iostream>
#include <climits>
#include <algorithm>

// CONSTANTS
const char EMPTY_SQUARE = '.',
           WALL = '#',
           MOVE_UP = '^',
           MOVE_RIGHT = '>',
           MOVE_DOWN = 'v',
           MOVE_LEFT = '<',
           TREASURE_SQUARE = 'T',
           TRAP[5] = "TRAP";
const int N_MIN = 0,
          N_MAX = 10,
          W_MIN = 2,
          W_MAX = 20,
          H_MIN = 2,
          H_MAX = 20,
          NO_ANSWER = INT_MAX;

// VARIABLES
int w, h, startRow, startColumn, n;
char maps[N_MAX][H_MAX][W_MAX + 1];
bool used[H_MAX][W_MAX];
int answer = NO_ANSWER;

// INPUT
void in() {
    std::cin >> w >> h >> startRow >> startColumn >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            std::cin.getline(maps[i][j], w + 1);
        }
    }
}

// SOLUTION
bool isInside(int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w;
}

bool isDeadEnd(char piece) {
    return piece == EMPTY_SQUARE || piece == WALL || piece == TREASURE_SQUARE;
}

bool isDeadEnd(int i, int j, int v) {
    //std::cout << !isInside(j, v) << used[j][v] << isDeadEnd(maps[i][j][v]) << '\n';
    return !isInside(j, v) || used[j][v] || isDeadEnd(maps[i][j][v]);
}

void solution() {
    int roadLengths[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            for (int v = 0; v < w; v++) {
                used[j][v] = false;
            }
        }

        int roadLength = 0;
        int j = startRow, v = startColumn;
        //std::cout << "go\n" << isDeadEnd(i, j, v) << '\n';
        while (!isDeadEnd(i, j, v)) {
            used[j][v] = true;
            //std::cout << maps[i][j][v] << '\n';
            switch (maps[i][j][v]) {
                case MOVE_UP: {
                    j--;
                    break;
                }
                case MOVE_RIGHT: {
                    v++;
                    break;
                }
                case MOVE_DOWN: {
                    j++;
                    break;
                }
                case MOVE_LEFT: {
                    v--;
                    break;
                }
            }
            roadLength++;
        }
        //std::cout << "\n";
        roadLengths[i] = !isInside(j, v) ||
            used[j][v] ||
            maps[i][j][v] != TREASURE_SQUARE ? NO_ANSWER : roadLength;
        //std::cout << roadLengths[i] << '\n';
    }
    auto minElement = std::min_element(roadLengths, roadLengths + n);
    answer = (*minElement) == NO_ANSWER ? NO_ANSWER : minElement - roadLengths;
}

// OUTPUT
void out() {
    if (answer == NO_ANSWER) {
        std::cout << TRAP << '\n';
    } else {
        std::cout << answer << '\n';
    }
}

// ENTRY
int main() {
    in();
    solution();
    out();
    return 0;
}

