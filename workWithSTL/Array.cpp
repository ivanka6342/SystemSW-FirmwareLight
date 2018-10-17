#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;

void printArrElem(char* string) {
	cout << string << endl;
}

enum appleColor { GREEN, ORANGE, RED};

char* getAppleColorAsString(appleColor color) {
	switch (color)
	{
	case 0: return (char*)"GREEN";
	case 1: return (char*)"ORANGE";
	case 2: return (char*)"RED";
	}
}

class Apple {
private:
	appleColor color;
	double weight;

public:
	Apple() {
		this->color = GREEN;
		this->weight = 0;
	}

	Apple(appleColor color, double weight) {
		this->color = color;
		this->weight = weight;
	}

	void setColor(appleColor color) {
		this->color = color;
	}
	
	appleColor getColor() {
		return this->color;
	}

	void setWeight(double weight) {
		this->weight = weight;
	}

	double getWeight() {
		return this->weight;
	}
	
};

void printAppleInfo(Apple apple) {
	static int appleCount = 0;
	appleCount++;
	cout << "Apple #" << appleCount
		<< "color: " << getAppleColorAsString(apple.getColor())
		<< "weigth: " << apple.getWeight()
		<< endl;
}

typedef array<Apple*, 2> appleArr;

int main() {

	// firstly Array of strings
	array<char*, 3> arr;

	if (!arr.empty()) {
		arr[0] = (char*)"String 1";
		arr.at(1) = (char*)"String 2";
		arr.at(2) = (char*)"String 3";
	}

	cout << "arr.size() = " << arr.size() << endl;
	cout << "arr.max_size() = " << arr.max_size() << endl;
	
	cout << "arr[1] = " << get<1>(arr) << endl;


	auto beginIterator = arr.begin();
	auto endIterator = arr.end();
	cout << endl << "Array in derect order:" << endl; 
	for_each(beginIterator, endIterator, printArrElem);
	
	auto rBeginIterator = arr.rbegin();
	auto rEndIterator = arr.rend();

	cout << endl << "Array in reverse order:" << endl;
	for_each(rBeginIterator, rEndIterator, printArrElem);

	arr.fill((char*)"strstrstr");
	cout << endl << "Array after arr.fill(): " << endl;
	for_each(beginIterator, endIterator, printArrElem);
	
	// Array of objects
	Apple apple1;
	Apple* apple2 = new Apple(RED, 120.65);
	
	appleArr apples = { &apple1, apple2 };
	// I even can't add element to Array by command like appleArr.add()
	// because it's static array. should use std::vector
	for (appleArr::const_iterator iter = apples.begin(); iter != apples.end(); iter++) {
		printArrElem(iter);
	}



/*
for (int i = 0; i < arr.size(); i++) {
	cout << i << ": " << get<0>(arr) << endl;
}*/
//cout << get<0>(arr) << endl;


	system("pause");
	return 0;
}