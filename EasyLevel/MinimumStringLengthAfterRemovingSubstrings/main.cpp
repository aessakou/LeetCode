#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    int minLength(string s) {
        
        long i = s.find("AB");
        long j = s.find("CD");
        while (i != string::npos || j != string::npos) {
            if (i != string::npos){
                s.erase(i, 2);
            }
            else if (j != string::npos){
                s.erase(j, 2);
            }
            i = s.find("AB");
            j = s.find("CD");
        }
        
		cout << s << endl;
        return s.length();
    }
};


int main() {


	Solution obj;



	cout << obj.minLength("ABFCACDB") << endl;
}