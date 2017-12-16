#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
#define mk(a,b) make_pair(a,b)

using namespace std;


int main()
{
    //freopen("input.txt","r",stdin);

    int p[]={-2,-2,0,2,2,0};
    int q[]={-1,1,2,1,-1,-2};//Remember x is row and y is column in grid[x][y]

    int n=0;
    scanf("%d",&n);//no. of rows and column
    int xs,ys,xe,ye;
    scanf("%d%d%d%d",&xs,&ys,&xe,&ye);//start and end coordinate
    
  /*_______*/
 /*  BFS  */
/*_______*/

    int grid[n][n];
    bool visit[n][n];
    pii parent [n][n];                 ///to track the path                    ---IMPORTANT
    int i=0,j=0;
    for(i=0;i<n;i++)      //initialize grid ,visit and parent matrix
        for(j=0;j<n;j++)
           {
               grid[i][j]=0;visit[i][j]=false;parent[i][j]=mk(0,0);
           }

    queue<pii> qu;
    int z=0;  // z is a FLAG to know whether destination is reached
    qu.push(mk(xs,ys));  //push 1st element 
    visit[xs][ys]=true;
    grid[xs][ys]=0;
    parent[xs][ys]=mk(-1,-1);
    pii s;
    int x=0,y=0;

    while(!qu.empty() && z==0)
    {
        int x1=0,y1=0;
        pii t=qu.front();
        qu.pop();
        x=t.first,y=t.second;
        s=mk(x,y);
        for(i=0;i<6;i++)
        {
            x1=x+p[i];
            y1=y+q[i];
            if(x1<0 ||x1>=n || y1<0 || y1>=n) //range check
            {
                continue;
            }
            else{
                if(!visit[x1][y1])
                {
                   // cout<<x1 <<"-" << y1<<"\n";
                    qu.push(mk(x1,y1));
                    visit[x1][y1]=true;
                    parent[x1][y1]=s;
                    grid[x1][y1]=grid[x][y]+1;
                }
                if(x1==xe && y1==ye)  {z=1;break;}  //if destination reached -> mark the FLAG and break out
            }
        }

    }

    if(z==0)
        printf("Impossible\n");// we got no Flag i.e. no destination was reached
    else{
        cout<< grid[xe][ye]<<"\n";

        stack <pii> st;   //tracking path  -> put path cordinates in a stack
        while(xe!=-1 && ye!=-1)
        {
            int xtemp=xe,ytemp=ye;
            st.push(mk(xtemp,ytemp));
            xe=parent[xtemp][ytemp].first;
            ye=parent[xtemp][ytemp].second;
        }
        pii t=st.top(); // now pop the stack one-by-one and display the route
        st.pop();       //pop 1st element i.e. source
        x=t.first,y=t.second;
        int x1=0,y1=0;
        while(!st.empty())
        {
        t=st.top();st.pop();
        x1=t.first,y1=t.second;
        //cout<< x1<<":"<<y1<<"\n";
        
            if(x1==x)
            {
            if(y<y1)  printf("R ");
            else printf("L ");
            }
            if(x1<x)
            {
            if(y1<y) printf("UL ");
            else printf("UR ");
            }
            if(x1>x)
            {
            if(y1<y) printf("LL ");
            else printf("LR ");
            }
            x=x1,y=y1;                                                        ///DONT FORGET 

        }

    }

    return 0;
}
