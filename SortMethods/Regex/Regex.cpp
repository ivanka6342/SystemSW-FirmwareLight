#include <iostream>
#include <regex>
#include <string>

using namespace std;

void checkRegex(string initialString) {
	// BLOCK A: find all substrings with "email"
	{
		string rx = "(.+)(email)(.+)";
		regex rgx(rx);
		cmatch matchRes;

		cout << "The 1st test:\r\n";
		cout << "Regular expression: \"" << rx << "\"\r\n";

		if (regex_match(initialString.c_str(), matchRes, rgx))
		{
			cout << "\tThe matches: ";
			for (unsigned i = 0; i < matchRes.size(); ++i) {
				cout << "\r\n\t\t[" << matchRes[i] << "] ";
			}
			cout << "\r\n";
		}
		else
			cout << "\tNo matches\r\n";
	}

	// lambda func that parse email from BLOCK B
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

	// BLOCK B: search all real emails contained in the string
	{
		// this work on regex101.com : ((?<![\w\S\B])(([\w]{1,25}[\.\w]*)(@{1})([\w]{1,25})(\.)([\w]{1,25})))(?![\w\S\B])
		string rx = "[\\w]{1,25}[\.\\w]*@{1}[\\w]{1,25}\.[\\w]{1,25}";
		regex rgx(rx);
		cmatch matchRes;

		cout << "The 2nd test:\r\n";
		cout << "Regular expression: \"" << rx << "\"\r\n";
		
		if (regex_search(initialString.c_str(), matchRes, rgx))
		{
			cout << "\tThe search: ";
			for (unsigned i = 0; i < matchRes.size(); ++i) {
				cout << "\r\n\t\t[" << matchRes[i] << "] " << endl;
				f(matchRes[i]);
			}
			cout << "\r\n";
		}
		else
			cout << "\tNo matches\r\n";
	}
}

int main() {
	string targetSequence = "Please, choose right email: 1)\"_your.email@gmail.com\", 2)\".not_a_em@il$$\", 3)\"_person.pp@service.com\"";
	cout << "Intial string: \"" << targetSequence << "\"\r\n";

	checkRegex(targetSequence);
	cout << endl;
	
	system("pause");
	return 0;
}