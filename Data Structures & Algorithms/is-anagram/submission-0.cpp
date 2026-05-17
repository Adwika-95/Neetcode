class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int n = s.length();
        vector<bool> used(n, false);

        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && s[i] == t[j]) {
                    used[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
};