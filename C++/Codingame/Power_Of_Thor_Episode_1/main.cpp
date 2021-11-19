#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int thorX;
    int thorY;
    cin >> lightX >> lightY >> thorX >> thorY; cin.ignore();

    // game loop
    while (true) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        int vectorX = lightX - thorX;
        int vectorY = lightY - thorY;

        std::string answer;
        if (vectorX > 0) {
            if (vectorY == 0) {
                answer = "E";
            } else if (vectorY > 0) {
                answer = "SE";
                thorY += 1;
            } else {
                answer = "NE";
                thorY -= 1;
            }
            thorX += 1;
        } else if (vectorX < 0) {
            if (vectorY == 0) {
                answer = "W";
            } else if (vectorY > 0) {
                answer = "SW";
                thorY += 1;
            } else {
                answer = "NW";
                thorY -= 1;
            }
            thorX -= 1;
        } else {
            if (vectorY > 0) {
                answer = "S";
                thorY += 1;
            } else {
                answer = "N";
                thorY -= 1;
            }
        }

        cout << answer << endl;
    }
}

