#include <queue>
#include <iostream>
#include <ctime>

using namespace std;

void showPriorityQueue(priority_queue<int> q) {
	priority_queue<int> tempQ = q;
	while (!tempQ.empty()) {
		cout << tempQ.top() << endl;
		tempQ.pop();
	}
}

int main() {
	priority_queue<int> pQ1, pQ2;
	
	// init first queue by push'ing random numbers
	srand(time(0));
	for (int i = 0; i<5; i++)
		pQ1.push(rand()%100);
	cout << "queue1:" << endl;
	showPriorityQueue(pQ1);

	// init second queue by emplace'ing random numbers
	cout << endl << "queue2: " << endl;
	for (int i = 0; i < 10; i++)
		pQ2.emplace(rand() % 100);
	showPriorityQueue(pQ2);
	
	// swap and show queues
	pQ1.swap(pQ2);
	for (int i = 5; i--;)
		pQ1.pop();

	cout << endl << "queues after swap and pop() some elements" << endl;
	showPriorityQueue(pQ1);
	cout << endl;
	showPriorityQueue(pQ2);

	system("pause");
	return 0;
}