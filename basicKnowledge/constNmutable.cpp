#include <iostream>
#include <string>

class Person {
private:
	int age;
	mutable std::string name;

	void setYear(int a) { age = a; }

public:
	Person(int a, std::string b) : age(a), name(b) { ; }
	
	void rename(std::string b) const { name = b; }

	// this method is const because it should be no way to change class content(exception: mutable variables)
	void show() const {
		//this->age++; // isn't work in const method
		std::cout << "(age: " << this->age << ", name: " << this->name << ")\n";
	}

	friend std::ostream& operator << (std::ostream& s, const Person& p) {
		s << "(age: " << p.age << ", name: " << p.name << ")";
		return s;
	}
};

int main() {
	Person man(10, "Peter");
	man.rename("Frank");
	std::cout << man << std::endl;
	man.show();

	system("pause");
	return 0;
}