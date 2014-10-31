class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;int i=1;
        sc.push(s[0]);
        while(i<s.size()){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                sc.push(s[i]);
            }else{
                if(s[i]==')'){
                    if(!sc.empty()&&sc.top()=='('){
                        sc.pop();
                    }else   return false;
                }else if(s[i]==']'){
                    if(!sc.empty()&&sc.top()=='['){
                        sc.pop();
                    }else   return false;
                }else if(s[i]=='}'){
                    if(!sc.empty()&&sc.top()=='{'){
                        sc.pop();
                    }else   return false;
                }
            }
            ++i;
        }
        
        if(sc.empty()) return true;
        else return false;
    }
};