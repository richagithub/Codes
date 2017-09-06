#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h> 
using namespace std;

#define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff

int arr[MAX];
int add1[MAX];
int* tree[MAX];
int tree_ans[MAX];


/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node]=add1+a; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	
}

void build_tree_ans(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree_ans[node]=0; // Init value
		return;
	}
	
	build_tree_ans(node*2, a, (a+b)/2); // Init left child
	build_tree_ans(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree_ans[node] = 0;
}



/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j) {
    
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a == b) { // Leaf node
    	        add1[a]++;
    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child

	tree[node] = 0; // Updating root with max value
}

void update_tree_ans(int node, int a, int b, int i, int j, int val) {
    
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a == b) { // Leaf node
    		arr[a]+=val;
    		return;
	}

	update_tree_ans(node*2, a, (a+b)/2, i, j, val); // Updating left child
	update_tree_ans(1+node*2, 1+(a+b)/2, b, i, j, val); // Updating right child

	tree_ans[node] = 0;
}


int main() {
	int t,i=0,j=0;
	int N,m;
	cin>> t;
	while(t--)
	{
		int k=0,j=0,fir=0;
		cin>> N >>m;
		int array1[m][2],array2[m][2];
		for(i=0;i<m;i++)
		{
			cin>> fir;
			if(fir==1)
			{
			  cin>>array1[j][0]>>array1[j][1];j++;
			}
			else
			{
				cin>>array2[k][0]>>array2[k][1];k++;
			}
		}
		
		for(i = 0; i <j ; i++) add1[i] = 0;
		build_tree(1,0,j-1);
		for(i=0;i<k;i++)//array2 updates add1
		   update_tree(1,0,j-1,(array2[i][0])-1 ,(array2[i][1])-1);
		   
	for(i=0;i<j;i++)//array2 updates add1
		   cout<< add1[i] <<" ";
		cout<<endl;	   
		  
	    for(i = 0; i <N ; i++) arr[i] = 0;
		build_tree_ans(1,0,N-1);   
		for(i=0;i<j;i++)//array2 updates add1
		   update_tree_ans(1,0,N-1,(array1[i][0])-1,(array1[i][1])-1,add1[i]);
		
       for(i=0;i<N;i++)//array2 updates add1
		   cout<< arr[i] <<" ";
		cout<<endl;
		
	}
}
