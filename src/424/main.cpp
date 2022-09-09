#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> mp(26, 0);
        int right = 0;
        int left = 0;
        int maxCount = 0;
        while (right < s.length())
        {
            mp[s[right] - 'A']++;
            maxCount = max(maxCount, mp[s[right] - 'A']);
            if (right - left + 1 - maxCount > k)
            {
                mp[s[left] - 'A']--;
                left++;
            }
            right++;
        }

        return right - left;
    }
};

int main()
{
    Solution s;
    int r = s.characterReplacement("ABABCDEFGHIJK", 2);
    return 0;
}
