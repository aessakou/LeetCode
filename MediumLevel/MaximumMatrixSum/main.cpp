#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int nigatives = 0;
        long long sum = 0;
        int min = 100000;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] < 0){
                    nigatives++;
                }
                sum += abs(matrix[i][j]);
                if (abs(matrix[i][j]) < min){
                    min = abs(matrix[i][j]);
                }
            }
        }
        if (nigatives % 2 == 0){
            return sum;
        }
        return (sum - (min * 2));
        
    }
};

int main(){

	Solution obj;
	
	obj = Solution();

	// [[1,-1],[-1,1]]
	vector<vector<int>> matrix1 = { {1, -1},
									{-1, 1}};
	
	
	// [[1,2,3],[-1,-2,-3],[1,2,3]]
	vector<vector<int>> matrix2 = {	{ 1, 2, 3},
									{-1,-2,-3},
									{ 1, 2, 3}};

	cout << obj.maxMatrixSum(matrix1) << endl; // Expected output : 4
	cout << obj.maxMatrixSum(matrix2) << endl; // Expected output : 16
}