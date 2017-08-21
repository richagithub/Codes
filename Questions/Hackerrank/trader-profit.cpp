/*
Hackerrank Challenge :     Goldman Sachs CodeSprint 
Problem: n days are given with stock for each day.
         You have to find k no. of transaction 
         (one transaction is complete process of buying +selling and none of transaction can overlap) that give maximum profit.
Answer : This is a Dynamic programming problem
         Optimal Solution : maximum profit
         Overlapping subproblem: on nth day, to do kth transaction(pr[k+1][n])... we can include this stock or we may not.
         Profit0: If we donot include this stock , then ans is=>  pr[Thistrans][n-1]
         Profit1: If we include Thisday's stock , then ans is=>
                                (pr[Lasttrans][m])+ ( Arr[Thisday's] - Arr[m])   ...0<=m< Thisday
                                (profit uptill last trans)+(profit due to transaction(buying on m + selling on Thisday))   
         profit on pr[Thistrans][Thisday] = max( Profit_including_this_days_stock  , Profit_not_including_this_days_stock  )
                                          = max( Profit1 , Profit0);


*/
#include <bits/stdc++.h>
 
using namespace std;

int traderProfit(int k, int n, int A[]) {
int pr[k+1][n];
int i=0,j=0,z=0;    
    for(i=0;i<n;i++)
        pr[0][i]=0;
    for(i=0;i<=k;i++)
        pr[i][0]=0;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<n;j++)
        {int maxi=0;
         for(z=0;z<j;z++)
             maxi=max(A[j]-A[z]+pr[i-1][z], maxi);
         pr[i][j]=max(maxi, pr[i][j-1]);   
        }
        
    }
 
    return pr[k][n-1];
    
}
 
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        int arr[n+1];
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}
 
