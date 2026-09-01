#include<iostream>
using namespace std;

int main(int argc, char* argv[]){

    int warnThreshold = 30;
    int criticalThreshold = 45;
    int numReadings = 10;

    if (argc >= 4) {
        warnThreshold = stoi(argv[1]);
        criticalThreshold = stoi(argv[2]);
        numReadings = stoi(argv[3]);
    }

    if (warnThreshold >= criticalThreshold) {
        cout << "Error   : Warning threshold must be less than critical threshold." << endl;
        return 1;
    }

    if (numReadings < 1 || numReadings > 500) {
        cout << "Error   : Number of readings must be between 1 to 500!" << endl;
        return 1;
    }

    cout << "Config : Warn=" << warnThreshold << "°C Critical=" << criticalThreshold << "°C Readings=" << numReadings << endl;


    int normalCount = 0;
    int warningCount = 0;
    int criticalCount = 0;
    int shutdownCount = 0;


    for (int i = 0; i < numReadings; i++) {
        int temp = rand() % 70;

        if (temp < warnThreshold) {
            normalCount++;
        }
        else if (temp < criticalThreshold) {
            warningCount++;
        }
        else if (temp < 60) {
            criticalCount++;
        }
        else {
            shutdownCount++;
        }
    }

    cout << "Results : Normal:" << normalCount << " Warning:" << warningCount << " Critical:" << criticalCount << " Shutdown:" << shutdownCount << endl;

    return 0;
}
