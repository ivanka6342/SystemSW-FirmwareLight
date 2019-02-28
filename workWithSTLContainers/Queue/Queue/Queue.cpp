#include <queue>
#include <iostream>

using namespace std;

void showQueue(queue<int> q) {
	queue<int> tempQ = q;
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}

int main() {
	queue<int> intQ;
	if (intQ.empty())
		for (int i = 0; i < 5; i++)
			intQ.push(i);
	intQ.back() = 15;
	cout << "queue size: " << intQ.size() << endl 
		<< "first queue contains:" << endl;
	showQueue(intQ);
	cout << endl;
	
	int readInt;
	queue<int> queInt;
	cout << endl << "pls type some numbers. type 0 to stop" << endl;
	do {
		cin >> readInt;
		queInt.emplace(readInt);
	} while (readInt);
	
	cout << endl << "second queue contains:" << endl;
	showQueue(queInt);

	queInt.swap(intQ); // only this definition that swaps queues(not elements inside one queue)

	cout << "queues after swap:" << endl;
	showQueue(intQ);
	cout << endl;
	showQueue(queInt);

	system("pause");
	return 0;
}