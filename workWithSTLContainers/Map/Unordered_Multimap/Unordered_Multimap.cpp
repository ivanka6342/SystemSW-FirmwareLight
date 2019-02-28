#include <iostream>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

void showElement(pair <string, double> pp) {
	cout << "\"" << pp.first << "\" : " << pp.second << endl;
}

void showUOMMap(unordered_multimap <string, double> mp, int num) {
	if (!mp.empty()) {
		cout << "UO MMap #" << num << " include next pairs:"<< endl;
		for_each(mp.begin(), mp.end(), showElement);
	}
	else {
		cout << "UO MMap #" << num << " is empty" << endl;
	}
}

int main() {
	pair <string, double> initArr[] = { {"Alex", 12.3}, {"Albert", -123.66}, {"Ivan", 1500.45}, {"Roger", 61.0}, {"Alex", 15.6} };

	unordered_multimap <string, double> mmp1;
	unordered_multimap <string, double> mmp2;
	showUOMMap(mmp1, 1);
	showUOMMap(mmp2, 2);

	cout << endl << "try to fill containers:" << endl;
	mmp1.insert(initArr, initArr+sizeof(initArr)/sizeof(initArr[0]));
		
	for (int i = 0; i < 3; i++)
		mmp2.emplace(make_pair("Andrew", i*111.11));

	showUOMMap(mmp1, 1);
	showUOMMap(mmp2, 2);

	cout << endl << "try to find value by key \"Roger\" : " << mmp1.find("Roger")->second << endl;
	
	cout << "swap containers and change some values" << endl;
	mmp1.swap(mmp2);
	mmp1.clear();
	mmp2.erase(mmp2.find("Alex"));
	mmp2.erase("Roger");

	auto func = mmp2.hash_function();
	cout << endl << "apply mmp2-hash-function in relation to \"some string\": " << func("some string") << endl << endl;

	showUOMMap(mmp1, 1);
	showUOMMap(mmp2, 2);

	system("pause");
	return 0;
}