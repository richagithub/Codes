/*
Hackerrank Challenge :     Goldman Sachs CodeSprint 

Question: we have n-length array. On each day we can buy upto ith no. of stocks costing arr[i] dollars. 
If the customer has an amount of k dollars initially, find out the maximum number of stocks they can buy? 

Answer: sort acc to cost
        keep substracting cost*no.of stock from k
        to find no.of stocks is: min(k/cost , i)
        count no. of stocks and return.
*/
#include <bits/stdc++.h>
#include <stdio.h>
#include<math.h>
using namespace std;

void mycomp()
{    
}

long long int buyMaximumProducts(int n,long long int k, vector< pair<long long int,long long int> > a[]) {
    // Complete this function
    int i=0;
    long long int count=0,two,one;
    
    for(i=0;i<n;i++)
    {
        one=a[i][0].first, two=a[i][0].second;//one is cost
        long long int p=k/one;
        long long int ss=min(p,two);
        k=(k-ss*one);     //k-(no. of stock*cost);
        count+=ss;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long int,long long int> > arr[n];
    int ss=0;
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >>ss;
        arr[arr_i].push_back(pair<long long int,long long int>(ss,arr_i+1));
    }
    
   
    
    sort(arr,arr+n );
    long long int k;
    cin >> k;
    long long int result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
