#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<vector<int>> directs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int x, int y, vector<vector<bool>> &book, vector<vector<int>> &heights)
    {
        if (book[x][y])
        {
            return;
        }

        book[x][y] = true;

        for (int i = 0; i < directs.size(); i++)
        {
            int nx = x + directs[i][0];
            int ny = y + directs[i][1];
            if (0 <= nx && nx < heights.size() && 0 <= ny && ny < heights[x].size() && !book[nx][ny] && heights[x][y] <= heights[nx][ny])
            {
                dfs(nx, ny, book, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> leftTop(row, vector<bool>(col, false));
        vector<vector<bool>> rightBottom(row, vector<bool>(col, false));

        for (int i = 0; i < col; i++)
        {
            dfs(0, i, leftTop, heights);
        }

        for (int i = 0; i < row; i++)
        {
            dfs(i, 0, leftTop, heights);
        }

        for (int i = 0; i < col; i++)
        {
            dfs(row - 1, i, rightBottom, heights);
        }

        for (int i = 0; i < row; i++)
        {
            dfs(i, col - 1, rightBottom, heights);
        }

        vector<vector<int>> result;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (leftTop[i][j] && rightBottom[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> v2 = {{2, 1}, {1, 2}};
    Solution *s = new Solution();

    vector<vector<int>> result = s->pacificAtlantic(v2);

    return 0;
}