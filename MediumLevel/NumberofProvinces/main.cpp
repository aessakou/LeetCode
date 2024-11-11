#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    map<int, string> provinces;
	vector<int> erass;
    int searchinPr(int city, int create) {
        string sc = "[" + to_string(city) + "]";  
        map<int, string>::iterator it = provinces.begin();
        while (it != provinces.end()) {
            if ((it->second).find(sc) != string::npos) {
                return it->first;
            }
            it++;
        }
        if (create) {
			cout << city << " Group Created" << endl;
            provinces[city] = sc;
            return city;
        }
        return -1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        string tmp;
        int size = isConnected.size();
        int proind;
        int num = 0;
        for (int i = 0; i < size; i++){
            proind = this->searchinPr(i, 1);
            for (int j = 0; j < size; j++) {
                if (isConnected[i][j] == 1 && proind != this->searchinPr(j, 0)) {
                    provinces[proind] += "[" + to_string(j) + "]";
                }
            }
        }
        for (auto it = provinces.begin(); it != provinces.end(); it++){
			if (it == provinces.begin())
				it++;
			if (it == provinces.end())
				break;
			string ss = it->second;
			proind = this->searchinPr(it->first, 0);
			for (int i = 0; i < ss.length(); i++) {
				if (ss[i] == '['){
					i++;
					string str = "";
					while (ss[i] && ss[i] != ']') {
						str += ss[i++];
					}
					int proind2 = this->searchinPr(stoi(str), 0);
					if (proind != proind2){
						cout << "Looking for :"<< str << endl;
						cout << proind2 << " : " << provinces[proind2] << endl;
						cout << proind << " : " << provinces[proind] << endl;
						provinces[proind2] += it->second;
						erass.push_back(proind);
						break;
					}
				}
			}
        }
		for (int i = 0; i < erass.size(); i++) {
			provinces.erase(i);
		}
		num = provinces.size();
        return num;
    }
};


int main() {
	
	// "[
	// 	[1,0,0,1],
	// 	[0,1,1,0],
	// 	[0,1,1,1],
	// 	[1,0,1,1]
	// ]"

	Solution obj;



	std::vector<int> v1  = {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0};
	std::vector<int> v2  = {0,1,0,1,0,0,0,0,0,0,0,0,0,1,0};
	std::vector<int> v3  = {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0};
	std::vector<int> v4  = {0,1,0,1,0,0,0,1,0,0,0,1,0,0,0};
	std::vector<int> v5  = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0};
	std::vector<int> v6  = {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0};
	std::vector<int> v7  = {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0};
	std::vector<int> v8  = {0,0,0,1,0,0,0,1,1,0,0,0,0,0,0};
	std::vector<int> v9  = {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0};
	std::vector<int> v10 = {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0};
	std::vector<int> v11 = {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0};
	std::vector<int> v12 = {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
	std::vector<int> v13 = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0};
	std::vector<int> v14 = {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0};
	std::vector<int> v15 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};

	// vector<int> v1 = {1, 0, 0, 1};
	// vector<int> v2 = {0, 1, 1, 0};
	// vector<int> v3 = {0, 1, 1, 1};
	// vector<int> v4 = {1, 0, 1, 1};


	// Add them all to a vector of vectors
	std::vector<std::vector<int>> vec = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15};
	// std::vector<std::vector<int>> vec = {v1, v2, v3, v4};


	cout << obj.findCircleNum(vec) << endl;

	return 0;
}