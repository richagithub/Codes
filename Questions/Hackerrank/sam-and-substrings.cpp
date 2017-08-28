/*
hackerrank dynamic programming

for N = 5312,
all possible substrings are
SIGMA = 5 3 1 2 53 31 12 531 312 5312 =6244
for 0<N< 2* 10^5  there will be ~ 2*10^10

Using dynamic programming:
with a little bit of rearrangement,

5 | 3 53 | 1 31 531 | 2 12 312 5312
Now, given sd[i], let us see if we can calculate sd[i+1]
sd[2] = 1 + 31 + 531 = 563   :--

[   sd[3] = 2 + 12 + 312 + 5312
    sd[3] = 2 + 10 + 2 + 310 + 2 + 5310 + 2
    sd[3] = 4 * 2 + 10 * (1 + 31 + 531 )
    sd[3] = (3 + 1) * *N[3]* + 10 * *sd[2]*    ]
 





*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define mod 1000000007         // IMPORTANT! donot write 1000000000+7

using namespace std;

long long int solve(string st)
{
   int l=st.length();
   long long int sum[l+1];     //   long Is Necessary
    int i=0,j=0;
    long long int k=0;
    sum[0]=st[0]-'0';
    k=sum[0];
    for(i=1;i<l;i++)
    {
        sum[i]=((((i+1)%mod)*((st[i]-'0')%mod))%mod + (10*sum[i-1])%mod)%mod;    // sum[i]=(i+1)*(int of st[i]) + (10* sum[i-1])
        k=((k%mod)+(sum[i])%mod)%mod;
    }
    return k;
    
}

int main() {
    string s;
    cin>> s;
    long long int l=solve(s);
    cout<< l;
    return 0;
}
