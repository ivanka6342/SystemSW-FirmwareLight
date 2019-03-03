#ifndef __STORAGE__
#define __STORAGE__

#include <vector>

class Storage {
private:
	std::vector<int> nums;

public:
	void addElem(int);

	bool isAvailable();

	int getElem();
};

#endif