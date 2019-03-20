#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

// this work on regex101.com : ((?<![\w\S\B])(([\w]{1,25}[\.\w]*)(@{1})([\w]{1,25})(\.)([\w]{1,25})))(?![\w\S\B])

// find all substrings with "email"
void checkRegexMatch(vector<string> strVector) {
	string rx = "([\\w]{1,25}[\.\\w]*)(@{1})([\\w]{1,25})(\.)([\\w]{1,25})";
	regex re(rx);
	cmatch matchRes;

	cout << "The 1st test: Match\r\n";
	cout << "Regular expression: \"" << rx << "\"\r\n";

	for (int i = 0; i < strVector.size(); i++) {
		cout << "init string: \"" << strVector[i] << "\"\r\n";

		if (regex_match(strVector[i].c_str(), matchRes, re))
		{
			cout << "\tThis string matches the pattern: ";
			for (unsigned i = 0; i < matchRes.size(); ++i) {
				cout << "\r\n\t\t[" << matchRes[i] << "] ";
			}
			cout << "\r\n";
		}
		else
			cout << "\tThis string does not matches the pattern\r\n";
	}
	cout << "\r\n";
}

// search all real emails contained in the string
void checkRegexSearch(string initialString) {

	// lambda func that parse email // now not used
	auto f = [](string str){
		string rx = "([\\w]{1,25}[\.\\w]*)(@{1})([\\w]{1,25})(\.)([\\w]{1,25})";
		regex rgx(rx);
		cmatch matchRes;

		regex_match(str.c_str(), matchRes, rgx);
		
		for (int i = 1; i < matchRes.size(); ++i) {
			cout << "\r\n\t\t\t[" << matchRes[i] << "] ";
		}
		cout << "\r\n";
	};

	string rx = "([\\w]{1,25}[\.\\w]*@{1}[\\w]{1,25}\.[\\w]{1,25})";
	regex re(rx);
	cmatch matchRes;

	cout << "The 2nd test: Search\r\n";
	cout << "Regular expression: \"" << rx << "\"\r\n";

	while (regex_search(initialString.c_str(), matchRes, re)) {
		for (int i = 1; i < matchRes.size(); i++)
			std::cout << "\t\t[" << matchRes[i] << "]\r\n";
		//f(matchRes[i]);
		initialString = (matchRes.suffix()).str();
	}

	cout << "\r\n";
}

void checkRegexReplace(string initialString) {
	string rx = "([\\w]{1,25}[\.\\w]*@{1}[\\w]{1,25}\.[\\w]{1,25})";
	regex re(rx);
	string replacement = "000";

	cout << "The 3rd test: Replace\r\n";
	cout << "Regular expression: \"" << rx << "\"\r\n";

	initialString = regex_replace(initialString.c_str(), re, replacement.c_str());

	cout << "Now initial string is: " << initialString << "\r\n";
}

int main() {
	string targetSequence = "Please, choose right email: 1)\"_your.email@gmail.com\", 2)\".not_a_em@il$$\", 3)\"_person.pp@service.com\"";
	vector<string> strVector = { "_your.email@gmail.com", ".not_a_em@il$$", "_person.pp@service.com" };
	cout << "Intial string: \"" << targetSequence << "\"\r\n\r\n";

	checkRegexMatch(strVector);
	checkRegexSearch(targetSequence);
	checkRegexReplace(targetSequence);
	
	system("pause");
	return 0;
}