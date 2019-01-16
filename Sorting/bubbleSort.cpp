#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int arr[]={1,4,7,9,2,4,6,7,8};
	int siz=sizeof(arr)/sizeof(arr[0]);
  
	//---sorting by bubble sort ----
  
  for(int i=0;i<siz-1;i++){  // keep 1 less than last array index
		for(int j=0;j<siz-1-i;j++){
			if(arr[j]>arr[j+1]){
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	
  //---sorting by bubble sort ends!  ----
  
  
	for(int i=0;i<siz;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}


//OUTPUT :
/*

1 2 4 4 6 7 7 8 9 

*/
