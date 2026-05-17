#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[5];
bool visited[5];

void DFS(int v)
{
  visited[v] = true;
  cout << v << " ";

  for(int u : graph[v])
    {
      if(!visited[u]) DFS(u);
    }
}

void BFS(queue<int>& q)
{
  if (q.empty()) return;

  int v = q.front();
  q.pop();
  cout << v << " ";

  for (int u : graph[v])
    {
      if (!visited[u])
	{
	  visited[u] = true;
	  q.push(u);
	}
    }

  BFS(q);
}



int main()
{
  graph[0] = {3,4};
  graph[1] = {3};
  graph[2] = {4};
  graph[3] = {0,1};
  graph[4] = {0,2};

  cout << "DFS: ";
  DFS(0);
  cout <<"\n";

  for (int i=0; i<5; i++) visited[i] = false;
  
  queue<int> q;
  visited[0] = true;
  q.push(0);
  
  cout << "BFS: ", BFS(q), "\n";

  return 0;
}
