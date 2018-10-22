#include <stack>
#include <iostream>

#define MAGIC_NUMBER 1234

using namespace std;

// copies current stack to tempSt and show every element as st.top() + st.pop()
void showStack(stack<double> st) {
	stack<double> tempSt;
	while (!st.empty()) {
		tempSt.push(st.top());
		cout << st.top() << endl;
		st.pop();
	}
	st = tempSt;
}

// custom stack initializer by function with variable number of parameters
void initStack(stack<double> *st, int n, ...) {
	/*
	int* ptr = &n;
	cout << "param count: " << *ptr << endl;
	ptr++;
	double* param = (double*)ptr;

	for (int i = 0; i < n; i++) {
		st->push(*param);
		param++;
	}
	*/
	union ChangePtr {
		int* ptr;
		double* param; 
	}value;
	
	value.ptr = &n;
	value.ptr++;

	for (int i = 0; i < n; i++) {
		st->push(*(value.param));
		value.param++;
	}
}

int main() {
	stack<double> numberStack;
	initStack(&numberStack, 5, 21.3, 324.4, 15.6, 77.9, 234.564);
	cout << "number stack size: " << numberStack.size() << endl;
	showStack(numberStack);

	stack<double> doubleStack;

	if (doubleStack.empty()) {
		for(int i=0; i<10; i++)
			doubleStack.push(i*MAGIC_NUMBER%17);
		cout << endl << "doubleStack size: " << doubleStack.size() << endl;
	}

	showStack(doubleStack);

	doubleStack.swap(numberStack);

	cout << endl << "numberStack now:" << endl;
	showStack(numberStack);

	cout << endl << "doubeStack now:" << endl;
	showStack(doubleStack);

	system("pause");
	return 0;
}