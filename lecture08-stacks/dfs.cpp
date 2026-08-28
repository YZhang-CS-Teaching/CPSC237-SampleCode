#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int main() {

  
  string name; //file name
  int n, m; //number of vertices and edges
  int start; //starting vertex

  //read in the file name
  cout << "Enter the file name: ";
  cin >> name;

  //read the graph into the adjacency list
  
  ifstream infile(name);

  //the first two integers in the file are the number of vertices
  //and the number of edges
  infile >> n >> m;

  //create a vector of size n+1,
  //since the vertex id starts from 1,
  //the 0'th position of the vector is unused
  vector<vector<int>> adj_list(n+1);

  //read the adjacency data into the adjancency list
  for (int i = 0; i < m; i++) {
    int u, v;
    infile >> u >> v;

    //since the graph is undirected, add both {u,v} and {v,u}
    adj_list[u].push_back(v);
    adj_list[v].push_back(u); 
  }
  
  infile.close();

  //create the boolean array to keep track
  //of which node is visited
  vector<bool> visited(n+1, false);

  cout << "Enter the starting vertex: ";
  cin >> start;

  //create a stack
  stack<int> s;

  //push the start vertex into stack
  s.push(start);
  
  
  cout << "DFS sequence: ";
  while(!s.empty())
    {
      //pop a vertex from stack
      int top = s.top();
      s.pop();

      //stack may contain same vertex twice
      //we only print if it is not visited

      if (visited[top]==false)
	{
	  visited[top] = true;
	  cout << top << " ";
	}

      //for all the adjacent vertices of top, if it is
      //not visited, then push it into stack
      for (int i = 0; i < adj_list[top].size(); i++)
	{
	  int node = adj_list[top][i];
	  if (visited[node]==false)
	    s.push(node);
	}
    }

  cout << endl;
  return 0;
}
