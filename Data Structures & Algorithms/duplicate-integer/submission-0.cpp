class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       std::unordered_map<int,int> nums_reps;
       for(const auto& numb: nums){
            nums_reps[numb] += 1;
            if(nums_reps[numb] > 1){
                return true;
            }
       } 
       return false;
    }
};