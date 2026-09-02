#include <iostream>
using namespace std;

namespace Physics {
 double clamp(double val, double min, double max){
	 return (val < min)? min : (val > max)? max : val;
 }
 double lerp(double a, double b, double t){
	 return a + t * (b - a);
 }
}


namespace GameMath {
 int clamp(int val, int min, int max){
	 return (val < min)? min : (val > max)? max : val;
 }
 double lerp(double a, double b, double t){
	 return a + t * (b - a);
 }
}

int main() {

	cout<<"For Physics clamp: "<< Physics::clamp(120.0, 0.0, 100.0)<<endl;
	cout<<"For Game Math clamp : "<< GameMath::clamp(-10, 0, 100)<<endl;

	cout<<"For Physics lerp: "<< Physics::lerp(0.0, 10.0, 0.5)<<endl;
	cout<<"For Game Math lerp : "<< GameMath::lerp(0.0, 100.0, 0.2)<<endl;

	cout << endl;

	{
		using namespace GameMath;
		cout<<"Inside the block scope of clamp"<<clamp(50, 0, 10)<<endl;
	}
	{
	    using namespace Physics;
	    cout << "Physics Clamp: " << clamp(150.0, 0.0, 100.0) << endl;
	}


	return 0;
}


