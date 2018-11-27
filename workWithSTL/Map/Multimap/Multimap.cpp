#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

void showMapPair(pair<string, double> p) {
	cout << p.first << " : " << p.second << endl;
}

void showMMap(multimap<string, double> mmap) {
	if (!mmap.empty()) {
		cout << "multimap size: " << mmap.size() << ", contain:" << endl;
		for_each(mmap.begin(), mmap.end(), showMapPair);
	}
	else cout << "this multimap is empty" << endl;

}

int main() {
	multimap<string, double> mmap1, mmap2 = { {"John", 13.52}, {"Kenny", 18.1}, make_pair("Daniel", 911.666) };
	for (double i = 0; i < 2; i++)
		mmap1.emplace(make_pair("query1", i + i/100));
	vector< pair<string, double> > v = { {"query2", 12.51}, {"query3", 42.42}, {"query4", 18.25} };
	mmap1.insert(v.begin(), v.end()); // insert from vector as range
	cout << "Insert and emplace to the 1st MMap:" << endl;
	showMMap(mmap1);
	cout << endl << "Result of the 2nd MMap copy constructor:" << endl;
	showMMap(mmap2);

	mmap1.swap(mmap2);
	mmap1.clear();

	cout << endl << "After swap() MMaps and clear() the 1st one, the 1st is:" << endl;
	showMMap(mmap1);

	cout << endl
		<< "Count of elements with the key 'query1' in the 2nd MMap: "
		<< mmap2.count("query1")
		<< endl;
	if (mmap2.find("query1") == mmap2.begin()) 
		cout << "MMap2.find('query1') returns iterator to first entry of element with equivalent key" << endl;
	mmap2.erase("query1");
	cout << endl << "MMap2 after erase('query1')" << endl;
	showMMap(mmap2);

	system("pause");
	return 0;
}