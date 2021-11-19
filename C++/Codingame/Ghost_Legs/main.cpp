#include <iostream>
#include <vector>
#include <algorithm>

// CONSTANTS
const int W_MIN = 3,
          W_MAX = 100,
          H_MIN = 3,
          H_MAX = 100;
const char VERTICAL_LADDER = '|',
           HORIZONTAL_LADDER = '-',
           LADDER_WIDTH = 3;

// VARIABLES
int w, h;
char labels[W_MAX + 1],
     ladders[H_MAX - 2][W_MAX - 1],
     numbers[W_MAX + 1];
std::vector<char*> answers;
          
// SOLUTION
void in() {
    std::cin >> w >> h; std::cin.ignore();
    std::cin.getline(labels, w + 1);
    for (int i = 0; i < h - 2; i++) {
        std::cin.getline(ladders[i], w + 1);
    }
    std::cin.getline(numbers, w + 1);
}

void solution() {
    for (int i = 0; i < w; i += LADDER_WIDTH) {
        int column = i;
        char* answer = new char[3];
        answer[0] = labels[column];
        for (int j = 0; j < h - 2; j++) {
            if (column != w - 1 && ladders[j][column + 1] == HORIZONTAL_LADDER) {
                column += LADDER_WIDTH;
            } else if (column != 0 && ladders[j][column - 1] == HORIZONTAL_LADDER) {
                column -= LADDER_WIDTH;
            }
        }
        answer[1] = numbers[column];
        answers.push_back(answer);
    }
}

void out() {
    for (int i = 0; i < answers.size(); i++) {
        std::cout << answers[i] << '\n';
    }
}

int main() {
    in();
    solution();
    out();
    return 0;
}

