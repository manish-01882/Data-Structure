/**********************************************************
Design, Develop and Implement a Program for the following
operationson Singly Linked List (SLL) with header
nodes a. Find the sum of two polynomials POLY1(x,y,z) and
POLY2(x,y,z) and store the result in POLYSUM(x,y,z)
***********************************************************/

#include<iostream>
#include <cstring>


using namespace std;

struct node{
    int data;
    struct node* next;
};

class LinkedList{
    int x,y,z;
    struct node *start;
    public:
        LinkedList(){ 
            x=0;
            y=0;
            z=0;
            start = NULL;
            }
        
        void insertAtBeg(int data);
        void insertAtEnd(int data);
        void deleteFromBeg();
        void deleteFromEnd();
        void display();
        void get_data();
        void add(LinkedList l1, LinkedList l2);
        void result();

};

void LinkedList::insertAtBeg(int data ){
    struct node *p = new node;
    p-> data = data;
    p-> next = start;
    start = p;
    

}
void LinkedList::insertAtEnd(int data){
    struct node *p = new node;
    struct node *temp;
    temp = start;
    p->data = data;
    if(temp == NULL)
        start = p;
    else{
        while(temp->next != NULL){
            temp = temp->next;
        } 
        temp->next = p;
    }

}

void LinkedList::deleteFromBeg(){
    struct node *temp,*p;
    temp = start;
    start = temp->next;

    delete temp;
}

void LinkedList::deleteFromEnd(){
    struct node *temp,*prev;
    temp = start;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
        if(temp->next == NULL){
            prev->next = NULL;
            delete temp;
            break;
        }
            
    }
}

void LinkedList::display(){
    struct node *temp = start;

    while(temp!=NULL){
        cout << temp->data;
        temp = temp-> next;
        cout << endl;
    }
    cout << endl;
}

void LinkedList::get_data(){
    cout<<"Enter x y z: ";
    cin >> x >> y >>z;
    insertAtEnd(x);
    insertAtEnd(y);
    insertAtEnd(z);
}
void LinkedList::add(LinkedList l1, LinkedList l2){
    this->x = l1.x + l2.x;
    this->y = l1.y + l2.y;
    this->z = l1.z + l2.z;
    insertAtEnd(x);
    insertAtEnd(y);
    insertAtEnd(z);

}

void LinkedList::result()
{
node *temp = start;
int a = temp->data;
temp=temp->next;
int b = temp->data;
temp=temp->next;
int c = temp->data;
cout<<a<<"x + "<<b<<"y + "<<c<<"z"<<endl;
}

int main(){
    LinkedList L1, L2, L3;
    L1.get_data();
    L2.get_data();
    L3.add(L1,L2);
    L3.result();
}