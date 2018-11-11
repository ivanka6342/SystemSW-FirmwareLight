#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

void printElem(int el) {
	cout << el << " ";
}

void showSet(multiset<int> &ms) {
	for_each(ms.begin(), ms.end(), printElem);
	cout << endl;
}

void countOfEach(multiset<int> &ms) {
	auto it = ms.begin();
	while (it != ms.end()) {
		cout << "count of " << *it << " : " << ms.count(*it) << endl;
		for (int i = 0; i < ms.count(*it); i++) {
			it++;
			if (it == ms.end()) break;
		}
	}
	cout << endl;
}

int main() {
	multiset<int> mSetInt;

	int arr[] = {12, 64, 95, 131, 14};
	mSetInt.insert(arr, arr + sizeof(arr) / sizeof(float)); // insert the range of elements(from array)
	cout << "add array of int:" << endl;
	showSet(mSetInt);

	for (int i = 12; i < 15; i++)
		mSetInt.emplace(i);
	cout << endl << "add some values from range [12;14]:" << endl;
	showSet(mSetInt);

	cout << endl;
	countOfEach(mSetInt);

	mSetInt.erase(mSetInt.find(13), mSetInt.find(64));
	cout << "delete values in range [13 ; 64):" << endl;
	showSet(mSetInt);

	mSetInt.erase(12);
	mSetInt.erase(mSetInt.begin());
	mSetInt.erase(77);
	cout << endl << "our multiset after mset.erase(12), mset.erase(set.begin()) and mset.erase(77):" << endl
		<< "set size: " << mSetInt.size() << endl;
	showSet(mSetInt);

	if (mSetInt.empty()) exit(true);
	mSetInt.clear();
	cout << endl << "size after clear(): " << mSetInt.size() << endl;


	system("pause");
	return 0;
}