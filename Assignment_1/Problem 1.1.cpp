#include <iostream>
using namespace std;

//Range start

int getRange(double range){

	if(range < 0){
		return -1;
	}else if(range >= 0 && range <= 29){
		return 0;
	}else if(range >= 30 && range <= 44){
		return 1;
	}else if(range >= 45 && range <= 59){
		return 2;
	}else{
		return 3;
	}
}

//Range end

//Action is start

void statusLable(int range){

	switch(range){
		case -1 : cout<<"SENSOR_ERROR";
				 cout<<"Sensor fault — check wiring";
				 break;

		case 0 : cout<<"NORMAL";
		         cout<<"No action required";
		         break;

		case 1:
		    cout << "Status : WARNING" << endl;
		    cout << "Action : Alert sent to supervisor" << endl;
		    break;

		case 2:
		    cout << "Status : CRITICAL" << endl;
		    cout << "Action : Cooling system triggered" << endl;
		    break;

		case 3:
		    cout << "Status : SHUTDOWN" << endl;
		    cout << "Action : Emergency shutdown initiated" << endl;
		    break;

		default:
		    cout << "Invalid status" << endl;
		    break;
	}
}
//Action is end.

int main() {
	double rangeValue;

	cout<<"Enter Reading : ";
	cin>>rangeValue;

	double fahrenheit = (rangeValue * 9.0 / 5.0) + 32;

	cout << "Temperature : " << rangeValue << "C / "<< fahrenheit << "F" << endl;

	int statusCode = getRange(rangeValue);
	statusLable(statusCode);

	cout << "Reading : "<< ((rangeValue >= 25) ? "Above Average" : "Below Average")<< endl;

	return 0;
}
