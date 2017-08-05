#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*Union find by path compression and union by ranks*/
int P[5000], R[5000];
void init() {
    for(int i=0;i<5000;i++) {
        P[i]=i;
        R[i]=0;
    }
}
int find(int n) {
    if(P[n] == n) return n;
    return P[n] = find(P[n]);
}
void join(int a, int b) {
    a=find(a);
    b=find(b);
    if(R[a]<R[b]) P[a] = b;
    else {
        P[b] = a;
        if(R[a] == R[b]) R[a]++;
    }
}

typedef pair<int,int> pii;
typedef pair<int,pii> edge;
typedef long long ll;

#define co(e) e.first
#define n1(e) e.second.first
#define n2(e) e.second.second
#define pb push_back

#define all(A) A.begin(), A.end()

int main() {
    int T;
    scanf("%d",&T);
    
    assert(T>=1 && T<=5);
    
    while(T--) {
        int N, M1;
        scanf("%d %d",&N,&M1);
        
        assert(N>=1 && N<=5000);
        assert(M1>=1 && M1<=20000);
        
        vector<edge> e1;
        for(int i=0;i<M1;i++) {
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            
            assert(a>=0 && a<N && b>=0 && b<N);
            assert(a != b);
            assert(c>=1 && c<=1000000000);
            
            e1.pb(edge(c,pii(a,b)));
        }
        
        
        /*Sorting the edges by weights*/
        sort(all(e1));
        
        /*
        Implement the kruskal's algorithm.
        Parse through M1 then.
        */
        int cnt=0;
        ll r1=0;
        init();
        vector<pii> mst;
        for(int i=0;i<M1;i++) if( find(n1(e1[i])) != find(n2(e1[i])) ) {
            join(n1(e1[i]),n2(e1[i]));
            r1 += co(e1[i]);
            mst.push_back(pii(n1(e1[i]),n2(e1[i])));
            cnt++;//counting no. of edges connected
        }
       printf("Minimum spanning tree total cost:%d\n",r1); 
       for(int i=0;i<mst.size();i++)
       printf("%d %d,",mst[i].first,mst[i].second);
       
    }
    return 0;
}


/*
INPUT:
1
5 7
0 1 5
1 4 6
0 2 1
2 1 2
1 3 3
2 3 7
3 4 4

OUTPUT   Success	time: 0 memory: 16104 signal:0

Minimum spanning tree total cost:10
0 2,2 1,1 3,3 4,
