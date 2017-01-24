//MARKING ALL WITH SAMELLEST PRIME NUMBER
/*
here we are using sieve to mark all factors and so with this help we can do following:
1) Get all the prime numbers 
2) get count of numbers that have smallest prime factor as i;//eg problem "Ashu and Prime Factors"-Hackerearth
  - solution is here 
3) you can save smallest prime factor of j as i. So next to factorize just keep dividing by v[j]
*/
// SOLUTION OF "Ashu and Prime Factors"
#include <stdio.h>
#include<stdlib.h>
 
int v[1000001];
int count[1000001];
 
int main()
{
  int i=0,j=0;
  for(i=0;i<1000001;i++)
  v[i]=0;
  
  count[0]=0,count[1]=0;
  for(i=2;i<1000001;i++)
  {
      for(j=i+i;j<1000001;j=j+i)
      {if(!v[j]) 
      {
          count[i]++;
          v[j]=1;
      }}
  }
  
  int T,a=0;
  scanf("%d",&T);
  while(T--)
  {
      scanf("%d",&a);
      printf("%d\n",count[a]+1);
  }
  return 0;
}
