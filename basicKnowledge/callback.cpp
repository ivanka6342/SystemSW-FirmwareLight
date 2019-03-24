#include <iostream>
#include <stdarg.h>

void swapNum(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void increaseSort(int& a, int& b) {
	if (a < b)
		swapNum(a, b);
}

void decreaseSort(int& a, int& b) {
	if (a > b)
		swapNum(a, b);
}

// use callback function to sort array
void sort(int* arr, int size, void(*cmpFunc)(int&, int&)) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cmpFunc(arr[i], arr[j]);
		}
	}
}

int main() {
	void(*incSortFunc)(int&, int&) = &increaseSort; // now we have "alias" incSortFunc
	void(*decSortFunc)(int&, int&) = &decreaseSort; // now we have "alias" decSortFunc

	int arr[5] = {34, 23, 455, 64, 13};

	// lambda expression to show arr
	auto showArr = [&] {
		for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
			std::cout << *(arr + i) << " ";
		std::cout << std::endl;
	};

	std::cout << "initial array:\n";
	showArr();

	std::cout << "\nincrease sort:\n";
	sort(arr, 5, incSortFunc); // we also can use &increaseSort instead
	showArr();
	
	std::cout << "\ndecrease sort:\n";
	sort(arr, 5, decSortFunc); // we also can use &decreaseSort instead
	showArr();

	system("pause");
	return 0;
}