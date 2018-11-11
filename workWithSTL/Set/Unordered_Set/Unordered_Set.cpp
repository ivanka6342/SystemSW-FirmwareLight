#include <iostream>
#include <unordered_set>
#include <iterator>
#include <algorithm>

using namespace std;

void showElem(int el) {
	cout << el << " ";
}

void showUOSet(unordered_set<int> &uos, int num) {
	cout << "uo-set " << num << " size: " << uos.size() << endl;
	if (!uos.empty())
		for_each(uos.begin(), uos.end(), showElem);
	else cout << "empty";
	cout << "\n\n";
}

int main() {
	unordered_set<int> uoSetInt0;                                        // empty unordered_set - default constructor
	unordered_set<int> uoSetInt1({ 12, 19, 4, 35, 91, 3, 32 });          // constructor with initializer list
	unordered_set<int> uoSetInt2(uoSetInt1.begin(), uoSetInt1.find(91)); // range constructor
	unordered_set<int> uoSetInt3({ 65, 82, 14, 13, 64, 45 });
	unordered_set<int> uoSetInt3copy(uoSetInt3);                         // copy of uoSetInt3

	showUOSet(uoSetInt0, 0);
	showUOSet(uoSetInt1, 1);
	showUOSet(uoSetInt2, 2);
	showUOSet(uoSetInt3, 3);
	showUOSet(uoSetInt3copy, 4);

	cout << "insert array to uoset0" << endl;
	int arr[] = {42, 13, 109};
	if (uoSetInt0.empty()) uoSetInt0.insert(arr, arr + sizeof(arr)/sizeof(int));

	cout << "emplace 7, 24 and 35 to uoset1. insert range uoset1[24;35) to uoset2" << endl;
	uoSetInt1.emplace(7);
	uoSetInt2.insert(uoSetInt1.emplace_hint(uoSetInt1.begin(), 24), uoSetInt1.emplace(35).first);

	cout << "clear uoset3, erase 82 from uoset4"<< endl << endl;
	uoSetInt3.clear();
	uoSetInt3copy.erase(82);

	showUOSet(uoSetInt0, 0);
	showUOSet(uoSetInt1, 1);
	showUOSet(uoSetInt2, 2);
	showUOSet(uoSetInt3, 3);
	showUOSet(uoSetInt3copy, 4);

	system("pause");
	return 0;
}