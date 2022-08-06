#include <iostream>
#include <cstring>

const int N_MIN = 0,
          N_MAX = 100,
          BITS_AMMOUNT = 7;

const char bitMap[2][3] = {"00", "0"};

char message[N_MAX];

void in() {
    std::cin.getline(message, N_MAX + 1);
}

void out() {
    int previousBit = -1;
    int messageLength = strlen(message);
    for (int i = 0; i < messageLength; i++) {
        for (int j = BITS_AMMOUNT - 1; j >= 0; j--) {
            int bit = ( message[i] & (1 << j) ) > 0;
            if (previousBit != bit) {
                if (previousBit != -1) {
                    std::cout << ' ';
                }
                std::cout << bitMap[bit] << ' ';
            }
            std::cout << 0;
            previousBit = bit;
        }
    }
}

int main() {
    in();
    out();
}

