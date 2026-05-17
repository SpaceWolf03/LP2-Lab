#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int heuristic(int x, int y, int gx, int gy)
{
  return abs(x-gx)+abs(y-gy);
}

void aStar(vector<vector<int>> grid, int sx, int sy, int gx, int gy)
{
  int n = grid.size();
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  priority_queue<pair<int,int>> pq;
  pair<int, int> curr, top, bottom, right, left, nmin;
  int h = 0;
  int hmin = 100;

  cout<< "(" <<  sx << ","<< sy << ")" << endl;
  pq.push({sx,sy});

  while (!pq.empty())
    {
      curr = pq.top();
      if (curr == make_pair(gx, gy))
	{
	  cout << "Goal reached!" << endl;
	  return;
	}
	
      top = {curr.first, curr.second+1};
      bottom = {curr.first, curr.second-1};
      right = {curr.first+1, curr.second};
      left = {curr.first-1, curr.second};

      for (auto node : {top, bottom, right, left})
	{
	  if (node.first>=n || node.first<0 || node.second>=n || node.second<0 || grid[node.first][node.second]==-1) continue;

	  h = heuristic(node.first, node.second, gx, gy);
	  if (h<hmin)
	    {
	      hmin = h;
	      nmin = {node.first, node.second};
	      cout << h << " - ";
	    }
	  
	}
      pq.push(nmin);
      cout << "(" << nmin.second << "," << nmin.first << ")" << endl;
    }

  cout << "Couldnt reach the goal" << endl;
  return;
}

int main()
{
  vector<vector<int>> grid =
    {
      {0,-1,3},
      {1, -1,3},
      {3, 2,0},
    };

  aStar(grid, 0, 0, 2, 2);

  return 0;
}
