#include<iostream>

using namespace std;
class stack{
    int max_stack;
    char arr[20];
    int top;
    public:
    stack(){
        max_stack = 20;
        top = -1;
    }
    void push(char ele);
    int pop();
    void isPalindrome(char str);
};

void stack::push(const char ele){
    if(top==max_stack)
        cout<<"Stack is full";
    else{
        top++;
        arr[top] = ele;
    }

}

int stack::pop(){
    if(top==-1)
        cout<<"Stack is empty";
    else{
        int ele = arr[top];
        top--;
        return ele;
    }
    return -1;
}

string infixPostfix(string Q, string P){
    stack s;
    s.push('(');
    P[Q.size() + 1] = ')';

    for(int i=0; i<Q.size(); ++i){
        char e = Q[i];
        if ((e >='a' && e<='z') || (e>='A' && e<='Z') || (e<=0 && e>=9) ){
            P[i] = e;
        }
        if(e=='(')
            s.push(e);
        
       
    

    
        m,ml

       
    }
     
}

int main(){
    string P = "";
    stack s;
}