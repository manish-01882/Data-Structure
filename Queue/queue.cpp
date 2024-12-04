#include <iostream>
using namespace std;

class CircularQueue {
    char elements[20]; // Array to store elements
    int frontIndex, rearIndex; // Index of the front and rear elements
    int maxSize; // Maximum size of the queue
    int currentSize; // Current number of elements in the queue

public:
    CircularQueue() {
        frontIndex = -1;
        rearIndex = -1;
        maxSize = 20;
        currentSize = 0;
    }

    void enqueue(char element) {
        if ((rearIndex + 1) % maxSize == frontIndex) {
            throw overflow_error("Overflow: Queue is full");
        }

        if (frontIndex == -1) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % maxSize;
        }
        elements[rearIndex] = element;
        currentSize++;
    }

    char dequeue() {
        if (frontIndex == -1) {
            throw underflow_error("Underflow: Queue is empty");
        }
        char element = elements[frontIndex];
        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % maxSize;
        }
        currentSize--;
        return element;
    }

    void display() {
        if (frontIndex == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        int index = frontIndex;
        while (index != rearIndex) {
            cout << elements[index] << " ";
            index = (index + 1) % maxSize;
        }
        cout << elements[rearIndex] << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice;

    cout << "1. Insert an element\n";
    cout << "2. Delete an element\n";
    cout << "3. Display queue\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    char element;
                    cout << "Enter an element: ";
                    cin >> element;
                    queue.enqueue(element);
                    cout << "Element inserted into the queue." << endl;
                    break;
                }
                case 2: {
                    char element = queue.dequeue();
                    cout << "Deleted element: " << element << endl;
                    break;
                }
                case 3: {
                    queue.display();
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
