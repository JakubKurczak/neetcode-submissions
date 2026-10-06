class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> monotonic_temps{};
        std::stack<int> monotonic_index{};
        std::vector<int> ret_days = std::vector<int>(std::size(temperatures),0);
        for(int index = 0; index < std::size(temperatures); index++){
            if (not std::empty(monotonic_temps) and monotonic_temps.top() < temperatures[index]) {
                while(not std::empty(monotonic_temps) and monotonic_temps.top() < temperatures[index]){
                    ret_days[monotonic_index.top()] = index-monotonic_index.top();
                    monotonic_temps.pop();
                    monotonic_index.pop();
                }
                
            }
            monotonic_temps.push(temperatures[index]);
            monotonic_index.push(index);
        }
        return ret_days;
    }
};
