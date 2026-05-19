class Solution {
private:
    bool validBracket(char a, char b) {
        if(a == '(' && b == ')') return true;
        else if(a == '{' && b == '}') return true;
        else if(a == '[' && b == ']') return true;
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for(auto& i : s) {
            if(i == '(' || i == '{' || i == '[') st.push(i);
            else {
                if(st.empty()) return false;
                if(!validBracket(st.top(), i)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};