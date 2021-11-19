#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int NO_TEMPERATURE = -10000;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    int n; // the number of temperatures to analyse
    int closest = NO_TEMPERATURE;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int temperature; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> temperature; cin.ignore();
        int absClosest = abs(closest);
        int absTemperature = abs(temperature);
        closest = absTemperature < absClosest ? temperature : closest;
        closest = absTemperature == absClosest && temperature != closest ? absTemperature : closest;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << (closest == NO_TEMPERATURE ? 0 : closest) << "\n";
}
