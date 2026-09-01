#include<iostream>
using namespace std;

//Version 1 start
void resetSensorPairV1(int reading1, int reading2){
int resetswap1 = reading1;
	reading1 = reading2;
	reading2 = resetswap1;
}
//Version 1 end

//Version 1 start
void resetSensorPairV2(int& reading1, int& reading2){
int resetswap2 = reading1;
	reading1 = reading2;
	reading2 = resetswap2;
}
//Version 1 end

//Version 1 start
void resetSensorPairV3(int* reading1, int* reading2){
int resetswap3 = *reading1;
	*reading1 = *reading2;
	*reading2 = resetswap3;
}
//Version 1 end


int main(){

	int reading1 = 55;
	int reading2 = 12;

//version 1 test
	cout << "--- V1: Call by Value ---" << endl;
	    cout << "Before : A=" << reading1 << " B=" << reading2 << endl;
	    resetSensorPairV1(reading1, reading2);
	    cout << "After  : A=" << reading1 << " B=" << reading2 << " <- values unchanged" << endl;
	    //version 1 test

//version 2 test
	    cout << "--- V2: Call by Reference ---" << endl;
	        cout << "Before : A=" << reading1 << " B=" << reading2 << endl;
	        resetSensorPairV2(reading1, reading2);
	        cout << "After  : A=" << reading1 << " B=" << reading2 <<" <- values Swaped" <<  endl;
//version 3 test

//	        version 3 test
	        cout << "--- V3: Call by Pointer ---" << endl;
	            cout << "Before : A=" << reading1 << " B=" << reading2 << endl;
	            resetSensorPairV3(&reading1, &reading2);
	            cout << "After  : A=" << reading1 << " B=" << reading2 <<" <- values Swaped Back" <<  endl;
	        //	        version 3 test

}
