#include <iostream>
#include <cstring>

using namespace std;

class stack {
    int max_stack;
    char arr[20];
    int top;

public:
    stack() {
        max_stack = 20;
        top = -1;
    }

    void push(char ele);
    int pop();
    void display();
};

void stack::push(const char ele) {
    if (top == max_stack)
        cout << "Stack is full";
    else {
        top++;
        arr[top] = ele;
    }
}

int stack::pop() {
    if (top == -1)
        cout << "Stack is empty";
    else {
        char ele = arr[top];
        top--;
        return ele;
    }
    return -1;
}

void isPalindrome(char str[]) {
    stack s;
    int i = 0;
    while (i < strlen(str)) {
        s.push(str[i]);
        i++;
    }
    int j = 0, h = 0;
    while (j < i) {
        if (s.pop() == str[j]) {
            h++;
            j++;
        } else {
            h = 0;
            break;
        }
    }
    if (h > 0) {
        cout << "Yes, it's a palindrome" << endl;
    } else {
        cout << "No, it's not a palindrome" << endl;
    }
}

void stack::display() {
    int i = 0;
    while (i <= top) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}

int main() {
    stack s;
    cout<<"Name: Karamveer Kaur\nURN: 2203479\n\n";
    cout << "1. Push an element" << endl;
    cout << "2. Pop an element" << endl;
    cout << "3. Check palindrome" << endl;
    cout << "4. Display the stack" << endl;
    cout << "5. Exit" << endl;

    int c;
    while (1) {
        cout << "Enter your choice: ";
        cin >> c;
        switch (c) {
            case 1: {
                char ele;
                cout << "Enter an element: ";
                cin >> ele;
                s.push(ele);
                cout << ele << " is pushed in stack" << endl << endl;
                break;
            }
            case 2: {
                int t = s.pop();
                if (t != -1)
                    cout << "Popped element: " << static_cast<char>(t) << endl;
                break;
            }
            case 3: {
                char g[20];
                cout << "Enter string: ";
                cin >> g;
                isPalindrome(g);
                break;
            }
            case 4: {
                cout << "Stack contents: ";
                s.display();
                cout<<endl;
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
