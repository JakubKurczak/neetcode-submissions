class Solution {
public:
    int characterReplacement(string s, int k) {
        int start_index = 0;
        int end_index = 1;
        int max_string = 1;
        char max_char = s[0];

        std::unordered_map<char,int> how_many_letters{};

        how_many_letters[s[start_index]] += 1;

        while(end_index < std::size(s)){
            how_many_letters[s[end_index]] += 1;
            if(how_many_letters[max_char] < how_many_letters[s[end_index]]){
                max_char = s[end_index];
            }

            while(((end_index - start_index ) + 1) - how_many_letters[max_char] > k){
                    how_many_letters[s[start_index]] -= 1;
                    start_index += 1;
                    // if(how_many_letters[max_char] < how_many_letters[s[start_index]]){ // tutaj blad! powinnismy szukac wsrod wszystkich kandydatow
                    //     max_char = s[start_index]; 
                    // }

                    for(auto& key_value: how_many_letters){
                        if(key_value.second > how_many_letters[max_char]){
                            max_char = key_value.first;
                            break;
                        }
                    }
            }

            if(max_string < ((end_index - start_index ) + 1)){
                max_string = ((end_index - start_index ) + 1);
            }

            end_index++; 
        }

        return max_string;
    }
};
