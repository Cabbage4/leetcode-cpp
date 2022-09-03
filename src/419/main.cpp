#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<bool>> &book, vector<vector<char>> &board, int x, int y)
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
            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board[0].size() && board[nx][ny] == 'X' && !book[nx][ny])
            {
                dfs(book, board, nx, ny);
            }
        }
    }

public:
    int countBattleships(vector<vector<char>> &board)
    {
        int r = 0;
        vector<vector<bool>> book(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'X' && !book[i][j])
                {
                    r++;
                    dfs(book, board, i, j);
                }
            }
        }

        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> v = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    int r = s.countBattleships(v);
    return 0;
}