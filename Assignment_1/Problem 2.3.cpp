#include <iostream>
using namespace std;

int main() {

    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;

    const int* regPtr1 = &statusReg;
    cout << "Status Register (regPtr1) : " << *regPtr1 << endl;

    regPtr1 = &dataReg;

    int* const regPtr2 = &controlReg;
    *regPtr2 = 0b11111111;
    cout << "Control Register (regPtr2) after write : " << *regPtr2 << endl;

    const int* const regPtr3 = &statusReg;
    cout << "Status Register (regPtr3) : " << *regPtr3 << endl;

    return 0;
}
