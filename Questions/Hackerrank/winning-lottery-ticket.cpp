

#include <iostream>
using namespace std;

int frq[1030];
int main() {
	// your code goes here
	int n,i=0,j=0,max=0;
	string id;
	cin>> n;
	
	for(i=0;i<1030;i++)
	frq[i]=0;
	
	for( j =0; j<10;j++)
                {
                 max |= 1<<j;
                   //cout<<"max = "<<max<<endl;
                }
	
	for(i=0;i<n;i++)
	    {
	    	int b=0,r=0;
	    	cin>>id;
	    	for(j=0;j<id.length();j++)
	    	{
	    	r=id[j]-48;	
	    	b= b|(1<<r);	//this is the code of the string 
	    	}
	    	frq[b]++;//cout<< b;
	    }
	    
	 //for(i=0;i<1030;i++)	   if(frq[i]>0) {cout<<i<<": "<< frq[i]<<"\n";}
	
	int count=0;
	   for(i=0;i<1030;i++)
	   {
	   	if(frq[i]>0)
	   	{
	   		for(j=i+1;j<1030;j++)
	   		{
	   			if(frq[j]>0)
	   			{
	   				if((i|j) == max)
	   				count=count+frq[i]*frq[j];
	   			}
	   		}
	   	if(i==max)
	   	count+=((frq[i]*(frq[i]-1))/2);
	   	}
	   }
	   cout<< count<<"\n";
	return 0;
}
