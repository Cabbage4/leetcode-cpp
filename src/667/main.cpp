#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> r;
        int max_index = k + 1;
        for (int i = 1; i <= (k + 1) / 2; i++)
        {
            r.push_back(i);
            r.push_back(max_index--);
        }

        if ((k + 1) % 2 != 0)
        {
            r.push_back((k + 2) / 2);
        }

        for (int i = k + 2; i <= n; i++)
        {
            r.push_back(i);
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> r = s.constructArray(3, 2);
    r = s.constructArray(10, 2);
    cout << "hello world" << endl;
    return 0;
}