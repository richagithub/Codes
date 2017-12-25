/*
Practise(EASY)
ALSO : https://www.codechef.com/COOK89/problems/BTAR
Editorial : https://discuss.codechef.com/questions/119997/btar-editorial

*/

    #include <iostream>
    #include<vector>
    #include<stdlib.h>
    #include<stdio.h>
    using namespace std;
     
    int main() {
    	// your code goes here
    	int t,n,m,i=0;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%d",&n);
    		int freq[4];
    		freq[0]=freq[1]=freq[2]=freq[3]=0;
    		int sum=0;
    		for(i=0;i<n;i++)
    		{
    		scanf("%d",&m);
    		freq[m%4]+=1;sum+=m;
    		}
     
     
    	   if(sum%4!=0) 
    		cout<< "-1\n";
     
    	   else{
    		int step=0;
    		step+=(freq[2]/2);
    		freq[2]=freq[2]%2;
    		int k=min(freq[1],freq[3]);
    		step+=k;
    		freq[1]-=k;freq[3]-=k;
    		if(freq[2]!=0)
    		{
    		 step+= freq[2]*2;
    		 freq[1]==0 ? freq[3]-=(freq[2]*2) : freq[1]-=(freq[2]*2);  	
    		}
    		freq[1]>0 ? step+=(freq[1]/4)*3 :step+=(freq[3]/4)*3;
     
    		cout<< step<<"\n";
     
       	       }//else
    	}//t
    	return 0;
    }
