class Solution {
public:

    //question link : https://www.lintcode.com/problem/expression-evaluation/
    /**
     * @param expression: a list of strings
     * @return: an integer
     */
     int checkPrecedence(string op){
         if(op == "+" || op=="-")
           return 1;
         else if(op=="*" || op=="/")
           return 2;
          else
           return 0;
     }
     int applyop(int v1,int v2, string op){
         if(op=="+")
           return v1+v2;
         if(op=="-")
           return v1-v2;
         if(op=="*")
           return v1*v2;
         if(op=="/")
           return v1/v2;
           
       return 0;
     }
     
    int evaluateExpression(vector<string> &expression) {
        stack<int> value;
        stack<string> op;
        for(vector<string>::iterator it = expression.begin();it!=expression.end();it++){
            if(*it == "+" || *it == "-" || *it=="*" || *it=="/"){
                if(op.empty() || checkPrecedence(*it) > checkPrecedence(op.top())){
                    op.push(*it);
                    cout<<op.top();
                }
                else{
                    cout<<op.top();
                    while(!op.empty() && checkPrecedence(*it)<=checkPrecedence(op.top())){
                        string oper = op.top();
                        op.pop();
                        int v2 = value.top();
                        value.pop();
                        int v1 = value.top();
                        value.pop();
                        int ans = applyop(v1,v2,oper);
                        value.push(ans);
                        
                    }
                    op.push(*it);
                    cout<<op.top();
                }
            }
            else if(*it=="("){
                op.push(*it);
            }
            else if(*it == ")"){
                while(!op.empty() && op.top() != "("){
                    string cur_op = op.top();
                    op.pop();
                    int v2 = value.top();
                    value.pop();
                    int v1 = value.top();
                    value.pop();
                    int ans = applyop(v1,v2,cur_op);
                    value.push(ans);
                }
                if(!op.empty())
                  op.pop();
            }
            else{
                value.push(atoi((*it).c_str()));
            }
            
        
        }
        int ans=0;
        while(!op.empty()){
            string cur_op = op.top();
            op.pop();
            int v2 = value.top();
            value.pop();
            int v1 = value.top();
            value.pop();
            ans = applyop(v1,v2,cur_op);
            value.push(ans);
        }
        
        if(!value.empty())
           ans = value.top();
        return ans;
        // write your code here
    }

};