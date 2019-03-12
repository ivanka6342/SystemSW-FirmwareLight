#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <string>
#include <functional>

using namespace std;

// create log notes
void func2(condition_variable& cv, bool& flag) {
	mutex mtx;
	unique_lock<mutex> ulck(mtx);
	ofstream log;
	string str;
	int num = 0;

	while (true) {
		while (!flag) 
			cv.wait(ulck);
		
		log.open("myLog.log", ios_base::app);
		str = "func2: " + to_string(++num) + "\n";
		log.write(str.c_str(), str.length());
		log.close();

		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

// change condition_variable state asking user 
// control lifetime of thread2
void func1(condition_variable& cv) {
	bool flag = false;

	thread thread2(func2, ref(cv), ref(flag));
	thread2.detach();

	while (true) {
		char ch;
		cout << "want to extend file? - (yY/nN): ";
		cin >> ch;
		cin.clear();

		if (ch == 'y' || ch == 'Y') {
			flag = true;
			cv.notify_one();
		}
		else if (ch == 'n' || ch == 'N')
			flag = false;		
	}
}

// control lifetime of thread1
int main() {
	condition_variable cv;

	thread thread1(func1, ref(cv));
	thread1.join();

	system("pause");
	return 0;
	}