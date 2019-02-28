#include <deque>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

// show every element using iterators
void showDeqAsWord(deque<char> &deq) {
	for (deque<char>::iterator iter = deq.begin(); iter != deq.end(); iter++)
		cout << *iter;
	cout << endl;
}

// show every element using .at(i) method
void reverseShowDeqAsWord(deque<char> &deq) {
	for (int i = deq.size()-1; i>=0; i--)
		cout << deq.at(i);
	cout << endl;
}

void deqPushStringFront(deque<char> &deq, char* word, int strSize) {
	int i = 0;
	word += strSize - 1;
	while (i < strSize) {
		deq.push_front(*word);
		word--;
		i++;
	}
}

void deqPushStringBack(deque<char> &deq, char* word, int strSize) {
	int i = 0;
	while (i++ < strSize)
		deq.push_back(*word++);
}

void deqEmplaceStringFront(deque<char> &deq, char* word, int strSize) {
	int i = 0;
	word += strSize - 1;
	while (i++ < strSize)
		deq.emplace_front(*word--);
}

void deqEmplaceStringBack(deque<char> &deq, char* word, int strSize) {
	int i = 0;
	while (i++ < strSize)
		deq.emplace_back(*word++);
}

// fill deque insert'íng string as range of char's
void fillDeqByString(deque<char> &deq, char* word, int strSize) {
	deq.clear();
	deq.insert(deq.begin(), word, word+strSize);
}

int main() {
	deque<char> deqWord;
	fillDeqByString(deqWord, (char*)"Deque", 5);
	cout << "First Deque:" << endl;
	showDeqAsWord(deqWord);

	deqPushStringBack(deqWord, (char*)"Back", 4);
	showDeqAsWord(deqWord);

	deqPushStringFront(deqWord, (char*)"Front", 5);
	showDeqAsWord(deqWord);
	cout << "Deque size: " << deqWord.size() << endl;
	deqWord.resize(20, 'a');
	showDeqAsWord(deqWord);
	cout << "Deque size: " << deqWord.size() << endl << endl;


	deque<char> deqReverseWord;
	fillDeqByString(deqReverseWord, (char*)"ertneC", 6);
	cout << "Second(reverse) Deque:" << endl;
	showDeqAsWord(deqReverseWord);
	reverseShowDeqAsWord(deqReverseWord);

	deqPushStringBack(deqReverseWord, (char*)"tfeL", 4);
	showDeqAsWord(deqReverseWord);
	reverseShowDeqAsWord(deqReverseWord);

	deqPushStringFront(deqReverseWord, (char*)"thgiR", 5);
	showDeqAsWord(deqReverseWord);
	reverseShowDeqAsWord(deqReverseWord);
	cout << "Reverse deque size: " << deqReverseWord.size() << endl;
	deqReverseWord.resize(11, 'a');
	showDeqAsWord(deqReverseWord);
	reverseShowDeqAsWord(deqReverseWord);
	cout << "Reverse deque size: " << deqReverseWord.size() << endl << endl;

	
	swap(deqReverseWord, deqWord);
	for(int i = 0; i < 6; i++)
		deqWord.erase(deqWord.end()-1);
	deqReverseWord.assign(5, 'a');
	cout << "First deque now:" << endl;
	showDeqAsWord(deqWord);
	reverseShowDeqAsWord(deqWord);
	cout << "Second deque now:" << endl;
	showDeqAsWord(deqReverseWord);

	system("pause");
	return 0;
}