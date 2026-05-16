class Solution {
private:
    bool isValid(char c) {
        return (c>='0' && c<='9') || (c>='a' && c<'z');
    }    
public:
    bool isPalindrome(string s) {

        for (auto& i : s) i = tolower(i);

        string t = "";

        for (auto& i : s) {
            if (!isValid(i)) continue;
            t += i;
        }

        int low = 0, high = t.size() - 1;

        while (low <= high) {
            if (t[low] != t[high]) return false;
            low++; high--;
        }

        return true;
    }
};