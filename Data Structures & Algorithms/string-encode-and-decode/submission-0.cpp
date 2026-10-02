class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded_string{};
        for(const auto&s: strs){
            encoded_string += (std::to_string(std::size(s)) + "#"+ s );
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        int next_index = 0;
        std::vector<std::string> decoded_strings{};
        auto prev_end_of_size = s.begin();
        auto end_of_size = std::find(prev_end_of_size,s.end(),'#');
        while(end_of_size != s.end()) {
            int size = std::stoi(std::string(prev_end_of_size, end_of_size));
            decoded_strings.push_back(std::string(end_of_size+1,end_of_size+1+size));
            prev_end_of_size = end_of_size + 1 + size;
            end_of_size = std::find(prev_end_of_size,s.end(),'#');
        }

        return decoded_strings;
    }
};
