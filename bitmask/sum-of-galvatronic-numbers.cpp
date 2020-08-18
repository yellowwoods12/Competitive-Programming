#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isUnique(int i){
	int sets = 0;
	while(i){
		sets+=i&1;
		i=i>>1;
	}
	if(sets==1)
	   return 1;
	else
	   return 0;
}
bool isGalvatronic(int n){
	
	 int i=0;
	 int temp = n;
	 while(temp){
	 	if(n&int(pow(2,i))){
	 		if(!isUnique(i))
	 		  return 0;
	 	}
	 	i++;
	    temp = temp>>1;
	 }
	 return 1;
}
int main() {
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i] = x;
	}
	set<int> s;
	for(int i=1;i<=20;i++){
		s.insert(pow(2,i));
	}
/*	for(auto it = s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}*/
	int j=1;int k = n-1;
	long long int sum = 0;
	for(int i=0;i<n;i++){
		if(isGalvatronic(a[i]))
		  sum+=a[i];
	}
	cout<<sum<<endl;
	// your code goes here
	return 0;
}