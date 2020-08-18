#include <bits/stdc++.h>
using namespace std;

//question - https://practice.geeksforgeeks.org/problems/convex-hull/0 
// Jarvis Algorithm

struct Point{
    int x;
    int y;
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};


int orientation(Point p, Point q, Point r){
    int sign = ((q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x));
    if(sign == 0)
       return 0;
    
    return sign>0?1:2;
}

bool compare(Point p, Point q){
    if(p.x<q.x)
       return 1;
     else if(p.x == q.x && p.y<q.y)
       return 1;
     
     return 0;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<Point> points(n,{0,0});
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            points[i].x = x;
            points[i].y = y;
        }
        
        if(n<3 || (n==3 && points[0].x==1 && points[1].x ==1 && points[2].x ==1)){
            cout<<"-1"<<endl;
            continue;
        }
       
        
        int l = 0;
        for(int i=1;i<n;i++){
            if(points[i].x < points[l].x){
                l=i;
            }
        }
        int p =l,q;
        int flag =0;
        vector<Point> result;
        do
        {
           result.push_back(points[p]);
          
          q = (p+1)%n;
          
          for(int i=0;i<n;i++){
              if(orientation(points[p],points[i],points[q]) == 2){
                  q = i;
              }
          }
          
          p=q;
              
        } while (p!=l);
        
        sort(result.begin(),result.end(),compare);
        for(int i=0;i<result.size();i++){
            cout<<result[i].x<<" "<<result[i].y;
            if(i!=result.size()-1){
                cout<<", ";
            }
        }
        cout<<endl;
    }
	//code
	return 0;
}