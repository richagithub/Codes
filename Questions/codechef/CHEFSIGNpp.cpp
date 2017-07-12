/*
CHEFSIGN: Chef and Symbol Sequence 
Title Description The chef picked up a strange string s yesterday, which is a string containing only three symbols of '', '=' and '>'. Remember the length of the string N, the chef wants to string at the beginning, end, and every two characters inserted between a positive integer, a total of N + 1 number. When the chef wants to insert a number, the meaning of these symbols is correct. For example, if a and b are inserted before and after '<', then there should be a <b. Is similar to '=' and '>'. The chef can arbitrarily select the number inserted in [1, P], and the same number can be inserted into multiple locations. Please help chef to calculate the minimum value of P can be how much. The first line of the 
input format 
input contains an integer T representing the number of test data groups. Followed by T group data. Each row of data has only one line, including a string s. The guaranteed string contains only the characters '<', '=' and '>'. 
Output format 
For each set of data, output a line containing an integer representing the minimum value of P. 
Data range and subtasks • 1 ≤ T, N ≤ 105 • 1 ≤ N in each group of data ≤ 106 sub-task 1 (30 points): • 1 ≤ T, N ≤ 103 • 1 ≤ the sum of N in each group of data ≤ 104 
sub-task 2 (70 points): • no additional restrictions on the 
sample data 
input 4 <<< <> <<=> <= < 
output 4 2 2 3 
sample explanation 
below for each set of data were given a feasible (1 <2 <3 <4 1 <2> 1 <2 • 1 <2 = 2> 1 1 <2 = 2 <3

This question is actually a continuous calculation of the same number of characters to solve the number of cases to consider the fact that all is equal to the number of the case This is the answer is a
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int M=1e6+7;
int read(){
    int ans=0,f=1,c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}
    return ans*f;
}
int T,sum[M],cnt;
char s[M],c;
int main()
{
    T=read();
    while(T--){
        int mx=0,cnt=0;
        while((c=getchar())!='\n'&&c!=EOF) if(c!='=') s[++cnt]=c;//IMPRESSIVE
        if(!cnt){printf("1\n"); continue;}
        for(int i=1;i<=cnt;i++){
            if(s[i]==s[i-1]) sum[i]=sum[i-1]+1;
            else sum[i]=2;
            mx=max(mx,sum[i]);
        }
        printf("%d\n",mx);
    }
    return 0;
}
