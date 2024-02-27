/*********************************************************
Design, Develop and Implement a menu driven Program for the 
following operations on Doubly Linked List (DLL) of 
Employee Data with the fields: SSN, Name, Dept, Designation, 
Sal, PhNo a. Create a DLL of N Employees Data by using end 
insertion.
b. Display the status of DLL and count the number of nodes in 
it 
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended 
Queue
f. Exit
**********************************************************/


#include<iostream>
#include <string.h>

using namespace std;

struct node{
    struct node* prev;
    int SSN;
    char name[20];
    char dept[10];
    char designation[10];
    float salary;
    char phone_no[11];
    struct node* next;
};

class double_linked_list{
    struct node* head,* tail;
    public:
    double_linked_list(){
        head = NULL;
        tail = NULL;
    }

    void insertAtBeg(int SSN,const char* name,const char* dept, const char* designation, float salary, const char* phone_no);
    void insertAtEnd(int SSN,const char* name,const char* dept, const char* designation, float salary, const char* phone_no);
    void deleteFromBeg();
    void deleteFromEnd();
    void display();
};

void double_linked_list::insertAtBeg(int SSN,const char* name,const char* dept, const char* designation, float salary, const char* phone_no){
    struct node *p = new node;
    p->SSN = SSN;
    strcpy(p->name, name);
    strcpy(p->dept, dept);
    strcpy(p->designation,designation);
    p->salary = salary;
    strcpy(p->phone_no, phone_no);

    p->prev = NULL;
    p-> next = head;
    head = p;

    if(tail == NULL){
        tail = p;
        tail->prev = head->next;
        tail->next = head->prev;
    }
}

void double_linked_list::insertAtEnd(int SSN,const char* name,const char* dept, const char* designation, float salary, const char* phone_no){
    struct node *p = new node;
    struct node *temp,*temp2;
    temp = head;

    p->SSN = SSN;
    strcpy(p->name, name);
    strcpy(p->dept, dept);
    strcpy(p->designation,designation);
    p->salary = salary;
    strcpy(p->phone_no, phone_no);
    
    if(head != NULL){
        while(temp->next != NULL){
            temp = temp->next;
        } 
        p->prev = temp;
        temp->next = p;

        temp = temp->next;
        while(temp->prev != NULL){
            temp2->next = temp-> prev;
            temp2->prev = temp->next;
            temp = temp->prev;
        }
        tail = temp2;
    } else {
        head = p;
    }

    
    

    // if(tail != NULL){
    //     while (temp2->next != NULL){
    //         temp2 = temp-> next;
    //     }
    //     temp2->prev = temp2;
    //     temp2->next = p;
    // }

}

void double_linked_list::deleteFromBeg(){
    struct node *temp;
    temp = head;
    temp = temp->next;
    temp->prev = NULL;
    head = temp;
}

void double_linked_list::display(){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        cout << temp->SSN <<' ';
        cout << temp->name << ' ';
        cout << temp->dept << ' ';
        cout << temp->designation<< ' ';
        cout<< temp->salary << ' ';
        cout << temp->phone_no << ' ';

        temp = temp-> next;
        cout << endl;
    }
    cout << endl;
}

int main(){
    double_linked_list n;
    n.insertAtBeg(255,"manish","cse", "student", 10, "7814086432");
    n.insertAtEnd(500,"jaspreet", "CSE", "std", 500, "22424");
    n.deleteFromBeg();
    n.display();
}