#include <iostream>
#include <vector>
using namespace std;

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

void printHeaders(const HeaderList& Headers){

	for(const auto& h : Headers ){

		cout<<" "<<h.first<<"\t"<<":"<<h.second<<endl;

	}

}

typedef unsigned long long RequestId;

int main() {
	HeaderList myHeaders = {
	    {"Content-Type", "application/json"},
	    {"Authorization", "Bearer eyJhbGci..."},
	    {"Accept-Language", "en-US"}
	};
	RequestId reqId = 123456;
	Port port = 8000;

	cout << "Request ID  : " << reqId << endl;
	cout << "Server Port : " << port << endl << endl;
	cout << "Headers:" << endl;

	printHeaders(myHeaders);
	return 0;
}
