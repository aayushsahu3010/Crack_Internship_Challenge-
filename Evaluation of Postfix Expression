int operate(int a,int b,char ch){
        if(ch=='+'){
            return a+b;
        }
        else if(ch=='-'){
            return a-b;
        }
        else if(ch=='*'){
            return a*b;
        }
        else if(ch=='/'){
            return a/b;
        }
        else{
            return 0;
        }
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        for(char ch:S){
            if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                int res=operate(a,b,ch);
                st.push(res);
            }
            else{
                
                st.push(ch-48);
            }
        }
        return st.top();
    }
