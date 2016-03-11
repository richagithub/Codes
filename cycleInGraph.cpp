#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<stack>
#define N 10005

using namespace std;
stack <pair<int,int> > s;
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
        adj[b].push_back(a);
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
       parent=-1;
       s.push(make_pair(i,parent));
   
      while(!s.empty())
          {
            pair<int,int> kk=s.top();
            s.pop();
            int k=kk.first;
            int p=kk.second;
            vt[k]=1;//printf("parent=%d\n",p);
            for(i=0;i<adj[k].size();i++)
              {
                  int d=adj[k][i];
                  if(!vt[d])
                  {
                      p=k;s.push(make_pair(d,p));
                  }
                  else if(d!=p)//else if d is visited , then it must be the parent. If its not parent then there is a cycle
                    {c=1;
                    //printf("d=%d parent=%d\n",d,p);
                    break;}
              }

            if(c==1)
            break;
            count++;
          }
          if(c==1  ) printf("NO\n");
          else if(count!=n) printf("NO\n");
          else  printf("YES\n");

      }//else
    return 0;
}
//Using two way adjacency list .Therefore using parent check
