#include <iostream>
#include <unordered_set>
#include <iterator>
#include <algorithm>

using namespace std;

void showElem(int el) {
	cout << el << " ";
}

void showUOMSet(unordered_multiset<int> &uoms, int num) {
	cout << "uo-mset #" << num << " size: " << uoms.size() << ", bucket count: " << uoms.bucket_count() << "( ";
	for (int i = 0; i < uoms.bucket_count(); i++) cout << uoms.bucket_size(i) << " ";
	cout << ")" << endl;

	if (!uoms.empty()) {
		auto it = uoms.begin();
		while (it != uoms.end()) {
			cout << "count of " << *it << " : " << uoms.count(*it) << endl;
			for (int i = 0; i < uoms.count(*it); i++) {
				it++;
				if (it == uoms.end()) break;
			}
		}
	}
	else cout << "empty";

	cout << endl;
}

int main() {
	cout << "construct uomsets:" << endl;
	int arr[] = { 3,5,7,9 };
	unordered_multiset<int> uomSetInt0;                                       // default constructor
	unordered_multiset<int> uomSetInt1({ 1,2,3,2 });                          // constructor with init list
	unordered_multiset<int> uomSetInt2(uomSetInt1);                           // copy constructor
	unordered_multiset<int> uomSetInt3(arr, arr + sizeof(arr) / sizeof(int)); // range constructor

	showUOMSet(uomSetInt0, 0);
	showUOMSet(uomSetInt1, 1);
	showUOMSet(uomSetInt2, 2);
	showUOMSet(uomSetInt3, 3);

	cout << "\n\nuomset1.emplace(3x3), uomset2.insert(arr), swap(uomset0, uomset1), uomset0.erase(2), uomset3.clear\n";
	for (int i = 0; i < 3; i++) uomSetInt1.emplace(3);
	uomSetInt2.insert(arr, arr + sizeof(arr) / sizeof(int));
	swap(uomSetInt0, uomSetInt1);
	uomSetInt0.erase(2);
	uomSetInt3.clear();

	showUOMSet(uomSetInt0, 0);
	showUOMSet(uomSetInt1, 1);
	showUOMSet(uomSetInt2, 2);
	showUOMSet(uomSetInt3, 3);

	system("pause");
	return 0;
}