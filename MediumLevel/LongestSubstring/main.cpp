class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        string subs;

        for (int i = 0; i < s.length();i++) {
            subs = s[i];
            for (int j = i + 1; j < s.length(); j++) {
                if (subs.find(s[j]) != string::npos) {
                    break;
                }
                subs += s[j];
            }
            if (len < subs.length())
                len = subs.length();
        }

        return len;
    }
};
