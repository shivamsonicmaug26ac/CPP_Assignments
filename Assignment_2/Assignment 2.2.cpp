#include <iostream>
using namespace std;

// integer quantity start
double reorderCost(int quantity, double unitPrice){
return quantity * unitPrice;
}; // integer quantity end

// fractional (by weight) start
double reorderCost(double qty, double unitPrice){
return qty * unitPrice;
}; // fractional (by weight) end

// with tax start
double reorderCost(int qty, double unitPrice, double taxRate){
double cost = qty * unitPrice;
return cost + (cost*taxRate/100);
}; // with tax end

//apply discoutn start
double applyDiscount(double price, double discountPercent = 10.0){
return price - (price * discountPercent/100);
};
//apply discoutn end


int main() {

	double ini = reorderCost(10, 30);
	cout<<"The Cost is : "<<ini<<endl;

	double ini1 = reorderCost(10.33, 11.23);
	cout<<"The Cost is : "<<ini1<<endl;

	double ini2 = reorderCost(7, 10.11, 10);
	cout<<"The Cost is : "<<ini2<<endl;

	double ini3 = applyDiscount(110);
	cout<<"The Cost is : "<<ini3<<endl;

	return 0;
}
