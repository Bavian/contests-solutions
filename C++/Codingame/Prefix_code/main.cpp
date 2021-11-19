#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define prefixCode first
#define asciiCode second

class TreeTrie {
private:
    const static int NULL_VALUE = -1;
    TreeTrie *left = nullptr, *right = nullptr;
    int value = NULL_VALUE;

    void rightNodeAdd(const bool *begin, bool *end, unsigned int value) {
        if (right == nullptr) {
            right = new TreeTrie();
        }
        right->add(begin + 1, end, value);
    }

    void leftNodeAdd(const bool *begin, bool *end, unsigned int value) {
        if (left == nullptr) {
            left = new TreeTrie();
        }
        left->add(begin + 1, end, value);
    }

public:
    void add(const bool *begin, bool *end, unsigned int value) {
        if (begin == end) {
            this->value = value;
        } else {
            if (*begin) {
                rightNodeAdd(begin, end, value);
            } else {
                leftNodeAdd(begin, end, value);
            }
        }
    }

    TreeTrie* next(bool node) {
        return node ? right : left;
    }

    bool isLeaf() {
        return value != NULL_VALUE;
    }

    int getValue() {
        return value;
    }
};

// CONSTANTS
const char  TRUE = '1',
            FALSE = '0',
            DECODE_FAILED[] = "DECODE FAIL AT INDEX";
const int   N_MIN = 0,
            N_MAX = 127,
            C_MIN = 0,
            C_MAX = 127,
            S_MAX = 5000,
            DECODE_NO_FAIL = -1;

// VARIABLES
int n;
std::pair<std::string, int> keys[N_MAX];
std::string encodedString;
std::string answer;
int decodedFailedIndex = DECODE_NO_FAIL;

// INPUT
void in() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> keys[i].prefixCode >> keys[i].asciiCode;
    }
    std::cin.ignore();
    std::getline(std::cin, encodedString);
}

// SOLUTION
bool toBool(char value) {
    return value == TRUE;
}

void solution() {
    TreeTrie root;
    for (int i = 0; i < n; i++) {
        int length = keys[i].prefixCode.size();
        bool prefix[length];
        for (int j = 0; j < length; j++) {
            prefix[j] = toBool(keys[i].prefixCode[j]);
        }
        root.add(prefix, prefix + length, keys[i].asciiCode);
    }

    std::vector<char> decodedString;
    TreeTrie *current = &root;
    int startIndex = 0;
    for (int i = 0; i < encodedString.size(); i++) {
        current = current->next(toBool(encodedString[i]));
        if (current == nullptr) {
            answer = DECODE_FAILED;
            decodedFailedIndex = startIndex;
            return;
        }

        if (current->isLeaf()) {
            decodedString.push_back(current->getValue());
            current = &root;
            startIndex = i;
        }
    }
    if (current != &root) {
        answer = DECODE_FAILED;
        decodedFailedIndex = encodedString.size() - 1;
        return;
    }
    decodedString.push_back('\0');
    answer = decodedString.data();
}

// OUTPUT
void out() {
    if (decodedFailedIndex != DECODE_NO_FAIL) {
        std::cout << DECODE_FAILED << ' ' << decodedFailedIndex << '\n';
    } else {
        std::cout << answer << '\n';
    }
}

int main() {
    in();
    solution();
    out();
    return 0;
}

