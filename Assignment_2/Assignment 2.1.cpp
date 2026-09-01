#include <iostream>
using namespace std;

class Product{
	int productId;
	string name;
	double price;
	int quantity;

public:

	void acceptDetails(){
		cin >> productId;
		cin >> name;
		cin >> price;
		cin >> quantity;
	}

	//	For the display start
	void displayDetails()const{

		cout << productId << "\t"
		         << name << "\t"
		         << price << "\t"
		         << quantity << "\t"
		         << totalValue() << endl;
		}
	//	For the display end

	double totalValue()const{

		return price*quantity;

		}

		//	name return start
	string nameReturn() const{

return name;

	}
		//	name return end

		//	low stock check start
	bool isLowStock(int threshold) const{

		 return quantity < threshold;

		}
};
		//	low stock check end

int main() {
	Product cloth[5];

//	Loop for accept details is start
for(int i =0; i<5; i++){
	cloth[i].acceptDetails();
}
//	Loop for accept details is end
	cout << "===== INVENTORY REPORT =====" << endl;
	    cout << "ID\tName\tPrice\tQty\tTotal Value" << endl;

//display product
	for(int i =0; i<5; i++){
		cloth[i].displayDetails();
	}
//display produc

//	product highest value find start
	int maxIndex = 0;
	double maxValue = cloth[0].totalValue();
	for(int i=0; i<5; i++){
		if(cloth[i].totalValue() > maxValue){
			maxValue = cloth[i].totalValue();
			maxIndex = i;
		}
	}
//	product highest value find end

//	product highest value print start
	cout << endl;
	cout << "Highest Value Product : "
	     << cloth[maxIndex].nameReturn()
	     << " (Rs. " << maxValue << ")" << endl;
//	product highest value print start


//	threshold loop check start
	int threshold;

		cout << "Enter threshold: ";

		cin >> threshold;

		cout << "Low Stock (Threshold: " << threshold << ") : ";

		bool first = true;
		for(int i=0; i<5; i++){

		    if(cloth[i].isLowStock(threshold)){

		        if(first == false){

		            cout << ", ";
		        }

		        cout << cloth[i].nameReturn();

		        first = false;
		    }
		}

//	//	threshold loop check end


	return 0;
}

