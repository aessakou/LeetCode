#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int limit;
    int head;
    vector<int> lexico;

	void dfs(int num) {
		lexico.push_back(num);
		if (num * 10 <= limit) {
			dfs(num * 10);
		}
		else if ((num + 1) % 10 == 0){
			dfs((num + 1) / 10);
		}
		else if ((num + 1) % 10 != 0 && (num + 1) != (head + 1) && (num + 1) <= limit){
			dfs(num + 1);
		}
		else if (num == limit && limit > 9){
			dfs((num / 10) + 1);
		}
		return;
	}

    vector<int> lexicalOrder(int n) {
		limit = n;
        for (int i = 1; i < 10 && i <= n; i++) {
            head = i;
			this->dfs(i);
        }
        return lexico;
    }
};



int main() {

	Solution obj;

	vector<int> res = obj.lexicalOrder(123);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ", ";
	}
	cout << endl;
}