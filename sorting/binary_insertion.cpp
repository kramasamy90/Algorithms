#include <bits/stdc++.h>
using namespace std;

/**
Return the smallest index (i) such that x <= v[i].
If x is larger than all the elements v[l:r] then, -1 is returned.
**/
template <typename T>
T bin_search(vector<T>& v, T x, int l, int r){
	if(l == r && x <= v[l]) return l;
	else if(l == r) return -1;
	int m = (l+r)/2;
	if(x <= v[m]) return(bin_search(v, x, l, m));
	else if(x > v[m]) return(bin_search(v, x, m+1, r));
}

/**
Binary insertion sort is simillar to insertion sort, but differs in the 
step of insertion. This algorithm uses to binary search to find the appropriate
insetion location.

Proof hint: Use invariant - v[0] to v[i-1] is sorted.

Worst case time complexity: O(log(n)).

**/

template <typename T>
void sort(vector<T>& v){
	for(int i = 1; i < v.size(); i++){
		T x = v[i];
		int k = bin_search(v, x, 0, i-1);
		if(k == -1) k = i;
		if(v[k] < v[i]) k = i;
		int j;
		for(j = i; j > k; j--){
			v[j] = v[j-1];
		}
		v[j] = x;
	}
}

/**
Fills the input vector with random numbers in the range [lower, upper]
Note: here these random numbers are not drawn from uniform distribution.
**/

void get_rand_int(vector<int>& v, int lower, int upper){
	for(int i = 0; i < v.size(); i++){
		v[i] = random() % (upper - lower + 1) + lower;
	}
}

void print_array(vector<int>& v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << '\n';
}


int main()
{
	int size = 10;
	vector<int> v(10);
	get_rand_int(v, 0, 9);
	print_array(v);
	sort(v);
	print_array(v);
}
