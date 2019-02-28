#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void showVectorSizes(vector<char*> *v) {
	cout << "vector size: " << v->size() << endl
		<< "vector max size: " << v->max_size() << endl
		<< "vector capacity: " << v->capacity() << endl;
}

void showVectorElements(vector<char*> *v) {
	cout << endl;
	for (vector<char*>::const_iterator iter = (*v).begin(); iter < (*v).end(); iter++)
		cout << *iter << endl;
	cout << endl;
}

int main() {
	vector<char*> tempVector;
	tempVector.push_back((char*)"crazyfrog");
	tempVector.push_back((char*)"ninja");

	vector<char*> stringVect;
	stringVect.reserve(3);
	showVectorSizes(&stringVect);

	if (stringVect.empty()) {
		stringVect.push_back((char*)"string 1");
		/*
		for (int i = 0; i < 3; i++) {
			char* a = (char*)"string";
			strcat_s(a, 16, (char*)i);
			stringVect.push_back(a);
		}
		*/
	}
	stringVect.resize(5, (char*)"empty");
	stringVect.reserve(15);

	cout << endl << "after vector.resize(5) and vector.reserve(15):" << endl;
	showVectorElements(&stringVect);
	showVectorSizes(&stringVect);

	stringVect.shrink_to_fit();
	cout << endl << "after vector.shrink_to_fit():" << endl;
	showVectorSizes(&stringVect);

	stringVect.insert(stringVect.begin(), (char*)"web");
	stringVect.insert(stringVect.begin(), 3, (char*)"led");
	stringVect.emplace(stringVect.end()-1, (char*)"gparted");
	stringVect.back() = (char*)"Cyberpunk";
	cout << endl << "after vector.insert(vector.begin(), ...)" << endl;
	showVectorSizes(&stringVect);
	showVectorElements(&stringVect);

	stringVect.erase(stringVect.begin(), stringVect.end());
	stringVect.shrink_to_fit();
	showVectorSizes(&stringVect);
	showVectorElements(&stringVect);

	stringVect.resize(9, (char*)"memory");
	showVectorSizes(&stringVect);
	showVectorElements(&stringVect);

	cout << endl << "after vector.assign()" << endl;
	stringVect.assign(tempVector.rbegin(), tempVector.rend());
	showVectorSizes(&stringVect);
	showVectorElements(&stringVect);

	stringVect.insert(stringVect.begin() + 1, 3, (char*)"abrakadabra");
	showVectorSizes(&stringVect);
	showVectorElements(&stringVect);

	tempVector.clear();
	cout << endl << "after tempVector.clear()" << endl;
	showVectorSizes(&tempVector);
	showVectorElements(&tempVector);

	system("pause");
	return 0;
}