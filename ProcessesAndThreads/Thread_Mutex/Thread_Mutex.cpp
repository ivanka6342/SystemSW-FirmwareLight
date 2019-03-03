#include <iostream>
#include <thread>
#include <mutex>

#include "Storage.h"

using namespace std;

void producer(Storage& storage, mutex& mtx, int direction) {
	int num = 0;
	int sum;

	if (direction)
		sum = 1;
	else
		sum = -1;

	while (true) {
		this_thread::sleep_for(chrono::milliseconds(1000));

		lock_guard<mutex> lock(mtx);
		num += sum;
		storage.addElem(num);
		cout << "producer" << direction << " add number : " << num << "\n";
	}
}

void consumer(Storage& storage, mutex& mtx, int num) {
	while (true) {
		this_thread::sleep_for(chrono::milliseconds(1000));

		lock_guard<mutex> lock(mtx);
		cout << "consumer" << num << " get number : ";
		if (storage.isAvailable())
			cout << storage.getElem() << "\n";
		else
			cout << "not available\n";
	}
}

int main() {
	mutex mtx;
	Storage storage;

	thread consumer1(consumer, ref(storage), ref(mtx), 1);
	thread consumer2(consumer, ref(storage), ref(mtx), 2);
	thread producer1(producer, ref(storage), ref(mtx), 0);
	thread producer2(producer, ref(storage), ref(mtx), 1);

	if (consumer1.joinable()) 
		consumer1.join();
	if (consumer2.joinable())
		consumer2.join();
	if (producer1.joinable())
		producer1.join();
	if (producer2.joinable())
		producer2.join();

	system("pause");
	return 0;
}