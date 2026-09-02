#include <iostream>
#include <string>
using namespace std;

// --- BONUS PART
int level = 1;

namespace Engine {
    namespace Audio {
        void playSound(string name) {
            cout << "Playing: " << name << endl;
        }
    }
}

int main() {
    int level = 5;
    cout << "Player Level (Local): " << level << endl;
    cout << "Game Difficulty (Global): " << ::level << endl;

    Engine::Audio::playSound("sword_clash");
    cout << endl;


//    for 3*4 start

    int row, cols;
    cin >> row >> cols;

    int **arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 5;
        }
    }

    cout << "===== GAME MAP (" << row << " x " << cols << ") =====" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLegend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon" << endl << endl;

    int grass = 0, water = 0, mountain = 0, forest = 0, dungeon = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            int num = arr[i][j];
            switch (num) {
                case 0: grass++; break;
                case 1: water++; break;
                case 2: mountain++; break;
                case 3: forest++; break;
                case 4: dungeon++; break;
            }
        }
    }

    cout << "Tile Count:" << endl;
    cout << "Grass    : " << grass << endl;
    cout << "Water    : " << water << endl;
    cout << "Mountain : " << mountain << endl;
    cout << "Forest   : " << forest << endl;
    cout << "Dungeon  : " << dungeon << endl;

    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
