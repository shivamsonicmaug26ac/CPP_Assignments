#include <iostream>
#include <memory>
using namespace std;

class AudioClip {
    string name;
    double duration;

public:

    AudioClip(string name, double duration) : name(name), duration(duration)
    {
        cout << "[Audio Clip Compiled]" << endl;
    }

    ~AudioClip()
    {
        cout << "[Audio Clip Destroyed]" << endl;
    }

    void display() const {
        cout << "Name : " << name << endl;
        cout << "Duration : " << duration << endl;
    }
    string getName()const{
    	return name;
    }
};
int main() {

	// Required structure in main():
	auto audio = make_shared<AudioClip>("explosion", 3.5);
	weak_ptr<AudioClip> observer = audio;
	if (auto clip = observer.lock())
	    cout << "Clip alive: " << clip->getName() << endl;
	audio.reset(); // unload
	if (auto clip = observer.lock()){
		cout << "Clip alive: " << clip->getName() << endl;
		}
		else if (observer.expired()) {
		    cout << "Clip already unloaded." << endl;
		}
	return 0;
}
