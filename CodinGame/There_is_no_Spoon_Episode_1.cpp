#include <iostream>

// CONSTANTS
const int   WIDTH_MIN = 0,
            WIDTH_MAX = 30,
            HEIGHT_MIN = 0,
            HEIGHT_MAX = 30,
            NO_NEIGHBORS_X = -1,
            NO_NEIGHBORS_Y = -1,
            ANSWERS = 3;
const char  NEIGHBOR_YES = '0',
            NEIGHBOR_NO = '.';

// VARIABLES
int width, height;
bool neighbors[HEIGHT_MAX + 2][WIDTH_MAX + 2];
int rightNeighbors[HEIGHT_MAX + 2][WIDTH_MAX + 2];
int bottomNeighbors[HEIGHT_MAX + 2][WIDTH_MAX + 2];

// INPUT
void in() {
    std::cin >> width >> height;
    std::cin.ignore();
    for (int i = 0; i < height; i++) {
        char buffer[width + 1];
        std::cin.getline(buffer, width + 1);
        for (int j = 0; j < width; j++) {
            neighbors[i + 1][j + 1] = buffer[j] == NEIGHBOR_YES;
        }
    }
}

// SOLUTION
void solution() {
    /*
    std::cout << height << " " << width << ". ";
    for (int i = 0; i < height + 2; i++) {
        for (int j = 0; j < width + 2; j++) {
            std::cout << neighbors[i][j] << ' ';
        }
        std::cout << '.';
    }
    std::cout << "\n";
    */
    for (int i = 0; i < height + 2; i++) {
        int lastNeighborIndex = width + 2;
        for (int j = width + 1; j >= 0; j--) {
            if (neighbors[i][j]) {
                if (lastNeighborIndex == width + 2) {
                    rightNeighbors[i][j] = NO_NEIGHBORS_X;
                } else {
                    rightNeighbors[i][j] = lastNeighborIndex;
                }
                lastNeighborIndex = j;
            }
        }
    }

    for (int j = 0; j < width + 2; j++) {
        int lastNeighborIndex = height + 2;
        for (int i = height + 1; i >= 0; i--) {
            if (neighbors[i][j]) {
                if (lastNeighborIndex == height + 2) {
                    bottomNeighbors[i][j] = NO_NEIGHBORS_Y;
                } else {
                    bottomNeighbors[i][j] = lastNeighborIndex;
                }
                lastNeighborIndex = i;
            }
        }
    }
}

// OUTPUT
void out() {
    for (int i = 0; i < height + 2; i++) {
        for (int j = 0; j < width + 2; j++) {
            if (neighbors[i][j]) {
                std::cout << j - 1 << ' ' << i - 1 << ' ';
                if (rightNeighbors[i][j] != NO_NEIGHBORS_X) {
                    std::cout << rightNeighbors[i][j] - 1 << ' ' << i - 1 << ' ';
                } else {
                    std::cout << NO_NEIGHBORS_X << ' ' << NO_NEIGHBORS_Y << ' ';
                }
                if (bottomNeighbors[i][j] != NO_NEIGHBORS_Y) {
                    std::cout << j - 1 << ' ' << bottomNeighbors[i][j] - 1 << '\n';
                } else {
                    std::cout << NO_NEIGHBORS_X << ' ' << NO_NEIGHBORS_Y << '\n';
                }
            }
        }
    }
}

int main() {
    in();
    solution();
    out();
    return 0;
}

