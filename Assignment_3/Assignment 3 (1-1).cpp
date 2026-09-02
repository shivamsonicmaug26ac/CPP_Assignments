#include <iostream>
using namespace std;

enum class HttpStatus{

	OK = 200,
	Created = 201,
	BadRequest = 400,
	Unauthorized = 401,
	NotFound = 404,
	ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint){

switch(status){
	case HttpStatus::OK:
		cout<<"Request is :"<<static_cast<int>(status)<<"Resousrce is Ok"<<endl;
	break;
	case HttpStatus::Created:
		cout<<"Request is :"<<static_cast<int>(status)<<"Resousrce is created"<<endl;
	break;
	case HttpStatus::BadRequest:
		cout<<"Request is :"<<static_cast<int>(status)<<"\t"<<"Resousrce is Bad Request"<<endl;
	break;
	case HttpStatus::Unauthorized:
		cout<<"Request is :"<<static_cast<int>(status)<<"\t"<<"Resousrce is Unauthorized"<<endl;
	break;
	case HttpStatus::NotFound:
		cout<<"Request is :"<<static_cast<int>(status)<<"\t"<<"Resousrce is Not Found"<<endl;
	break;
	case HttpStatus::ServerError:
		cout<<"Request is :"<<static_cast<int>(status)<<"\t"<<"Here is server error"<<endl;
	    break;
}

cout << "Endpoint : " << endpoint<<endl;

}

int main() {
	handleResponse(HttpStatus::OK, "/Home");
	handleResponse(HttpStatus::Created, "/CreatedBy");
	handleResponse(HttpStatus::BadRequest, "/BadRequestBY");
	handleResponse(HttpStatus::Unauthorized, "/UnauthorizedBy");
	handleResponse(HttpStatus::NotFound, "/NotFound");
	handleResponse(HttpStatus::ServerError, "/ServerError");

	return 0;
}
