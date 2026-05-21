class Solution {
public:
    // Encode list of strings to a single string
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string &s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    // Decode a single string to list of strings
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.length()) {
            // Find the delimiter '#'
            int j = i;
            while (s[j] != '#') j++;

            // Extract length
            int len = stoi(s.substr(i, j - i));

            // Extract the string of length 'len'
            string str = s.substr(j + 1, len);
            result.push_back(str);

            // Move index forward
            i = j + 1 + len;
        }

        return result;
    }
};