#include <iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<math.h>

using namespace std;

void bfs(int s,vector<int> adj[],int n)
{
//start bfs
	bool visit[n+1];
	int dist[n+1],i=0;
	for(i=0;i<n+1;i++)
	{
		visit[i]=false,dist[i]=0;
	}
	visit[s]=true;dist[s]=0; //mark root visited
	queue<int> q;
	q.push(s);               //push root
	while(!q.empty())        //while loop on queue
	{
		int k=q.front();//printf("%d ",k);
		q.pop();              //pop
		for(i=0;i<adj[k].size();i++)//for all adjacent to k
		{
			if(!visit[adj[k][i]])     //if not visited
			  {
			  	visit[adj[k][i]]=true;  //mark visited
			  	dist[adj[k][i]]=dist[k]+1;//distance will increase adding 1 to parents distance
			  	q.push(adj[k][i]);      //push in queue
			  }
		}
	}
  
  
	for(i=1;i<n+1;i++)
	{
		if(i!=s && dist[i]==0)
            printf("-1 ");
        else if(i!=s && dist[i]>0)
		    printf("%d ",dist[i]*6);
	}
}

int main() {
	// your code goes here
	// freopen("input.txt", "r", stdin);
	int q,n,m,s=0,u,v;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&m);
		vector<int> adj[n+1];
		while(m--)
		{
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);//adjacency list
		}
		scanf("%d",&s);
		bfs(s,adj,n);//do bfs 
		printf("\n");
	}
	return 0;
}
