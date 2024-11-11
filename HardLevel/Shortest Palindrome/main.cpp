#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        for (int i = (len / 2); i < len; i++) {
            if (s[i] != s[len - i - 1])
                return false;
        }
        return true;
    }

    string shortestPalindrome(string s) {
        string str;
        string tmp;

		for (int i = 0; i < s.size();i++) {
			str += s[i];
			tmp = str;
			reverse(str.begin(), str.end());
			if (s.find(str) == string::npos){
				tmp.erase(tmp.size() - 1);
				break;
			}
			str = tmp;
		}
		cout << tmp << endl;
		// cout << str << endl;
		str = s.substr(tmp.size(), s.size());
		reverse(str.begin(), str.end());
		cout << str << endl;
		str += s; 
        return str;
    }
};


int main() {
	Solution obj;
	string str = "mtcbactm";

	// cout << obj.shortestPalindrome(str) << endl;
	// cout << str << endl;
	
	str = "abcda";

	cout << obj.shortestPalindrome(str) << endl;
	cout << str << endl;

	string test = "a#a##";


	return 0;
}