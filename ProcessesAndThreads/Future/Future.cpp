#include <iostream>
#include <thread>
#include <future>

using namespace std;
using namespace chrono;

bool task(int n) {
	cout << n << ": begin\r\n";
	this_thread::sleep_for(milliseconds(500));
	cout << n << ": end\r\n";
	return true;
}

void task_f(future<int>& f) {
	int n = f.get();
	cout << n << ": begin\r\n";
	this_thread::sleep_for(milliseconds(2000));
	cout << n << ": end\r\n"
		<< "\tDONE 3\r\n";
}

int main() {
	// create thread and wait returned value
	future<bool> ft = async(task, 3);
	if (ft.get())
		cout << "\tDONE 1\r\n";

	// create thread and wait returned value
	packaged_task<bool(int)> ptsk(task);
	future<bool> ret = ptsk.get_future();
	thread thr1(move(ptsk), 2);
	if (ret.get())
		cout << "\tDONE 2\r\n";
	thr1.join();

	// self set return future value
	promise<int> prom;
	future<int> fut = prom.get_future();
	thread thr2(task_f, ref(fut));
	this_thread::sleep_for(milliseconds(2000));
	prom.set_value(1);
	thr2.join();

	system("pause");
	return 0;
}