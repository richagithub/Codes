#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <math.h>
#define mod 1000000007
using namespace std;
long long int pow2[2][15];  //Stores power of 2 as ->
               // 2^25  , 2^50 , 2^100 , 2^200 , 2^800 , 2^1600 , 2^3200 , 2^6400 , 2^12800 , 2^51200 , 2^102400 ... 
               // 0     , 1    , 2     , 3     , 4     , 5      , 6      , 7      ,8        , 9       , 10 .....  14             

long long int get(int n)
{
    if(n<25)
        return (long long int)pow(2.0,n)%mod;
    int kdiv=n/25;    //cout<< kdiv<<endl;
    int k=(log ((double)kdiv))/(log ((double)2.0)) ;   //cout<< k<<endl;
    return (( pow2[1][k] %mod ) * (get(n-pow2[0][k]) %mod))%mod;
}

int main()
{
int i=0,n=0;
pow2[0][0]=25;
pow2[1][0]=((long long int)pow(2.0,25))%mod;
for(i=1;i<15;i++)
{
    pow2[0][i]=pow2[0][i-1] * 2;
    pow2[1][i]=((pow2[1][i-1])%mod * (pow2[1][i-1])%mod )%mod;
}

//cout<< pow2[0][14] << "\t" << pow2[1][14];
cin>> n; //input the power to which we want of 2.
long long int ans= get(n);
cout<<"ans:="<< ans<<endl;
    return 0;
}


/*
OUTPUT:
26
ans:=67108864

*/

