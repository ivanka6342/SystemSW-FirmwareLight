#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

void printElem(float el) {
	cout << el << " ";
}

void showSet(set<float> &fSet) {
	for_each(fSet.begin(), fSet.end(), printElem);
	cout << endl;
}

int main() {
	set<float> fSet;
	float arr[] = {12.32, 34.34, 87.296, 16.25, -12.03};
	fSet.insert(arr, arr + sizeof(arr)/sizeof(float)); // insert the range of elements(from array)
	cout << "add array of floats:" << endl;
	showSet(fSet);
	
	for (float i = 26; i < 34; i++)
		fSet.emplace(i + i / 100);
	cout << endl << "add some values from range (26;34):" << endl;
	showSet(fSet);

	cout << endl << "set.emplace(26.26): " << std::boolalpha << fSet.emplace(26.26).second << endl;
	cout << "set.emplace(11.192): " << std::boolalpha << fSet.emplace(11.192).second << endl;
	cout << "set.size(): " << fSet.size() << endl;

	fSet.erase(fSet.find(31.31), fSet.find(87.296));
	cout << endl << "delete values in range [31.31 ; 87.296):" << endl;
	showSet(fSet);

	fSet.erase(12.32);
	fSet.erase(fSet.begin());
	cout << endl << "our set after set.erase(12.32) and set.erase(set.begin()):" << endl
		<< "set size: " << fSet.size() << endl;
	showSet(fSet);

	if (fSet.empty()) exit(true);
	fSet.clear();
	cout << endl << "size after clear(): " << fSet.size() << endl;

	system("pause");
	return 0;
}