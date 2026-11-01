class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int full_product_without_zeroes = 0;
        bool has_zeroes = false;
        int zero_count = 0;
        vector<int> ret{};
        for(int num: nums){
            if(num!=0){
                if(full_product_without_zeroes == 0)
                    full_product_without_zeroes = 1;
                full_product_without_zeroes *= num;
            } else {
                has_zeroes = true;
                zero_count++;
            }
        }

        for(int num: nums){
            if(num != 0){
                if(has_zeroes)
                    ret.push_back(0);
                else
                    ret.push_back(full_product_without_zeroes/num);
            } else {
                if(zero_count == 1){
                    ret.push_back(full_product_without_zeroes);
                }else{
                    ret.push_back(0);
                }
            }
        }

        return ret;
    }
};
