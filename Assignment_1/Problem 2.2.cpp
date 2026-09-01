#include <iostream>
#include <cmath>
using namespace std;

double Signal;
double gainFactor;
int n;

//Compute RMS Start Done
double computeRMS(double* Signal, int n){

double sum = 0;
double* ptr = Signal;

for(int i =0; i<n; i++){

	sum += (*ptr) * (*ptr);
	ptr++;
}
return sqrt(sum/n);
}
//Compute RMS end

//Compute normalise Start Done
void normalise(double* Signal, int n){

	double maxVal = 0;
	double* ptr = Signal;

	for(int i=0; i<n; i++){
	    double current = *ptr;
		if(current < 0){
			current = current * -1;
		}
		if(current > maxVal){
			maxVal = current;
		}
	ptr++;
		}

		ptr = Signal;
		for(int i=0; i<n; i++){

			*ptr = *ptr / maxVal;
			ptr++;
		}
	}
//Compute normalise end

//Compute countZeroCrossings Start Done
int countZeroCrossings(double* Signal, int n){

	int count = 0;
	double* ptr = Signal;

	for(int i =0; i<n-1; i++){
		if( (*ptr > 0 && *(ptr+1) < 0) || (*ptr < 0 && *(ptr+1) > 0) ){
		    count++;
		}
		    ptr++;
	}
	return count;
}
//Compute countZeroCrossings end

//Compute ApplyGain Start
void applyGain(double* Signal, int n, double gainFactor){
		double* ptr = Signal;
		for(int i  =0; i<n; i++){
			*ptr = *ptr*gainFactor;
			ptr++;
		}
		}
//Compute ApplyGain end


int main() {

    double Signal[]={0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
    int n=7;

    cout << "Before normalise: ";

    double* ptr = Signal;

    for(int i = 0; i < n; i++){
        cout << *ptr << " ";
        ptr++;
    }

    cout << endl;

    normalise(Signal, n);

    cout << "After normalise: ";

    ptr = Signal;

    for(int i = 0; i < n; i++){
        cout << *ptr << " ";
        ptr++;
    }

    cout << endl;

    cout << "Zero crossings: " << countZeroCrossings(Signal, n) << endl;

    applyGain(Signal, n, 2.0);

    cout << "After gain: ";

    ptr = Signal;

    for(int i = 0; i < n; i++){
        cout << *ptr << " ";
        ptr++;
    }

    cout << endl;

    cout << "RMS: " << computeRMS(Signal, n) << endl;

    return 0;
}

