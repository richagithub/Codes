#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int countt; //countt is no of even parts
int dfs(int v, bool visit[], vector<int> adj[])
    {
        //cout<<v<<endl;
        visit[v]=true;
        vector<int> :: iterator i;
        int c=0;//calculate no of nodes in this subtree (childrens+itself)
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {
          
            if(!visit[*i])
                c+=dfs(*i,visit,adj);   //calculate no of childs
        }
        
        c=c+1;//counting itself
        //cout<<v << c<< endl;
        if(!(c&1))//even
        {
        countt++; //cout<<  v<< " " <<countt<<endl;
        c=0;return 0;//if no. of nodes are even , we detach it from tree and so returns 0;
        }
        
        return c;
    }


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     //freopen("input.txt","r",stdin);
    int N,M,a,b,i;
    scanf("%d%d",&N,&M);
    
    vector<int> adj[N+2];
    
    for(i=0;i<M;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    /*print adj list
    for(i=0;i<=N;i++)
    {
        vector<int>::iterator j;
        for(j=adj[i].begin();j!=adj[i].end();j++)
            cout<< " "<< *j;

        cout<<"\n";
    }
    */
    

    bool visit[N+1];/* MISTAKE -> Don't write visit[N];  */ 
    for(i=0;i<N+1;i++)
        visit[i]=false;//mark all visit false
  
    countt=0;
    int k=dfs(1,visit,adj);
    //cout<<k;
    if(k==0)
    cout<< --countt ;

    return 0;
}

/*

Try to find the no. of nodes in subtree. if a subtree has even no. of nodes , just detach it.

*/
