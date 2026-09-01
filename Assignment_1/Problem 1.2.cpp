#include <iostream>
#include <iomanip>
using namespace std;

int N;
double arr[100];

//reading start
void readings(){

	for(int i=0; i<N; i++){
//		cout<<"Enter The Value : ";
		cin>>arr[i];
	}

}
//reading end

//range checking start
void rangeChecking(){
	int skipped = 0;
	cout << fixed << setprecision(1);
for(int i =0; i<N; i++){
	if(arr[i] < 0){
		skipped++;
		continue;
	}
		cout<<arr[i]<<" ";
}
cout << endl;
cout << "Skipped (errors) : " << skipped << endl;
}
//range checking end

//scan reading checking start
void scanReading(){

	for(int i =0; i<N; i++){
		if(arr[i] >= 45){
			cout <<endl<<"First Critical : Index " << i << " -> " << fixed << setprecision(1) << arr[i] << "°C" << endl;
			break;
		}
	}

}
//scan reading checking end

//computeMinMaxAvg is start
void computeMinMaxAvg(){

    double min = 0;
    double max = 0;
    double sum = 0;
    int count = 0;

    for(int i = 0; i < N; i++){

        if(arr[i] < 0){
            continue;
        }

        if(count == 0){
            min = arr[i];
            max = arr[i];
        }
        else{

            if(arr[i] < min){
                min = arr[i];
            }

            if(arr[i] > max){
                max = arr[i];
            }
        }

        sum = sum + arr[i];
        count++;
    }
    double avg = sum / count;

    cout << endl;
        cout << fixed << setprecision(1);
        cout << "Min : " << min << "°C\t";
        cout << "Max : " << max << "°C\t";
        cout << fixed << setprecision(2);
        cout << "Avg : " << avg << "°C" << endl;
}
//computeMinMaxAvg is end

//categoryCount is start
void categoryCount()
{
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for(int i = 0; i < N; i++){

        if(arr[i] < 0){
            continue;
        }

        if(arr[i] < 30){
            normal++;
        }
        else if(arr[i] < 45){
            warning++;
        }
        else if(arr[i] < 60){
            critical++;
        }
        else shutdown++;
    }

    cout << endl;
        cout << "Normal: " << normal << "\t";
        cout << "Warning:" << warning << "\t";
        cout << "Critical:" << critical << "\t";
        cout << "Shutdown:" << shutdown << endl;
}
//categoryCount is end

int main() {
		cin >> N;
	    cout << "Readings entered : " << N << endl;
	    readings();
	    cout << "Valid readings : ";
	    rangeChecking();
	    scanReading();
	    computeMinMaxAvg();
	    categoryCount();
	    return 0;
}
