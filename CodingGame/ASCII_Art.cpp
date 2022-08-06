#include <iostream>
#include <cstring>

const int   L_MIN = 0,
            L_MAX = 30,
            H_MIN = 0,
            H_MAX = 30,
            N_MIN = 0,
            N_MAX = 200;

const int LETTERS_COUNT = 27;

int letterLength, letterHeight, mapLength;
char *message, **alphabet;

void in() {
    std::cin >> letterLength >> letterHeight; std::cin.ignore();
    int mapLength = letterLength * LETTERS_COUNT;
    
    std::string stringMessage;
    std::getline(std::cin, stringMessage);
    message = new char[stringMessage.length()];
    std::strcpy(message, stringMessage.c_str());

    alphabet = new char*[letterHeight];
    for (int i = 0; i < letterHeight; i++) {
        alphabet[i] = new char[mapLength];
        std::cin.getline(alphabet[i], mapLength + 1);
    }
}

int getLetterIndex(char letter) {
    if ('a' <= letter && letter <= 'z') {
        return letter - 'a';
    }
    if ('A' <= letter && letter <= 'Z') {
        return letter - 'A';
    }
    return LETTERS_COUNT - 1;
}

void out() {
    int messageLength = strlen(message);
    for (int i = 0; i < letterHeight; i++) {
        for (int j = 0; j < messageLength; j++) {
            int letterIndex = getLetterIndex(message[j]);
            for (int c = 0; c < letterLength; c++) {
                std::cout << alphabet[i][c + letterIndex * letterLength];
            }
        }
        std::cout << '\n';
    }
}

int main() {
    in();
    out();
}

