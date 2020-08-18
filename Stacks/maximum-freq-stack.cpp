//intuitive approach (doesn't work for very large cases)

#define ff first
#define ss second

class FreqStack {
    unordered_map<int,int> st;
        int freq;
      stack<int> s;
      stack<int> s2;
public:
    FreqStack() {
        freq=0;
    }
    
    bool empty(){
       if(st.size()==0)
           return 1;
        
    int c = 0;
      for(auto it = st.begin();it!=st.end();it++){
        if(it->ss == 0)
            c++;
      }
        if(c==st.size())
             return 1;
        else
            return 0;
    }
    
    int returnmaxf(){
        
        for(auto it = st.begin();it!=st.end();it++){
            if(it->ss == freq){
               // cout<<it->ff;
                return it->ff;
                
            }
        }
        return -1;
    }
    
     void findmaxf(){
        int minv = INT_MIN;
        for(auto it = st.begin();it!=st.end();it++){
            minv = max(minv,it->ss);
        }
         freq = minv;

    }
    void push(int x) {
        if(st.find(x)==st.end()){
            st[x] = 1;
            freq = max(freq,1);
        }
        else{
            st[x]+=1;
            freq = max(freq,st[x]);
        }
        s.push(x);
    
    }
    
    int pop() {
        
        
        while(st[s.top()]!= freq){
            int f = s.top();
            //cout<<st[s.top()];
            s.pop();
            s2.push(f);
            
            
        }
        if(st[s.top()]==freq){
         //  cout<<s.top();
            int element = s.top();
            st[element]--;
            s.pop();
            
            
            findmaxf();
             //cout<<freq;
            while(!s2.empty()){
                int t = s2.top();
                s2.pop();
                s.push(t);
              //  cout<<t;
            }
         /*    for(auto it = st.begin();it!=st.end();it++){
             cout<<it->ff<<" "<<it->ss<<"next";
           }
            cout<<"after";*/
            return element;
            
        }
        return -1;
    }
       
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */