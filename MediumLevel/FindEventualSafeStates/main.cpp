#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int start;
	int second;
    bool dfs(vector<vector<int>>& graph, int node) {
        if (node == start)
            return false;
        for (int i = 0; i < graph[node].size(); i++) {
			cout << node << " --> " << graph[node][i] << endl;
            if (graph[node][i] == node || second == node) {
				cout << node << " is unsafe" << endl;
                return false;
			}
            if (graph[node][i] != node && this->dfs(graph, graph[node][i]) == false)
				return false;
        }
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safes;
		vector<int> unsafes;
        for (int i = 0; i < graph.size(); i++) {
            start = i;
            if (graph[i].empty())
                safes.push_back(i);
			else {
				int j = 0;
				for (j = 0; j < graph[i].size(); j++) {
					cout << i << " To " << graph[i][j] << endl;
					second = graph[i][j];
                    if (graph[i][j] == i)
						break;
					if (find(unsafes.begin(), unsafes.end(), graph[i][j]) != unsafes.end())
						break;
					if (this->dfs(graph, graph[i][j]) == false)
						break;
				}
				cout << endl;
				if (j >= graph[i].size())
					safes.push_back(i);
				else
					unsafes.push_back(i);
			}
        }
        return safes;
    }
};


int main() {

	Solution obj;

	vector<int> v0 = {2, 3};
	vector<int> v1 = {2,3,4};
	vector<int> v2 = {3, 4};
	vector<int> v3 = {};
	vector<int> v4 = {1};

	vector<vector<int>> vec = {v0,v1,v2,v3,v4,};
	vector<int> res = obj.eventualSafeNodes(vec);
	
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

}