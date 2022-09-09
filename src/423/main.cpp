#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    string originalDigits(string s)
    {
        unordered_map<char, int> hmp;
        for (char c : s)
        {
            hmp[c]++;
        }

        vector<string> list(10, "");
        // six
        if (hmp['x'] != 0)
        {
            list[6] = string(hmp['x'], '6');
            hmp['s'] -= hmp['x'];
            hmp['i'] -= hmp['x'];
            hmp['x'] = 0;
        }

        // zero
        if (hmp['z'] != 0)
        {
            list[0] = string(hmp['z'], '0');
            hmp['e'] -= hmp['z'];
            hmp['r'] -= hmp['z'];
            hmp['o'] -= hmp['z'];
            hmp['z'] = 0;
        }

        // two
        if (hmp['w'] != 0)
        {
            list[2] = string(hmp['w'], '2');
            hmp['t'] -= hmp['w'];
            hmp['o'] -= hmp['w'];
            hmp['w'] = 0;
        }

        // four
        if (hmp['u'] != 0)
        {
            list[4] = string(hmp['u'], '4');
            hmp['f'] -= hmp['u'];
            hmp['o'] -= hmp['u'];
            hmp['r'] -= hmp['u'];
            hmp['u'] = 0;
        }

        // eight
        if (hmp['g'] != 0)
        {
            list[8] = string(hmp['g'], '8');
            hmp['e'] -= hmp['g'];
            hmp['i'] -= hmp['g'];
            hmp['h'] -= hmp['g'];
            hmp['t'] -= hmp['g'];
            hmp['g'] = 0;
        }

        // three
        if (hmp['h'] != 0)
        {
            list[3] = string(hmp['h'], '3');
            hmp['t'] -= hmp['h'];
            hmp['r'] -= hmp['h'];
            hmp['e'] -= 2 * hmp['h'];
            hmp['h'] = 0;
        }

        // seven
        if (hmp['s'] != 0)
        {
            list[7] = string(hmp['s'], '7');
            hmp['v'] -= hmp['s'];
            hmp['n'] -= hmp['s'];
            hmp['e'] -= 2 * hmp['s'];
            hmp['s'] = 0;
        }

        // five
        if (hmp['v'] != 0)
        {
            list[5] = string(hmp['v'], '5');
            hmp['f'] -= hmp['v'];
            hmp['i'] -= hmp['v'];
            hmp['e'] -= hmp['v'];
            hmp['v'] = 0;
        }

        // one
        if (hmp['o'] != 0)
        {
            list[1] = string(hmp['o'], '1');
            hmp['n'] -= hmp['o'];
            hmp['e'] -= hmp['o'];
            hmp['o'] = 0;
        }

        // nine
        if (hmp['i'] != 0)
        {
            list[9] = string(hmp['i'], '9');
            hmp['n'] -= hmp['i'] * 2;
            hmp['e'] -= hmp['i'];
            hmp['i'] = 0;
        }

        string r = "";
        for (string v : list)
        {
            r += v;
        }

        return r;
    }
};

int main()
{
    Solution s;
    string r = s.originalDigits("owoztneoer");
    return 0;
}