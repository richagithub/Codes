// C++ code to demonstrate operations of Binary Index Tree
//Fenwick Tree 
//Best Tutorial : topcoder : https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
//you can use BIT.cpp of brian's codebook:https://github.com/kartikkukreja/blog-codes/blob/master/src/BIT%20or%20Fenwick%20Tree%20Data%20Structure.cpp

//Code from:Geeks for Geeks
#include <iostream>
using namespace std;
 
/*            n  --> No. of elements present in input array.   
    BITree[0..n] --> Array that represents Binary Indexed Tree.
    arr[0..n-1]  --> Input array for whic prefix sum is evaluated. */
 
/* Returns sum of arr[0..index]. This function assumes
   that the array is preprocessed and partial sums of
    array elements are stored in BITree[].    */
int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result
 
    index = index + 1;// index in BITree[] is 1 more than the index in arr[]
 
    while (index>0)   // Traverse ancestors of BITree[index]
    {   
        sum += BITree[index]; // Add current element of BITree to sum
 
        index -= index & (-index);// Move index to parent node in getSum View
    }
    return sum;
}
 
/* Updates a node in Binary Index Tree (BITree) at given index
   in BITree.  The given value 'val' is added to BITree[i] and 
   all of its ancestors in tree  */
void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;  // index in BITree[] is 1 more than the index in arr[]
 
    while (index <= n)   // Traverse all ancestors and add 'val'
    {
       
       BITree[index] += val; // Add 'val' to current node of BI Tree
 
       index += index & (-index);  // Update index to that of parent in update View
    }
}
 
/* Constructs and returns a Binary Indexed Tree for given
 array of size n  */
int *constructBITree(int arr[], int n)
{
   
    int *BITree = new int[n+1];   // Create and initialize BITree[] as 0
    for (int i=1; i<=n; i++) 
        BITree[i] = 0;
 
    
    for (int i=0; i<n; i++)       // Store the actual values in BITree[] using update()
        updateBIT(BITree, n, i, arr[i]);
 
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
 
    return BITree;
}
 
 
// Driver program to test above functions
int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
         << getSum(BITree, 5);
 
    freq[3] += 6;         // Lets test the update operation
    updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]
 
    cout << "\nSum of elements in arr[0..5] after update is "
         << getSum(BITree, 5);
 
    return 0;
}
