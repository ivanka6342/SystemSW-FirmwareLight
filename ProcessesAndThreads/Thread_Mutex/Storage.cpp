#include "Storage.h"

void Storage::addElem(int num) {
	nums.push_back(num);
}

bool Storage::isAvailable() {
	return !nums.empty();
}

int Storage::getElem() {
	int  i = nums[0];
	nums.erase(nums.begin());
	return i;
}