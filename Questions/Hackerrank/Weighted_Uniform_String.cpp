//Coder: Richa
//Date : 4.july.2017 -- 10:58pm
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
#define Max 10000001
using namespace std;
    int t[Max];



int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    
    int i=0;
    for(i=0;i<Max;i++)
        t[i]=0;
    int al[26];
     for(i=0;i<26;i++)
        al[i]=0;
    
    t[s[0]-'a'+1]++;
    al[s[0]-'a'+1]=(s[0]-'a'+1);
    for(i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])
        { al[s[i]-'a'+1]+=(s[i]-'a'+1); //cout<<al[s[i]-'a'+1]<<"\n";
          t[al[s[i]-'a'+1]]++;
        }
        else
        {
        t[s[i]-'a'+1]++;
        al[s[i]-'a'+1]=(s[i]-'a'+1);//cout<<al[s[i]-'a'+1]<< "\n";
        }
    }
    
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if(t[x]>0)
            printf("Yes\n");
        else
            printf("No\n");
        // your code goes here
    }
   
    /*
    for(i=0;i<20;i++)
        cout<< t[i]<<"\t";
    cout<<"\n al:";
    for(i=0;i<26;i++)
        cout<< al[i]<<"\t";
    */

    return 0;
}
