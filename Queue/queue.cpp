#include <iostream>
using namespace std;

class Queue {
    char a[20];
    int f, r;
    int max;
    int c;

public:
    Queue() {
        f = -1;
        r = -1;
        max = 20;
        c = 0;
    }

    void enqueue(char ele) {
        if ((r + 1) % max == f) {
            throw overflow_error("Overflow");
        }

        if (f == -1) {
            f = 0;
            r = 0;
        } else {
            r = (r + 1) % max;
        }
        a[r] = ele;
        c++;
    }

    char dequeue() {
        if (f == -1) {
            throw underflow_error("Underflow");
        }
        char ele = a[f];
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % max;
        }
        c--;
        return ele;
    }

    void display() {
        if (f == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        int i = f;
        while (i != r) {
            cout << a[i] << " ";
            i = (i + 1) % max;
        }
        cout << a[r] << endl;
    }
};

int main() {
    Queue obj;
    int ch;

    // cout << "Name: Karan Kashyap\nURN: 2203481\n\n";
    // cout<<"Name : Manish Choudhary\nURN : 2203495\n\n";
    cout<<"Name: Karamveer Kaur\nURN: 2203479\n\n";
    // cout<<"Name: Jaspreet Singh\nURN: 2203473\n\n";
    cout << "1. Insert an element.\n2. Delete an element\n3. Display queue\n4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> ch;

        try {
            switch (ch) {
                case 1: {
                    char ele;
                    cout << "Enter an element: ";
                    cin >> ele;
                    obj.enqueue(ele);
                    cout << "Element is inserted in the queue." << endl;
                    break;
                }
                case 2: {
                    char ele = obj.dequeue();
                    cout << "Deleted element: " << ele << endl;
                    break;
                }
                case 3: {
                    obj.display();
                    break;
                }
                case 4: {
                    cout << "Exiting program." << endl;
                    return 0;
                }
                default: {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        } catch (const overflow_error& e) {
            cout << "Error: " << e.what() << endl;
        } catch (const underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
