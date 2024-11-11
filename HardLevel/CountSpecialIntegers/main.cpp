#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int countSpecialNumbers(int n) {
        int num;
        int special = 0;
        vector<int> tmp = {0,1,2,3,4,5,6,7,8,9};
        vector<int> digits;
        for (int i = 1; i <= n; i++){
            num = i;
            digits = tmp;
            while (num) {
                if(digits[num % 10] == num % 10) {
                    digits.push_back(num % 10);
                    num /= 10;
                }
                else
                    break;
            }
            if (num == 0)
                special++;
        }
        return special;
    }
};


int main() {


	Solution obj;

	cout << obj.countSpecialNumbers(20) << endl;

}

for (int i = m; i < n; i++) {
	word1Freq[word1[i] - 'a']++;
	word1Freq[word1[i - m] - 'a']--;

	if (isValid()) validCount++;
}