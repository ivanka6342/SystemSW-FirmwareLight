#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

// this thread will work with lock-unlock sequence
void funcPlus(int& num, mutex& mtx) {
	while (true) {
		mtx.lock();
			num += 5;
			cout << "thread_id: " << this_thread::get_id() << ", num: " << num << "\n";
		mtx.unlock();
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

// this one will work with try_lock{unlock} construction
void funcMinus(int& num, mutex& mtx) {
	while (true) {
		if (mtx.try_lock()) {
			num -= 5;
			cout << "thread_id: " << this_thread::get_id() << ", num: " << num << "\n";
			mtx.unlock();
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}
}

int main() {
	int num = 25;
	mutex mtx;

	thread thread1(funcPlus, ref(num), ref(mtx));
	thread1.detach();
		
	thread thread2(funcMinus, ref(num), ref(mtx));
	thread2.detach();

	system("pause");
	return 0;
}