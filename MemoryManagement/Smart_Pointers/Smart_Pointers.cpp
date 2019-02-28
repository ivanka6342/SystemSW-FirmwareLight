#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

class First {
private:
	int a;

public:
	First() : a(2) 
	{
		cout << "class \"First\" constructor\n";
	}

	void say_a() { cout << "a = " << a << "\n"; }

	~First() {
		cout << "class \"First\" destructor\n";
	}
};

class DeleteFirst {
public:
	void operator()(First *ptr) const {
		cout << "delete \"First\" class object\n";
		delete ptr;
	}
};

void auto_ptr_training() {
	auto_ptr<First> firstSmartPtr(new First());
	firstSmartPtr.get()->say_a();
}

void unique_ptr_training() {
	cout << "\nunique_ptr:\n";
	unique_ptr<First> firstSmartPtr(new First);
	if (firstSmartPtr) firstSmartPtr->say_a();

	unique_ptr<First> p;
	if (!p) cout << "no p\n";

	unique_ptr<First> secondSmartPtr(move(firstSmartPtr));                    // exchange value with creating new pointer
	if (!firstSmartPtr && secondSmartPtr) cout << "no first, but second\n";

	firstSmartPtr = move(secondSmartPtr);                                     // exchange value moving old pointer value
	if (!secondSmartPtr && firstSmartPtr) cout << "no second, but first\n";
}

void shared_ptr_training() {
	cout << "\nshared_ptr:\n";
	shared_ptr<First> firstSmartPtr(new First);
	if (firstSmartPtr) firstSmartPtr->say_a();

	// default constructor
	shared_ptr<First> secondSmartPtr;
	if (!secondSmartPtr) cout << "no second\n";
	secondSmartPtr = firstSmartPtr;
	if (secondSmartPtr && firstSmartPtr) {
		cout << "if first and second:\n";
		secondSmartPtr->say_a();
	}

	// copy constructor
	shared_ptr<First> thirdSmartPtr(secondSmartPtr);
	if (thirdSmartPtr && secondSmartPtr && firstSmartPtr) {
		cout << "if first, second and third:\n";
		thirdSmartPtr->say_a();
	}

	// constructor with destructor functor
	shared_ptr<First> forthSmartPtr(new First, DeleteFirst());

	cout << "counters of object use by ptr:\n"
		<< "first : " << firstSmartPtr.use_count() << "\n"
		<< "second : " << secondSmartPtr.use_count() << "\n"
		<< "third : " << thirdSmartPtr.use_count() << "\n"
		<< "forth : " << forthSmartPtr.use_count() << "\n";
}

void weak_ptr_training() {
	cout << "\nweak_ptr:\n";

	shared_ptr<First> firstSmartPtr(new First);
	shared_ptr<First> secondSmartPtr;
	weak_ptr<First> thirdSmartPtr = firstSmartPtr;

	secondSmartPtr = thirdSmartPtr.lock();
	if (firstSmartPtr == secondSmartPtr)
		cout << "first == second\n";

	cout << "owners count : " << thirdSmartPtr.use_count() << "\n";
	firstSmartPtr.reset();
	secondSmartPtr.reset();

	if (thirdSmartPtr.expired())
		cout << "weak pointer is expired. shared are empty\n";

	firstSmartPtr = thirdSmartPtr.lock();
	if (firstSmartPtr == nullptr)
		cout << "weak ptr has no such power as strong\n";
}

int main() {
	auto_ptr_training();
	unique_ptr_training();
	shared_ptr_training();
	weak_ptr_training();

	system("pause");
	return 0;
}