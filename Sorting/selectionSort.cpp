#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int arr[]={1,5,3,7,9,4,3,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	
  // ---- Sorting by Seclection sort -----//
	for(int i=0;i<n;i++){
		int sm=arr[i],pos=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<sm){
				sm=arr[j];pos=j;
			}
		}//for j closed
		
		int temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}//for i closed
	
  //---- Sorting ends!----//
  
  
  
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

/*
INPUT:  1 5 3 7 9 4 3 8
OUTPUT: 1 3 3 4 5 7 8 9 
*/

/* HOW SELECTION SORT WORKS :

First we search the smallest element from arr[0]....arr[n-1] and exchange it with arr[0].
This will palce the smallest element of the list at 0th position of array. 
Now we will search smallest element from remaining elements arr[1]......arr[n-1] and exchange it with arr[1]
Complexity : O(n^2)

*/
