using namespace std;
#include <bits/stdc++.h>

class Solution
{
public:
	void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &left_row, vector<int> &upper_diagonal, vector<int> &lower_diagonal, int n)
	{
		if (col == n)
		{
			ans.push_back(board);
			return;
		}

		for (int row = 0; row < n; row++)
		{
			if (left_row[row] == 0 && upper_diagonal[(n - 1) + col - row] == 0 && lower_diagonal[col + row] == 0)
			{
				board[row][col] = 'Q';
				left_row[row] = 1;
				lower_diagonal[col + row] = 1;
				upper_diagonal[(n - 1) + col - row] = 1;
				solve(col + 1, board, ans, left_row, upper_diagonal, lower_diagonal, n);
				board[row][col] = '.';
				left_row[row] = 0;
				lower_diagonal[col + row] = 0;
				upper_diagonal[(n - 1) + col - row] = 0;
			}
		}
	}

public:
	vector<vector<string>> solve_n_queens(int n)
	{
		vector<vector<string>> ans;
		vector<string> board(n);
		string s(n, '.');
		for (int i = 0; i < n; i++)
		{
			board[i] = s;
		}
		vector<int> left_row(n, 0), upper_diagonal(2 * n - 1, 0), lower_diagonal(2 * n - 1, 0);
		solve(0, board, ans, left_row, upper_diagonal, lower_diagonal, n);
		return ans;
	}
};

int main()
{
	int n = 8;
	Solution obj;
	vector<vector<string>> ans = obj.solve_n_queens(n);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << "Cach xep " << i + 1 << "\n";
		for (int j = 0; j < ans[0].size(); j++)
		{
			cout << ans[i][j];
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
