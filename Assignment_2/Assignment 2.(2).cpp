#include <iostream>
#include <memory>
using namespace std;

class Patient{
	int patientId;
	string name;
	int age;
	string ward;
	const string bloodGroup;

public :

// Getters start
	int getpatientId() const{
		return patientId;
	}

	string patientName() const{
		return name;
	}

	int patientAge() const{
		return age;
	}

	string patientWard() const{
		return ward;
	}

	string patientBloodGroup() const{
		return bloodGroup;
	}

//	Setters start

void setPatientID(int patientId){
this-> patientId = patientId;
}

void setPatientName(const string& patientName){
this-> name = patientName;
}

void setAge(int patientAge){
	this-> age = patientAge;
}

void setWard(const string& patientWard){
	this-> ward = patientWard;
}

//constructor start
//constructor 1
Patient(): patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+"){
cout << "[Constructor] Default patient registered." << endl;
}
//constructor 2
Patient(int id, const string& name) : bloodGroup("O+"), age(0), ward("General"){
patientId = id;
this-> name = name;
cout << "[Constructor] Emergency: " << name << endl;
}
//constructor 3
Patient (int id, const string& name, int age, const string& ward, const string& bloodGroup): bloodGroup(bloodGroup){
patientId = id;
this-> name = name;
this-> age = age;
this-> ward = ward;
cout << "[Constructor] Full admission: " << name << endl;
}
//constructor end

//Distructor start
~Patient(){

	cout << "[Destructor] Patient " << name << " discharged." << endl;

}

//For display
void displayRecord() const{

	cout<<"Patient Record: " << endl;
	cout<<"ID\t : " <<getpatientId()<< endl;
	cout<<"Name\t : " <<patientName()<< endl;
	cout<<"Age\t : " <<patientAge()<< endl;
	cout<<"Ward\t : " <<patientWard()<< endl;
	cout<<"Blood Grp\t : " << patientBloodGroup() << endl;
}

//for transfer
void transferWard(const string& newWard){
	ward = newWard;
	cout << "Ward Transfer: " << patientName() << " -> " << newWard << endl;
}
};
int main() {



//	with input start

//	defalult start 1

	Patient pa1(1001, "Meera Joshi", 34, "Cardiology", "B+");

	Patient pa2(1002, "Raj Patel");

	Patient pa3;

	Patient* record = new Patient[4];
	pa1.displayRecord();
//	with input end

//	loop for call display record start
	for(int i=0; i<4; i++){
		record[i].displayRecord();
	}
//	loop for call display record end
	pa2.transferWard("ICU");


//	delete memory

	delete[] record;

	return 0;
};


//	Passed Values start

//	Patient pa1;
//
//	Patient pa2(1001, "Lilawati");
//
//	Patient pa3(1002, "Kamlawati", 56, "Genral_1", "AA -");
//Patient *record = new Patient[4];
//	pa3.displayRecord();
//	Passed Values end



//int id, age;
//		string name, ward, bloodgroup;
//
//		cout<<"Enter Patient ID : ";
//		cin>> id;
//
//		cout<<"Enter Patient name : ";
//		cin>> name;
//
//		cout<<"Enter Patient Age : ";
//		cin>> age;
//
//		cout<<"Enter Patient ward : ";
//		cin>> ward;
//
//		cout<<"Enter Patient BloodGroup : ";
//		cin>> bloodgroup;
//
//		 Patient pa1(id, name, age, ward, bloodgroup); //constructor 3 call hoga
