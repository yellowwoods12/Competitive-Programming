// url for problem : https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/grandmaster/description/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n,0);
	stack<int> st;
    stack<int> st1;
    
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v[i]=x;
	}
	 int xs;
	cin>>xs;
    vector<int> x(xs,0);
    vector<int> finalcount(xs,0);
    for(int i=0;i<xs;i++){
        int p;
        cin>>p;
        x[i]=p;

    }
	vector<int> next(n,0);
    vector<int> prev(n,0);
	
	for(int i=n-1;i>=0;i--){
       while(!st.empty() && v[st.top()]<=v[i]){
		   st.pop();
	   }
	   next[i]=st.empty()?n-i-1:st.top()-i-1;
	   st.push(i);
	}
    for(int i=0;i<n;i++){
        while(!st1.empty() && v[st1.top()]<v[i]){
            st1.pop();
        }
        prev[i]=st1.empty()?i:i-st1.top()-1;
		st1.push(i);
    }
   
	map<int,long long int> mp;
	for(int i=0;i<n;i++){
		mp[v[i]]+=((prev[i]+next[i]+1)+ (prev[i]*next[i])) ;
		
	}
	for(int i=0;i<xs;i++){
		cout<<mp[x[i]]<<endl;
	}
	return 0;
}