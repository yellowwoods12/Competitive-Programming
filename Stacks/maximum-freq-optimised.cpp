
//using map of stacks
#define ff first
#define ss second
#define ll long long int

class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
       int maxf;
public:
    FreqStack() {
       
        maxf = 0;
    }
    
    void push(int x) {
        if(freq.find(x)==freq.end()){
            freq[x] =1;
            group[1].push(x);
            maxf = max(maxf,1);
        }
        else{
            freq[x]+=1;
            group[freq[x]].push(x);
            maxf = max(maxf,freq[x]);
        }
    }
    
    int pop() {
       int el = group[maxf].top();
        group[maxf].pop();
        freq[el]--;
        if(group[maxf].size() == 0){
            maxf--;
        }
        return el;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */