#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

// TYPES
struct Point {

    static const int radius = 6371;

    double longitude, latitude;

    Point(double longitdude, double latitude) {
        this->longitude = longitdude;
        this->latitude = latitude;
    }

    double toRad(double x) {
        return x;
    }

    double radLongitude() {
        return toRad(longitude);
    }

    double radLatitude() {
        return toRad(latitude);
    }

    double distanceTo(Point &other) {
        double x = (other.radLongitude() - radLongitude())
            * cos((other.radLatitude() + radLatitude()) / 2.0);
        double y = other.radLatitude() - radLatitude();
        return x * x + y * y;
    }
};

struct Defibrillator : Point {

    int id;
    std::string name, address, phone;

    Defibrillator(int id,
                  std::string name,
                  std::string address,
                  std::string phone,
                  double longitude,
                  double latitude)
    : Point(longitude, latitude) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phone = phone;
    }
};

// CONSTANTS
const int   N_MIN = 0,
            N_MAX = 10000,
            INFO_SEPARATORS_COUNT = 5;
const char  double_SEPARATOR = ',',
            INFO_SEPARATOR = ';';

// VARIABLES
Point* user;
int n;
Defibrillator *defibrillators[N_MAX + 1];
int answerIndex;

// INPUT
std::string substringToString(const char *begin, const char *end) {
    return std::string(begin, std::distance(begin, end));
}

int stringToInt(const char *begin, const char *end) {
    int result = 0;
    for (auto it = begin; it != end; it++) {
        result = result * 10 + (*it) - '0';
    }
    return result;
}

double stringToDouble(const char *begin, const char *end) {
    int integerPart = 0;
    double decimalPart = 0.f;
    double dec = 0.1;
    bool separatorFound = false;
    int strLength = std::distance(begin, end);
    for (auto it = begin; it != end; it++) {
        if (*it == double_SEPARATOR) {
            separatorFound = true;
            continue;
        }

        if (separatorFound) {
            decimalPart = decimalPart + ((*it) - '0') * dec;
            dec /= 10;
        } else {
            integerPart = integerPart * 10 + (*it) - '0';
        }
    }
    return integerPart + decimalPart;
}

double stringToDouble(std::string &str) {
    auto c_str = str.c_str();
    return stringToDouble(c_str, c_str + str.size());
}

Defibrillator* parseDefibrillatorInfo(std::string &defibrillatorInfo) {
    int separations = INFO_SEPARATORS_COUNT + 2;
    int separatorIndexes[separations];
    separatorIndexes[0] = 0;
    separatorIndexes[separations - 1] = defibrillatorInfo.size();
    
    int separatorNumber = 1;
    for (int i = 0; i < defibrillatorInfo.size(); i++) {
        if (defibrillatorInfo[i] == INFO_SEPARATOR) {
            separatorIndexes[separatorNumber++] = i;
        }
    }

    auto c_str = new char[defibrillatorInfo.size()];
    for (int i = 0; i < defibrillatorInfo.size(); i++) {
        c_str[i] = defibrillatorInfo[i];
    }
    auto def = new Defibrillator(
        stringToInt(c_str + separatorIndexes[0], c_str + separatorIndexes[1]),
        substringToString(c_str + separatorIndexes[1] + 1, c_str + separatorIndexes[2]),
        substringToString(c_str + separatorIndexes[2] + 1, c_str + separatorIndexes[3]),
        substringToString(c_str + separatorIndexes[3] + 1, c_str + separatorIndexes[4]),
        stringToDouble(c_str + separatorIndexes[4] + 1, c_str + separatorIndexes[5]),
        stringToDouble(c_str + separatorIndexes[5] + 1, c_str + separatorIndexes[6])
    );
    return def;
}

void in() {
    std::string longidude, latitude;
    std::getline(std::cin, longidude);
    std::getline(std::cin, latitude);
    user = new Point(stringToDouble(longidude), stringToDouble(latitude));
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string defibrillatorInfo;
        std::getline(std::cin, defibrillatorInfo);
        defibrillators[i] = parseDefibrillatorInfo(defibrillatorInfo);
    }
}

// SOLUTION
void solution() {
    /*
    std::cout << user->longitude << ' ' << user->latitude << '\n';
    std::cout << n << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << "Defibrillator number " << i << '\n';
        std::cout << '\t' << defibrillators[i]->id << '\n';
        std::cout << '\t' << defibrillators[i]->name << '\n';
        std::cout << '\t' << defibrillators[i]->address << '\n';
        std::cout << '\t' << defibrillators[i]->phone << '\n';
        std::cout << '\t' << defibrillators[i]->longitude << '\n';
        std::cout << '\t' << defibrillators[i]->latitude << '\n';
    }
    */
    auto minDistance = user->distanceTo(*defibrillators[0]);
    answerIndex = 0;
    for (int i = 1; i < n; i++) {
        auto distance = user->distanceTo(*defibrillators[i]);
        if (distance  < minDistance) {
            minDistance = distance;
            answerIndex = i;
        }
    }
}

// OUTPUT
void out() {
    std::cout << defibrillators[answerIndex]->name << '\n';
}

// ENTRY
int main () {
    in();
    solution();
    out();
    return 0;
}

