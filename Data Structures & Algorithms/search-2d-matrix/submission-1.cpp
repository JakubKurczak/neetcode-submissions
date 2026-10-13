class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_l = 0;
        int row_r = std::size(matrix) - 1;

        while(row_l <= row_r){
            int row_mid = row_l + ((row_r-row_l)/2);

            if(matrix[row_mid][std::size(matrix[row_mid] )-1] < target){
                row_l = row_mid + 1;

            } else if(matrix[row_mid][0] > target) {
                row_r = row_mid - 1;
            } else {
                // tutaj szukamy targetu w tym rzędzie
                int l = 0;
                int r = std::size(matrix[row_mid]) - 1;
                while(l<=r){
                    int m  = l + ((r-l)/2);
                    if(matrix[row_mid][m]<target){
                        l = m + 1;
                    } else if(matrix[row_mid][m] > target) {
                        r = m -1;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }

        return false;
    }
};
