#include<bits/stdc++.h>
using namespace std;


// problem link : https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/signal-range/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        stack<int> s;
        vector<int> signal(n,0);
        vector<int> range(n,0);
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            signal[i]=x;
        }
        range[0] = 1;
        s.push(0);
        int maxv = 1;
         for(int i=1;i<n;i++){
         	
         	//condition check for popping index from stack
            while(!s.empty() && signal[s.top()]<=signal[i]){
               s.pop();
            }
            //condition check if stack is empty range is i+1 otherwise
            //the difference of current index and index on stack's top
            range[i] = (s.empty())?(i+1):(i-s.top());
            s.push(i);
           
        }
        for(int i=0;i<range.size();i++){
            cout<<range[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}