/*
Problem: http://www.spoj.com/problems/KQUERY/

Solution: Offline(save all query in a vector) + sort(order by k) +
          Segment Tree(build tree, update tree, query tree)

Explanition: 

*/

#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<iostream>
#define MAX 120500   // tree size -> Gives SIGSEV error for 60500 ->???? WHYY 
using namespace std;
int tree[MAX];
 
struct node{
int l,r,k,pl;               //'pl' to store order of "Query" before sorting
};
 
bool sortfunc(node* const q1,node* const q2)  //sort the vector v[n+q]
{
    if(q1->k == q2->k)
    {
    	return (q1->l)>(q2->l);  //order on basis of l(asc)[ l==-1 is before l>=0 ]
    }
    return (q1->k)>(q2->k);    //order on basis of k (desc)
}
 
vector <node*> v;    //vector to store all queries
 
void build_tree() {    // initialize all cells of tree equal to 0
    int i=0;
    for(i=0;i<MAX ; i++)
        tree[i]=0;
}
 
 
void update(int nod, int a, int b, int i, int j, int value) {  //in this question a is equal to b and value ==1
	                                        //store 1 at all leaves to be updated and store the sum in inner nodes
	                                        // this sum gives ans for that range
 
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
 
  	if(a == b) { // Leaf node
    		tree[nod] += value;
    		return;
	}
 
	update(nod*2, a, (a+b)/2, i, j, value); // Updating left child
	update(1+nod*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
	tree[nod] = tree[nod*2] + tree[nod*2+1]; // Updating root with sum value
}
 
int query(int nod, int a, int b, int i, int j) {          // simple query in the range[i,j] for the sum
 
	if(a > b || a > j || b < i) return 0; // Out of range
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[nod];
 
	int q1 = query(nod*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query(1+nod*2, 1+(a+b)/2, b, i, j); // Query right child
 
	int res = q1 + q2; // Return final result
 
	return res;
}
 
 
int main()
{
    //freopen("input.txt","r",stdin);
    int a,n,q,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        node* t=(node* )malloc(sizeof(node));
        scanf("%d",&t->k);
        t->l=-1,t->r=i;
        v.push_back(t);
    }
    scanf("%d",&q);
    int qr[q];         //qr[] to store the result in proper order
    for(i=0;i<q;i++)
    {
        node* t=(node* )malloc(sizeof(node));
        scanf("%d%d%d",&t->l,&t->r,&t->k);
        t->l=t->l -1, t->r=t->r -1, t->pl = i;
        v.push_back(t);
    }
	//sort the vector
    sort(v.begin(),v.end(),sortfunc);
    build_tree();       //build tree, initialize with zeros
    for(i=0;i<v.size();i++)
    {
        if((v[i])->l ==-1)   // for query of type 1
        {
        	int z=v[i]->r;
            update(1,0,n-1,z,z,1);
        }
        else               // for query of type 2
        {
         int res=query(1,0,n-1,v[i]->l , v[i]->r );
         qr[v[i]->pl]=res;    // store result in qr at proper order
            //cout<< res<<"\n";
        }
 
    }
    for(i=0;i<q;i++)
    printf("%d\n",qr[i]);  
     
    return 0;
}
