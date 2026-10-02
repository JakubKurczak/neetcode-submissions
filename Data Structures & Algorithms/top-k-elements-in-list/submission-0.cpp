class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> freqs;

        for(const auto& n: nums){
            freqs[n] += 1;
        }

        std::priority_queue<std::pair<int,int>> pq;
        for(const auto& n_f: freqs){
            pq.push(std::make_pair(n_f.second,n_f.first));
        }

        std::vector<int> top_k;

        while(std::size(top_k) < k ){
            top_k.push_back(pq.top().second);
            pq.pop();
        }
        return top_k;
    }
};
