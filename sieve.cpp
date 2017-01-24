#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<vector>
#define lli long long int
#define MAX 100
using namespace std;

bool v[MAX]; // visited elements
int len, sp[MAX];

void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (lli i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (lli j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

vector <int> factorize(int k) {               //this is how to factorize k. //result is stored in vector<int>
	vector <int> ans;
	while(k>1) {
		ans.push_back(sp[k]);
		k/=sp[k];
	}
	return ans;
}

int main(){
	Sieve();
	for (int i = 0; i < 50; i++)	cout << sp[i] << "\t";

    return 0;
}
