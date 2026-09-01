#include <iostream>
#include <cmath>
using namespace std;

inline double distanceBetween(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

inline double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

inline double clamp(double value, double minVal, double maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

inline bool isInSafeZone(double x, double y, double cx, double cy, double radius) {
    double dist = distanceBetween(x, y, cx, cy);
    return dist <= radius;
}

int main() {

    double homeX = 0.0, homeY = 0.0;
    double safeRadius = 50.0;

    double waypoints[3][2] = {
        {20.0, 30.0},
        {45.0, 45.0},
        {60.0, 10.0}
    };

    for (int i = 0; i < 3; i++) {
        double wx = waypoints[i][0];
        double wy = waypoints[i][1];

        double dist = distanceBetween(homeX, homeY, wx, wy);
        bool safe = isInSafeZone(wx, wy, homeX, homeY, safeRadius);

        cout << "Waypoint " << i + 1 << " (" << wx << ", " << wy << ")" << endl;
        cout << "  Distance from home : " << dist << endl;
        cout << "  Inside safe zone   : " << (safe ? "Yes" : "No") << endl;
    }

    cout << "\nclamp(120, 0, 100) = " << clamp(120, 0, 100) << endl;
    cout << "toRadians(180) = " << toRadians(180) << endl;

    return 0;
}
