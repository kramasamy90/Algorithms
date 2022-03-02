#include <bits/stdc++.h>
using namespace std;

/**
* Insertion sort.
* Insert v[i] into the sorted array v[0]-v[i-1].
* Proof hint: Use invariant - v[0] to v[i-1] is sorted.
* Worst case time complexity: O(n^2).
**/

template<typename T>
void sort(vector<T>& v){
	for(int i = 1; i < v.size(); i++){
		T temp = v[i];
		int j;
		for(j = i-1; j >= 0 && temp < v[j]; j--){
			swap(v[j+1], v[j]);
		}
		v[j+1] = temp;
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
