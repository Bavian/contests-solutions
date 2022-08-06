#include <iostream>
#include <cstring>

// CLASSES
enum HorizontalDirection { ON_LEFT, MIDDLE, ON_RIGHT };
enum VerticalDirection { ABOVE, IN_MIDDLE, BELOW };

// CONSTANTS
const int   W_MIN = 1,
            W_MAX = 10000,
            H_MIN = 1,
            H_MAX = 10000,
            N_MIN = 2,
            N_MAX = 100,
            X_MIN = 0,
            X_MAX = W_MAX - 1,
            Y_MIN = 0,
            Y_MAX = H_MAX - 1;
const char  UP[] = "U",
            UP_RIGHT[] = "UR",
            RIGHT[] = "R",
            DOWN_RIGHT[] = "DR",
            DOWN[] = "D",
            DOWN_LEFT[] = "DL",
            LEFT[] = "L",
            UP_LEFT[] = "UL";

// SOLUTION
HorizontalDirection getHorizontalDirection(char *direction) {
    if (strcmp(direction, UP_RIGHT) == 0 ||
        strcmp(direction, RIGHT) == 0 ||
        strcmp(direction, DOWN_RIGHT) == 0) {
        return ON_RIGHT;
    }
    if (strcmp(direction, UP_LEFT) == 0 ||
        strcmp(direction, LEFT) == 0 ||
        strcmp(direction, DOWN_LEFT) == 0) {
        return ON_LEFT;
    }
    return MIDDLE;
}

VerticalDirection getVerticalDirection(char *direction) {
    if (strcmp(direction, UP_RIGHT) == 0 ||
        strcmp(direction, UP) == 0 ||
        strcmp(direction, UP_LEFT) == 0) {
        return ABOVE;
    }
    if (strcmp(direction, DOWN_RIGHT) == 0 ||
        strcmp(direction, DOWN) == 0 ||
        strcmp(direction, DOWN_LEFT) == 0) {
        return BELOW;
    }
    return IN_MIDDLE;
}

int main() {
    int width, height;
    std::cin >> width >> height;

    int n;
    std::cin >> n;

    int x, y;
    std::cin >> x >> y;
    std::cin.ignore();

    int left = 0, right = width;
    int top = 0, bottom = height;

    char bombDirection[3];
    for (;;) {    
        std::cin.getline(bombDirection, 3);
        switch (getHorizontalDirection(bombDirection)) {
            case ON_LEFT: right = x;
            case MIDDLE: break;
            case ON_RIGHT: left = x + 1;
        }
        switch(getVerticalDirection(bombDirection)) {
            case ABOVE: bottom = y;
            case IN_MIDDLE: break;
            case BELOW: top = y + 1;
        }
        x = left + (right - left) / 2;
        y = top + (bottom - top) / 2;
        std::cout << x << ' ' << y << '\n';
    }
}

