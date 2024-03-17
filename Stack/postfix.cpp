//Exp 5
#include<iostream>
#include<cstring>
using namespace std;

int checkPrecedence(char op);
int bracket(char e);
void checkbracket(string m);

class stack{
    char b[20];
public:
    int top;
    int max;
    stack(){
        top=-1;
        max=20;
    }
    void push(char ele){
        if(top==(max-1)){
            cout<<"overflow";
            return;
        }
        top++;
        b[top]=ele;
    }
    char pop(){
        char w=b[top];
        top--;
        return w;
    }
};

void infixToPostfix(string m){
    stack s;
    m = m + ')';
    char p[20];
    int c=0;
    s.push('(');
    for(int i=0; i<m.length(); i++){ 
        char e = m[i];
        if((e>='a'&& e<='z') ||( e>='A' && e<='Z')){
            p[c]=e;
            c++;

        }
        else if(e=='(' || e=='{' || e=='['){
            s.push(e);
            
        }
        else if(e=='^' || e=='%' || e=='*' || e=='/' || e=='+' || e=='-'){
            int p1 = checkPrecedence(e);
            int greaterPrecedence = 1;
                char op = s.pop();
                int p2 = checkPrecedence(op);
                if(p2>=p1){ 
                    p[c]= op;
                    c++;
                }
                else{
                    s.push(op);
                } 
            s.push(e);
            
        }
        else if(e==')' || e=='}' || e==']'){
    while(1){
        char n = s.pop();
        if(n == '(' || n == '{' || n == '['){
            break;
        }

        else{
            p[c] = n;
            c++;
        }
    }
    }}
    
    cout<< "Postfix Expression: " << p << endl;
}

int checkPrecedence(char op){
    if(op =='^'){
        return 5;
}
    else{
        if(op == '/' || op == '%'){
            return 4;
        }
        else if(op=='*'){
            return 3;
        }
        else if(op=='+')
            return 2;
        else
            return 1;
    }
}

void checkbracket(string m){
	stack s;
	int c=0;
	for(int i=0;i<m.length();i++){
		char e=m[i];
		if(e=='(' || e=='{' || e=='['){
			s.push(e);
		}
		if(e==')' || e=='}' || e==']'){
			char op= s.pop();
			int ch = bracket(e);
			if(e==')' && ch == 1)
			    c++;
			else if(e=='}' && ch == 2){
				c++;
			}
			else if(e==']' && ch == 3){
				c++;
			}
			else{
			    cout<<"unmatched\n";
			    return;
			}
		}
	}
	if(s.top==-1){
		infixToPostfix(m);
	}
	else{
		cout<<"unmatched\n";
	}
}

int bracket(char m){
	if(m==')')
		return 1;
	else if(m=='}')
	    return 2;
	else if(m==']')
	    return 3;
	else 
	    return -1;
}

int main(){
    string s;//="{(a+b)/g}*f";
    //s=s+')';
    //infixToPostfix(s);
    //checkbracket(s);
    cout<<"Name : Manish Choudhary\nURN : 2203497\n\n";
    string y="y";
    while(y=="yes" || y=="y"){
    	cout<<"Enter an Expression : ";
        cin>>s;
        checkbracket(s);
    	//string y;
    	cout<<"do you want to check the expression?\n ";
    	cin>>y;
	}
    return 0;
}