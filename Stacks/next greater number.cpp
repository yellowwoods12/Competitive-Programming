/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
//url : https://www.hackerearth.com/problem/algorithm/next-greater-number/
// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n,0);
	stack<int> st;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v[i]=x;
	}
	st.push(n-1);
	vector<int> next(n,0);
	next[n-1]=-1;
	for(int i=n-2;i>=0;i--){
       while(!st.empty() && v[st.top()]<=v[i]){
		   st.pop();
	   }
	   next[i]=st.empty()?-1:v[st.top()];
	   st.push(i);
	}
	for(int i=0;i<n;i++){
		cout<<next[i]<<" ";
	}
	return 0;
}