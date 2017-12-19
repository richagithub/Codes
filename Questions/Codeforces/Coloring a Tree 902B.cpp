#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<vector>
using namespace std;

int dfs(int v,bool vis[], vector<int> adj[],int col[] ,int parent )
{
	int colmy=col[v],colp=col[parent];
	vis[v]=true;
	int sum=0,i=0;
	for(i=0;i<adj[v].size();i++)
	{
		if(!vis[adj[v][i]])
		sum+=dfs(adj[v][i],vis,adj,col,v);
	}
	if(colmy!=colp)
	  return sum+1;
	  else
	  return sum;
}

int main() {
	// your code goes here
	int n,m,i=0,j=0;
	scanf("%d",&n);
	vector <int> adj[n+1];
	bool vis[n+1];
	for(i=0;i<=n;i++)
	   vis[i]=false;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&m);
		adj[i].push_back(m);
		adj[m].push_back(i);
	}
	int c[n+1];
	c[0]=0;
	for(i=1;i<=n;i++)
	 scanf("%d",&c[i]);
	
	int parent=0;
	int steps=dfs(1,vis,adj,c,parent);
	 cout<<steps<<"\n";
	return 0;
}
