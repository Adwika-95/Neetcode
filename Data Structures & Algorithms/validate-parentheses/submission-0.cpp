class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If opening bracket, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // If closing bracket
            else {
                if (st.empty()) return false;

                if (ch == ')' && st.top() != '(') return false;
                if (ch == '}' && st.top() != '{') return false;
                if (ch == ']' && st.top() != '[') return false;

                st.pop();
            }
        }

        return st.empty();
    }
};