#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

void showElement(pair <string, string> pp) {
	cout << "\t \"" << pp.first << "\" : \"" << pp.second << "\"" << endl;
}

void showUOMap(unordered_map<string, string> uomap, int num) {
	if (!uomap.empty()) {
		cout << "UO Map #" << num << " contains:" << endl;
		for_each(uomap.begin(), uomap.end(), showElement);
	}
	else cout << "UO Map #"<< num << " is empty" << endl;
}

int main() {
	pair<string, string> initArray[] = { {"hello", "world"}, {"just", "do it"}, {"wake", "up"}, {"common", "guys"} };
	
	unordered_map <string, string> strMap1;
	unordered_map <string, string> strMap2;
	showUOMap(strMap1, 1);
	showUOMap(strMap2, 2);

	cout << endl << "try to fill uo map containers:" << endl;
	strMap1.insert(initArray, initArray+sizeof(initArray)/sizeof(initArray[0]));
	strMap2.emplace(initArray[1]);
	strMap2.emplace(make_pair("oh", "God"));

	showUOMap(strMap1, 1);
	showUOMap(strMap2, 2);

	cout << "find value by key(hello) in uomap #1: "
		<< strMap1.find("hello")->second
		<< endl;
	
	cout << "try to swap and change some elements:" << endl;

	strMap1.swap(strMap2);
	strMap1.clear();
	strMap2["just"] = "forget"; // without exception/ i dont want to handle it now
	strMap2.erase(strMap2.find("common"));
	strMap2.erase("wake");

	showUOMap(strMap1, 1);
	showUOMap(strMap2, 2);

	system("pause");
	return 0;
}