#include<iostream>
#include<cstring>
using namespace std;

class stack{
    int b[20];
public:
    int top;
    int max;
    stack(){
        top=-1;
        max=20;
    }
    void push(int ele){
        if(top==(max-1)){
            return;
        }
        top++;
        b[top]=ele;
    }
    int pop(){
        if(top==-1){
            return 0 ;
        } 
        int w=b[top];
        top--;
        return w;
    }
};

int operate(int a,int b,char e){
    if(e == '+'){
        return (a+b);
    }
    else if(e=='-')
        return (b-a);  
    else if(e== '*')
        return (a*b);
    else if(e== '/')
        return (b/a);
    else if(e=='^')
        return b^a;
    else if(e=='%')
        return b%a;
    else
        return -1;
}

void evaluate(string a){
    stack st;
    int  p[20];
    for(int i=0;i<a.length();i++){ 
        char e = a[i];
        if(e>='0' && e<='9'){
            int num = e-'0';
            st.push(num);
        }
        else if(e=='+' || e=='-' || e=='*' || e=='/' || e=='^' || e=='%'){
            int a=st.pop();
            int b = st.pop();
            int c = operate(a,b,e);
            st.push(c);
        }
    }
    cout << "Result: " << st.pop() << endl;
}

int main(){
    // cout<<"Name : Manish Choudhary\nURN : 2203495\n\n";
    // cout<<"Name: Karamveer Kaur\nURN: 2203479\n\n";
    // cout<<"Name: Jaspreet Singh\nURN: 2203473\n\n";
    cout<<"Name: Karan Kashyap\nURN: 2203481\n\n";
    string a="562+*84/-";
    evaluate(a);
    return 0;
}
