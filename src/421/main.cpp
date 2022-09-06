#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    static constexpr int HIGH_BIT = 30;

public:
    int findMaximumXOR(vector<int> &nums)
    {
        int r = 0;
        for (int k = HIGH_BIT; k >= 0; k--)
        {
            unordered_set<int> bmp;
            for (int num : nums)
            {
                bmp.insert(num >> k);
            }

            int r_next = 2 * r + 1;
            bool flag = false;
            for (int num : nums)
            {
                if (bmp.count(r_next ^ (num >> k)))
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                r = r_next;
            }
            else
            {
                r = r_next - 1;
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> data = {3, 10, 5, 25, 2, 8};
    int r = s.findMaximumXOR(data);
    cout << r;
    return 0;
}