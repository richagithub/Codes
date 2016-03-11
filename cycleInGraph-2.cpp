#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<stack>
#define N 10005

using namespace std;
stack <int> s;
int main()
{
vector <int> adj[N];//array of vectors
int vt[N];
    int i,j,k,n,e,a,b;
    scanf("%d%d",&n,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);

    }
    for(i=0;i<N;i++)
        vt[i]=0;
    if(n!=(e+1))
      {
          printf("NO\n");
          return 0;
      }
      else
      {int i=1,parent,c=0,count=0;

       s.push(i);
       //parent=-1;
     //while
      while(!s.empty())
          {
            int k=s.top();
            s.pop();
            vt[k]=1;
            for(i=0;i<adj[k].size();i++)
              {
                  int d=adj[k][i];
                  if(!vt[d])
                  {
                      s.push(d);
                  }
                  else
                    {c=1;break;}
              }
             //parent=k;
            if(c==1)
            break;
            count++;
          }
          if(c==1 ||count!=n ) printf("NO\n");
          else
          printf("YES\n");

      }//else
    return 0;
}
/*
Not using two way adjacency list .Therefore not using parent check
