#include <iostream>
#include <windows.h>
#include <thread>

using namespace std;

void func2() {
	this_thread::sleep_for(chrono::milliseconds(5000));
	for (int i = 0; i < 3; i++) {
		cout << "Second level thread, id:" << this_thread::get_id() << endl;
		Sleep(1000);
	}
}

void func() {
	thread thread(func2);
	thread .detach();
	for (int i = 0; i < 2; i++) {
		cout << "First level thread, id:" << this_thread::get_id() << endl;
		Sleep(500); 
	}
}

int main() {
	cout << "Main thread, id: " << this_thread::get_id() << endl;
	cout << "hardware concurrency(virtual core number): " << thread::hardware_concurrency() << endl;

	for (int i = 0; i < 2; i++) {
		thread thread(func);
		if (thread.joinable())
			thread.join(); // now main thread wait the execution of first level thread
	}

	system("pause");
	return 0;
}