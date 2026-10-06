class Solution {
public:
    std::unordered_map<char, std::function<int (int,int)>> calculations{
        {'+',[](int a, int b){return a+b;}},
        {'-',[](int a, int b){return a-b;}},
        {'/',[](int a, int b){return a/b;}},
        {'*',[](int a, int b){return a*b;}},
        
        };
    int evalRPN(vector<string>& tokens) {
        std::stack<int> values;
        for(const auto& token: tokens){
            if(std::size(token) == 1 && not std::isdigit(token[0])){
                auto calc = calculations[token[0]];
                int a = values.top();
                values.pop();
                int b = values.top();
                values.pop();
                values.push(calc(b,a));
            } else {
                values.push(std::stoi(token));
            }
        }
        
        return values.top();
    }
};
