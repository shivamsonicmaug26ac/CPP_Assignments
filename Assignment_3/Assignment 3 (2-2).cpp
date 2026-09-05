#include <iostream>
#include <memory>
using namespace std;

class Shader{
	string name;
	string type;

public:

//	int getReferenceCount(const shared_ptr<Shader>& ptr){
//		return ptr.use_count();
//	}

	Shader(string name, string type) : name(name), type(type)
	{
	    cout << " [Shader Compiled]" << endl;
	}
	~Shader()
	{
	    cout << " [Shader Destroyed]" << endl;
	}
	void display()const{

	cout<<"Name : "<<name<<endl;
	cout<<"Type : "<<type<<endl;

	}
};

int getReferenceCount(const shared_ptr<Shader>& ptr)
{
    return ptr.use_count();
}

int main() {
	auto shader = make_shared<Shader>("main_vert", "vertex");
	cout << "Ref count: " << getReferenceCount(shader) << endl; // 1
	{
	 auto rendererRef = shader;
	 cout << "Ref count: " << getReferenceCount(shader) << endl; // 2
	 auto editorRef = shader;
	 cout << "Ref count: " << getReferenceCount(shader) << endl; // 3
	}
	cout << "Ref count: " << getReferenceCount(shader) << endl; // 1
	return 0;
}
