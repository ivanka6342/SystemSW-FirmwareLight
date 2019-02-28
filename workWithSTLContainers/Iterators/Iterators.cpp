#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

void printElement(int el) {
	cout << el << "  ";
}

// const iterators
void directShowList(list<int> ls, int num) {
	if (!ls.empty()) {
		cout << "list #" << num << " contains: ";
		for (list<int>::const_iterator it = ls.cbegin(); it != ls.cend(); it++)
		{
			printElement(*it);
		}
		cout << "\n";
	}
	else
		cout << "list #" << num << " is empty\n";
}

// const reverse iterators
void reverseShowList(list<int> ls, int num) {
	if (!ls.empty()) {
		cout << "list #" << num << " contains: ";
		for (list<int>::const_reverse_iterator it = ls.rbegin(); it != ls.rend(); it++)
		{
			printElement(*it);
		}
		cout << "\n";
	}
	else
		cout << "list #" << num << " is empty\n";
}

void forwardFillList(list<int> &ls, int a, int b) {
	for (int i = a; i <= b; i++)
		ls.push_back(i);
}

void backwardFillList(list<int> &ls, int a, int b) {
	for (int i = a; i >= b; i--)
		ls.push_back(i);
}

void fillList(list<int> &ls, int a, int b) {
	if (a <= b)
		forwardFillList(ls, a, b);
	else 
		backwardFillList(ls, a, b);
}

int main() {
	list<int> intList1;
	list<int> intList2;
	fillList(intList1, 0, 4);
	fillList(intList2, 9, 5);

	directShowList(intList1, 1);
	directShowList(intList2, 2);

	cout << "\nopeations with forward iterators:\n";
	for (auto it = intList1.begin(); it != intList1.end(); it++)
		*it *= 10;
	for (auto it = intList2.begin(); it != intList2.end(); it++)
		*it *= 10;

	directShowList(intList1, 1);
	directShowList(intList2, 2);

	cout << "\nopeations with backward iterators:\n";
	for (auto it = intList1.rbegin(); it != intList1.rend(); it++)
		*it += 5;
	for (auto it = intList2.rbegin(); it != intList2.rend(); it++)
		*it += 5;

	reverseShowList(intList1, 1);
	reverseShowList(intList2, 2);

	// advance 
	auto it = intList1.begin();
	advance(it, 3);
	cout << "\nlist #1 [3] (by advance op) = " << *it << "\n";

	// prev and next
	auto itn = prev(it, 1);
	cout << "\tprev = " << *itn << "\n";
	itn = next(it, 1);
	cout << "\tnext = " << *itn << "\n";

	// distance
	auto it1 = intList2.begin();
	auto it2 = intList2.end();
	cout << "distanse between list #2 .begin and .end = " << distance(it1, it2) << "\n";

	// swap
	it2--;
	swap(it1, it2);
	cout << "iterators to first and last elements of list #2 after swap(): " << *it1 << " " << *it2 << "\n";

	// begin and end
	cout << "begin and end of the list:\n";
	cout << "\t #1: " 
		<< *begin(intList1) << ", " << *prev(end(intList1), 1) << "\n"
		<< "\t #2: " 
		<< *begin(intList2) << ", " << *prev(end(intList2)) << "\n";
	
	// generators
	cout << "using generators:\n";
	copy(intList2.rbegin(), intList2.rend(), back_inserter(intList1));
	fill_n(inserter(intList2, intList2.end()), 5, 0); // inserts to created position

	directShowList(intList1, 1);
	directShowList(intList2, 2);
	
	fill_n(intList1.rbegin(), 5, 0);                  // replace existing elements
	move(make_move_iterator(intList2.begin()), make_move_iterator(intList2.end()), intList1.begin());
	intList2.clear();
	intList1.swap(intList2);

	cout << "\nafter move(2 to 1), clear(2) and swap:\n";
	directShowList(intList1, 1);
	directShowList(intList2, 2);

	system("pause");
	return 0;
}