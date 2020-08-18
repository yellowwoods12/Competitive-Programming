#include <bits/stdc++.h>
using namespace std;

#define maxv 1000
int lazy[maxv];
int st[maxv];

void constructUtil(int *st, int arr[], int ss,int se, int si){
    if(ss>se)
      return;
    if(ss==se){
        st[si] = arr[se];
        return;
    }
    int mid = ss+(se-ss)/2;
    constructUtil(st,arr,ss,mid,2*si+1);
    constructUtil(st,arr,mid+1,se,2*si+2);
    
    st[si] = max(st[2*si+1],st[2*si+2]);
    return;
}
void constructST(int *st,int arr[],int n){
    
    constructUtil(st,arr,0,n-1,0);
}

void updateUtil(int ss,int se,int us,int ue,int si,int inc){
    
    if(ss>se || us> ue || ue<ss || us>se){
        return;
    }
    
    if(lazy[si]!=0){
        st[si]+=lazy[si];
        
        if(ss!=se){
            lazy[2*si+1]+=lazy[si];
            lazy[2*si+2]+=lazy[si];
        }
        lazy[si] = 0;
    }
    if(us<=ss && ue>=se){
        st[si]+=inc;
        if(ss!=se){
            lazy[2*si+1]+=inc;
            lazy[2*si+2]+=inc;
        }
        return;
    }
    
    int mid = ss+ (se-ss)/2;
    updateUtil(0,mid,us,ue,2*si+1,inc);
    updateUtil(mid+1,se,us,ue,2*si+2,inc);
    
    st[si] = max(st[2*si+1],st[2*si+2]);
}

void update(int us,int ue,int inc,int n){
    
    updateUtil(0,n-1,us,ue,0,inc);
}

int queryUtil(int ss,int se,int us,int ue,int si){
    if(ss>se || ue<ss || us>se){
        return 0;
    } 
    
    if(lazy[si]!=0){
            st[si]+=lazy[si];
            while(ss!=se){
                lazy[2*si+1] +=lazy[si];
                lazy[2*si+2] +=lazy[si];
            }
           lazy[si]= 0;
        }
    if(us<=ss && ue>=se){
        return st[si];
    }
    int mid = ss+(se-ss)/2;
    return max(queryUtil(ss,mid,us,ue,2*si+1),queryUtil(mid+1,se,us,ue,2*si+2));
    
}
int query(int n,int us,int ue){
    
    return queryUtil(0,n-1,us,ue,0);
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	constructST(st,arr,n);
	
	update(0,3,0,n);
	
	cout<<query(n,0,2)<<endl;
}