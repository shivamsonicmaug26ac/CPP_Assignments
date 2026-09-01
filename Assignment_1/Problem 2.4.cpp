#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size, int** outMin, int** outMax) {

    if (size <= 0) {
        return false;
    }

    const int* minAddr = &rawData[0];
    const int* maxAddr = &rawData[0];

    for (int i = 1; i < size; i++) {
        if (rawData[i] < *minAddr) {
            minAddr = &rawData[i];
        }
        if (rawData[i] > *maxAddr) {
            maxAddr = &rawData[i];
        }
    }

    *outMin = const_cast<int*>(minAddr);
    *outMax = const_cast<int*>(maxAddr);

    return true;
}

int main() {

    int packet[] = {45, 12, 67, 8, 55, 31};
    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    } else {
        cout << "Invalid packet size" << endl;
    }

    return 0;
}
