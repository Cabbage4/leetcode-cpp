#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution
{
private:
    int cp(string s1, string s2)
    {
        int r = 0;
        for (int i = 0; i < 8; i++)
        {
            if (s1[i] != s2[i])
            {
                r++;
            }
        }
        return r;
    }

public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < bank.size(); i++)
        {
            if (1 == cp(bank[i],start))
            {
                if (!mp.count(bank[i]))
                {
                    mp[bank[i]] = {};
                }

                mp[bank[i]].push_back(start);

                if (!mp.count(start))
                {
                    mp[start] = {};
                }

                mp[start].push_back(bank[i]);
            }

            for (int j = i + 1; j < bank.size(); j++)
            {
                if (1 == cp(bank[i], bank[j]))
                {
                    if (!mp.count(bank[i]))
                    {
                        mp[bank[i]] = {};
                    }

                    mp[bank[i]].push_back(bank[j]);

                    if (!mp.count(bank[j]))
                    {
                        mp[bank[j]] = {};
                    }

                    mp[bank[j]].push_back(bank[i]);
                }
            }
        }

        queue<string> q;
        unordered_map<string, int> book;
        q.push(start);
        int step = -1;

        while (q.size() != 0)
        {
            step++;
            int child_size = q.size();

            for (int i = 0; i < child_size; i++)
            {
                string s = q.front();
                q.pop();

                if (s == end)
                {
                    return step;
                }

                if (mp.count(s) == 0)
                {
                    continue;
                }

                for (string next_s : mp[s])
                {
                    if (book.count(next_s) == 0) 
                    {
                        q.push(next_s);
                        book[next_s] = 1;
                        continue;
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<string> data = {"AACCGGTA"};
    int r = s.minMutation("AACCGGTT", "AACCGGTA",data);
    return 0;
}