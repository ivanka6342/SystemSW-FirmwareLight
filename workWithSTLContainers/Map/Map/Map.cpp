#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>

using namespace std;

void showPair(pair<int, char> p) {
	cout << p.first << " : " << p.second << endl;
}

void showMap(map<int, char> m) {
	if (!m.empty()) {
		cout << "map size: " << m.size()
			<< ", contain:" << endl;
		for_each(m.begin(), m.end(), showPair);
	}
	else cout << "this map is empty" << endl;
}

int main() {
	map<int, char> m1 = { {15, 'D'}, make_pair(34, '/') }, m2;
	for (int i = 2; i >= 0; i--) // different directions of FOR loops show that map is ordered
		m1.insert(make_pair(i, (char)((int)'a'+i)));
	for (int i = 0; i < 5; i++)  // repeated elements are not allowed and not inserts to map again
		m1.emplace(make_pair(i, (char)((int)'a' + i)));
	cout << "map1 after insert(pairs <0-2 : 'a'-'e'>) and emplace(pairs <0-4 : 'a'-'g'>) :" << endl;
	showMap(m1);

	// m.insert(m.begin(), make_pair(10, 'c')); // has no sense because of map is ordered
	// m.emplace_hint(m.begin(), make_pair(10,'c')); // similar situation
	// m.count(); // similar
	// auto it = advance(m.begin(), 3); // not works
	
	cout << endl << "map2:" << endl;
	showMap(m2);

	map<int, char>::iterator mapFindIter = m1.find(0);
	cout << endl << "map1.find(0) matches to pair < " << mapFindIter->first << " : " << mapFindIter->second << " >"<< endl;

	m1.erase(m1.find(4));
	m1.swap(m2);
	m2.at(3) = '*'; // throws an out_of_range exception if not found
	m2[2] = '&'; // construct and insert new element if not found
	m2.erase(4);

	cout << endl << "after map1.swap(map2), map2.at(3) = '*', map2[2]='&', map2.erase(4)" << endl;
	cout << "map1:" << endl;
	showMap(m1);
	cout << endl << "map2:" << endl;
	showMap(m2);

	m2.clear();
	cout << endl << "map2.clear(): ";
	showMap(m2);

	system("pause");
	return 0;
}