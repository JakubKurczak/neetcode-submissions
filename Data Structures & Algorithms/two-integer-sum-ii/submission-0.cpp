class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index_start=0;
        int index_end=std::size(numbers)-1;
        while(numbers[index_start]+numbers[index_end] != target) {
            if(numbers[index_start]+numbers[index_end] > target) {
                index_end--;
            } else {
                index_start++;
            }
        }

        return {index_start+1,index_end+1};
    }
};
