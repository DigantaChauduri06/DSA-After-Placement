class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for (char &c : s) {
            if (c == ' ') continue;
            char lower = tolower(c);
            if (isalpha(lower) || isdigit(lower))
                temp.push_back(lower);
        }
        // cout << temp << endl;
        int i = 0;
        int j = temp.size() - 1;
        while (i <= j) {
            if (temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};