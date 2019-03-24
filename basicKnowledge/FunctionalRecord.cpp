#include <iostream>

class A {
private:
	int num = 1;
public:
	A(int a = 0) : num(a) {}
	int method() { return num; }
	friend int funtionalMethod(A obj) { return obj.num; }
};

int main() {
	A obj;
	
	std::cout << "using standard class method: " << obj.method() << std::endl
		<< "using functional method with friend function: " << funtionalMethod(obj) << std::endl;

	system("pause");
	return 0;
}