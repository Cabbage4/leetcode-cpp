#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
private:
    struct Cmp
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }
    };

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), Cmp());
        int r = 0;
        int lastValue = -1001;
        for (int i = 0; i < pairs.size(); i++)
        {
            if (pairs[i][0] > lastValue)
            {
                lastValue = pairs[i][1];
                r++;
            }
        }
        return r;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}};
    Solution s;
    int r = s.findLongestChain(v);

    v = {{1, 2}, {7, 8}, {4, 5}};
    r = s.findLongestChain(v);

    return 0;
}