#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& grid, int row, int col)
{
  int n = grid.size();
  for (int i=0; i<n; i++) if (grid[row][i] == 1) return false;

  for (int i=0; i<n; i++) if (grid[i][col] == 1) return false;

  //if (row>col) for (int i=row; i<n+row; i++) if (grid[i-row][i-col] == 1) return false;

  for (int i=row, j=col; i>=0 && j>=0; i--, j--) if (grid[i][j] == 1) return false;
  for (int i=row, j=col; i<n && j>=0; i++, j--) if (grid[i][j] == 1) return false;

  return true;
}

bool nqueen(vector<vector<int>>& grid, int col)
{
  int n = grid.size();
  if (col == n) return true;

  for (int row=0; row<n; row++)
    {
      if (isSafe(grid, row, col))
	{
	  grid[row][col] = 1;

	  if (nqueen(grid, col+1)) return true;

	  grid[row][col] = 0;
	}
    }
  return false;
}


int main()
{
  int n = 0;
  cout << "Enter board size: "; 
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 0));

  if (nqueen(grid, 0))
    {
      cout << "Soln found: " << endl;
      for (auto row : grid)
	{
	  for (auto cell : row) {cout << cell << " ";}
	  cout << endl;
	}
      cout << endl;
    }
      
  else cout << "No soln found" << endl; 

  return 0;
}
