#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int uniqueLetterString(string s)
    {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]].push_back(i);
        }

        int r = 0;
        for (unordered_map<char, vector<int>>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            vector<int> list = iter->second;
            list.insert(list.begin(), -1);
            list.emplace_back(s.length());
            for (int i = 1; i < list.size() - 1; i++)
            {
                r += (list[i] - list[i - 1]) * (list[i + 1] - list[i]);
            }
        }

        return r;
    }
};

int main()
{
    Solution s;
    int r = s.uniqueLetterString("ABC");
    r = s.uniqueLetterString("ABA");
    r = s.uniqueLetterString("LEETCODE");
    return 0;
}