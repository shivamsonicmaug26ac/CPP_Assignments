#include <iostream>
using namespace std;

class Entity{

private:
	string name;
	int health;
	int level;
	string type;

public:
//	getters
		string getName() const{
			return name;
		}
		int getHealth() const{
			return health;
		}
		int getLevel() const{
			return level;
		}
		string getType() const{
			return type;
		}
//display start
		 void displayInfo() const{
		        cout<< "----------------" << endl;
		        cout<< "Name\t : " << getName() << endl;
		        cout<< "Health\t : " << getHealth() << endl;
		        cout<< "Level\t : "<< getLevel() << endl;
		        cout<< "Type\t : "<<getType() << endl;
		        cout<<"-----------------"<<endl;
		    }
//display end


//setters

		Entity& setName(const string& name){
			this-> name = name;
			return *this;
		}
		Entity& setHealth(int health){
			this-> health = health;
			return *this;
		}
		Entity& setLevel(int level){
			this-> level = level;
			return *this;
		}
		Entity& setType(const string& type){
			this-> type = type;
			return *this;
		}
};


int main() {

	Entity player, enemy, item;
	player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
	enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
	item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

	player.displayInfo();
	enemy.displayInfo();
	item.displayInfo();

	return 0;
}
