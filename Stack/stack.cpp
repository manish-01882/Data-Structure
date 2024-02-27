#include<iostream>
#include <cstring>

using namespace std;

class stack{
    int max_stack;
    int arr[20];
    int top;
    public:
    stack(){
        max_stack = 20;
        top = -1;
    }
    void push(char ele);
    int pop();
    //void isPalindrome(char str[]);
    void display();
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
void isPalindrome(char str[]){
    stack s;
    int i = 0;
    while(i<strlen(str)){
        s.push(str[i]);
        i++;
    }
    int j=0, h=0;
    while(j>i){
        if(s.pop() == str[j]){
            h++;
            j++;
        }
        else{
            h=0;
            break;
        }
    }
    if(h>0){
        cout << "Yes, its a palindrome"<<endl;
    }
    else{
        cout<<"No, its not a palindrome"<<endl;
    }

}

void stack::display(){
    int i=0;
    while(i<top){
        pop();
        cout<<arr[top];
    }
}

int main(){
    stack s;
    cout<<"1. Push an element"<<endl;
    cout<<"2. Pop an element"<<endl;
    cout<<"3. Check palindrome"<<endl;
    cout<<"4. Display the stack"<<endl;
    cout<<"5. exit"<<endl;

    int c;
    while(1){
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c){
            case 1:{
                char  ele;
                cout<<"Enter an element: ";
                cin >> ele;
                s.push(ele);
                cout<<ele<<" is pushed in stack\n\n";
                break;
            }
            case 2:{
                char t = s.pop();
                cout<<"Pop element: "<<t;
                break;
            }
            case 3:{
                char g[20];
                cout<<"Enter string: ";
                cin>>g;
                isPalindrome(g);
                break;
            }
            case 4:{
                s.display();
                break;
            }
            case 5:{
                exit(0);
                break;
            }
            default:{
                cout<<"Invalid choice";
                break;
            }

        }
    }
}