class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;
        cleaned.reserve(s.size());

        for(char c : s) {
            if (isalnum(c)) {
                cleaned.push_back(tolower(c));
            }
        }

        int i = 0, j = cleaned.size() - 1;
        while (i < j) {
            if (cleaned[i] != cleaned[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
