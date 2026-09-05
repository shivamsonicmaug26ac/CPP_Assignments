#include <iostream>
#include <memory>
using namespace std;

class Texture{
string name;
int width;
int height;

public:

Texture(string name, int width, int height) : name(name), width(width), height(height)
{
    cout << "[Texture Loaded]" << endl;
}
~Texture()
{
    cout << "[Texture Released]" << endl;
}
void display()const{

cout<<"Name : "<<name<<endl;
cout<<"Width : "<<width<<endl;
cout<<"Height : "<<height<<endl;

}
};

int main() {
	unique_ptr<Texture> text1 = make_unique<Texture>("player_sprite", 512, 512);
	text1->display();
//	unique_ptr<Texture> text2 = text1;
	unique_ptr<Texture> text2 = std::move(text1);
	cout<<"Text is null: "<<(text1 == nullptr ? "Yes":"No")<<endl;
	return 0;
}
