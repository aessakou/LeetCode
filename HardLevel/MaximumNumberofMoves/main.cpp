#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// class Solution {
// public:

// 	const int N = 50;
// 	const vector<pair<int, int>> moves = {
// 		{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
// 		{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
// 	};

// 	int shortDist(int startX, int startY, int targetX, int targetY) {
// 		return 0;
// 	}

// 	string s;
//     int tobin(int num) {
//         if (num < 2){
//             return num;
//         }
//         else {
//             s += to_string(num % 2);
//             string t = to_string(tobin(num / 2));
// 			if (t != "-1") {
// 				s += t;
// 			}
//         }
//         return -1;
//     }


//     int maxMoves(int kx, int ky, vector<vector<int>>& positions) {

//         int start = 0;
//         int max = 90;
//         int tmp = 100;

// 		for (int i = 0; i < positions.size(); i++){
// 			// tmp = 100;
// 			tmp = this->shortDist(kx, ky, positions[i][0], positions[i][1]);
// 			cout << "Shortest to: (" << positions[i][0] << "," << positions[i][1] << ") is " << tmp << endl;
// 		}
//         return max;
        
//     }
// };




// int main() {

	
// 	Solution obj;

// 	obj.tobin(01);

// 	cout << obj.s << endl;
// 	// int kx = 0;
// 	// int ky = 0;

// 	// vector<int> v1 = {1, 1};
// 	// vector<int> v2 = {49, 49};
// 	// vector<int> v3 = {1, 6};
// 	// vector<int> v4 = {2, 3};

// 	// vector<vector<int>> vec = {v1, v2, v3, v4};

// 	// obj.maxMoves(kx, ky, vec);

// 	return 0;
// }


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // Memoization map to store results of subexpressions
        unordered_map<string, vector<int>> memo;
        return compute(expression, memo);
    }

private:
    vector<int> compute(const string& expression, unordered_map<string, vector<int>>& memo) {
        // Check if the result for this expression is already computed
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> results;
        bool isNumber = true;

        // Iterate over the expression to find operators
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                isNumber = false;
                // Split the expression into two parts
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                // Compute all possible results for left and right parts
                vector<int> leftResults = compute(left, memo);
                vector<int> rightResults = compute(right, memo);

                // Combine results based on the operator
                for (int leftValue : leftResults) {
                    for (int rightValue : rightResults) {
                        if (c == '+') {
                            results.push_back(leftValue + rightValue);
                        } else if (c == '-') {
                            results.push_back(leftValue - rightValue);
                        } else if (c == '*') {
                            results.push_back(leftValue * rightValue);
                        }
                    }
                }
            }
        }

        // If the expression is a number, add it to the results
        if (isNumber) {
            results.push_back(stoi(expression));
        }

        // Store the results in the memoization map
        memo[expression] = results;
        return results;
    }
};

int main() {
    Solution sol;
    string expression = "2-1-1-1-1-1-1-1";
    vector<int> results = sol.diffWaysToCompute(expression);

    cout << "Possible results: ";
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
