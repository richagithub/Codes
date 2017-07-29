/*
Finding largest and secong largest ints in a array 
with order of O(n)
Here we just keep to variables one,two to store largest and second largest respectively;
We do the usual method of comparing first for largest , then for second largest at the same time of checking the int.
But I did one mistake of not taking largest value into second large value , when another largest is found.Look down:        */

#include <stdio.h>
#include <vector>
using namespace std;
int main(void) {
  long long int i=0;
	vector<long long int> arr;
	char temp; 
	long long int one=0 , two=0,len=0,pos=0;
 
 do{
        scanf("%lld%c", &i, &temp); 
        arr.push_back(i);
        len++;
        if(i>one)
        {two=one;one=i;pos=len;}  //two=one is IMPORTANT, as we are transfering the then largest to become second largest;
        else if(i>two && len!=pos)//else we will miss that large value
        two=i;                    //then now largest(i) becomes one/largest;pos stores new largest position/index;
    } while(temp!= '\n');
 
 for(i=0;i<arr.size();i++)
 printf("%d ",arr[i]);
 return 0;
 }
