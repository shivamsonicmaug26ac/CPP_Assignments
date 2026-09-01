#include <iostream>
#include <iomanip>
using namespace std;

double readTem[3][3];

//Read Temprature start
void temRead(double readTem[3][3]){
	for(int i =0; i<3; i++){
		for(int j =0; j<3; j++){
			cin >> readTem[i][j];
		}
	}

}
//Read Temprature end

//Get Temprature start
void getTeam(double readTem[3][3]){
	cout << fixed << setprecision(1);
	for(int i = 0; i < 3; i++){
		cout << "Floor " << i + 1 << " : ";
	    for(int j = 0; j < 3; j++){
	    	cout << readTem[i][j]<<"\t";
	    }
	    cout << endl;
	}
}
//Get Temprature end

//find temprature start
void findTem(double readTem[3][3]){

	double max = readTem[0][0];
	int maxFloor = 0;
	int maxRoom = 0;
	for(int i = 0; i < 3; i++){
	    for(int j = 0; j < 3; j++){
	        if(readTem[i][j] > max){
	        	max = readTem[i][j];
	        	maxFloor = i;
	        	maxRoom = j;

	        }
	    }
	}
	cout << fixed << setprecision(1);
	    cout << "Hottest Room : Floor " << maxFloor + 1 << ", Room " << maxRoom + 1 << " → " << max << "°C" << endl;
}
//find temprature end

//find hottest floor start
void hotFloor(double readTem[3][3]){
		double maxAvg = 0;
		int hottestFloor = 0;

		for(int i = 0; i < 3; i++){
		        double sum = 0;
		        for(int j = 0; j < 3; j++){
		            sum = sum + readTem[i][j]; // simple addition
		        }
		        double avg = sum / 3.0;

		        if(avg > maxAvg){
		            maxAvg = avg;
		            hottestFloor = i;
		        }
		    }

		    cout << fixed << setprecision(2);
		    cout << "Hottest Floor : Floor " << hottestFloor + 1 << " (avg " << maxAvg << "°C)" << endl;
		}
//find hottest floor end

//warning room start
void warnRooms(double readTem[3][3]){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(readTem[i][j] >= 30.0){
                count = count + 1; // simple counter
            }
        }
    }
    cout << "Rooms at WARNING or above : " << count << endl;
}
//warning room end

int main() {
//	cout<<"enter the room tempreture : ";
	temRead(readTem);
	cout << "        Room1\tRoom2\tRoom3" << endl;
	getTeam(readTem);
	findTem(readTem);
	hotFloor(readTem);
	warnRooms(readTem);
	return 0;
}
