//question link :   https://www.geeksforgeeks.org/maximum-product-of-indexes-of-next-greater-on-left-and-right/

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	stack<int> left;
	stack<int> right;
	
	vector<int> lmax(n,0);
	vector<int> rmax(n,0);
	
	for(int i=0;i<n;i++){
	    while(!left.empty() && arr[left.top()]<= arr[i]){
	        left.pop();
	    }
	    lmax[i] = left.empty()?0:left.top()+1;
	    left.push(i);
	}
	
	for(int i=n-1;i>=0;i--){
	    while(!right.empty() && arr[right.top()]<= arr[i]){
	        right.pop();
	    }
	    rmax[i] = right.empty()?0:right.top()+1;
	    right.push(i);
	}
	
	int maxprod = INT_MIN;
	for(int i=0;i<n;i++){
	   maxprod = max(maxprod,lmax[i]*rmax[i]);
	}
	cout<<maxprod;
	
    return 0;
	
}