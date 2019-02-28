#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

void showListElement(double value) {
	cout << value << endl;
}

void showList(list<double> ls) {
	cout << "current list:" << endl;
	for_each(ls.begin(), ls.end(), showListElement);
}

void showReverseList(list<double> ls) {
	cout << "current reverse list:" << endl;
	for_each(ls.rbegin(), ls.rend(), showListElement);
}

// purposeless function just for using some similar methods of std::List
void madTripleFrontInsert(list<double> &ls, double value) {
	ls.push_front(value);
	ls.emplace_front(value);
	ls.emplace(ls.begin(), value);
}

// purposeless function just for using some similar methods of std::List
void madTripleBackInsert(list<double> &ls, double value) {
	ls.push_back(value);
	ls.emplace_back(value);
	ls.emplace(ls.end(), value);
}

int main() {
	list<double> doubleList;
	double doubleArr[] = {123.3, 12.6, 75.87, 96.64, 34.02};
	doubleList.insert(doubleList.begin(), doubleArr, doubleArr+sizeof(doubleArr)/sizeof(double)); // works like a range()
	showList(doubleList);
	doubleList.resize(10);
	cout << endl << "size of list(after resize) now: " << doubleList.size() << endl;

	auto it = doubleList.begin();
	advance(it, 5); // offset iterator right to 5th position(0,1,2,3,4)V(5,6,7,...)
	doubleList.insert(it, 4, 12.21); // works like a fill()
	cout << endl << "after list.insert() - ";
	showList(doubleList);


	list<double> doubleList2;
	madTripleFrontInsert(doubleList2, 132.56);
	madTripleBackInsert(doubleList2, 12.198);
	cout << endl << "the second(new) - ";
	showList(doubleList2);
	doubleList2.erase(doubleList2.begin());
	doubleList2.remove(12.198);
	showReverseList(doubleList2);

	doubleList2.swap(doubleList);
	doubleList.clear();
	doubleList.assign(5, 1.2);
	doubleList.pop_front();
	doubleList.pop_back();

	doubleList2.sort();

	cout << endl << "now(after swap and sort) first and second lists looks so:" << endl;
	showList(doubleList);
	showList(doubleList2);

	system("pause");
	return 0;
}