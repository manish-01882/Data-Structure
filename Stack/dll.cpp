#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    struct node *prev;
    int ssn;
    int sal;
    char name[15];
    char dept[5];
    char designation[25];
    long long int ph_no;
    struct node *next;
};

class DLL
{
    struct node *head;
    struct node *tail;

public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeg(int s,const char n[], const char d[], const char de[], int sl, long long int ph)
    {
        struct node *temp, *p;
        p = new struct node;
        p->ssn = s;
        p->sal = sl;
        p->ph_no = ph;
        strcpy(p->name, n);
        strcpy(p->dept, d);
        strcpy(p->designation, de);
        p->prev = NULL;
        p->next = head;
        head = p;
    }

    void insertAtEnd(int s, const char n[], const char d[], const char de[], int sl, long long int ph)
    {
        struct node *temp, *p;
        p = new struct node;
        temp = head;
        p->ssn = s;
        p->sal = sl;
        p->ph_no = ph;
        strcpy(p->name, n);
        strcpy(p->dept, d);
        strcpy(p->designation, de);
        
        if (head != NULL)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            p->prev = temp;
            temp->next = p;
        }
        else
        {
            head = p;
        }
    }

    void deleteAtBeg()
    {
        struct node *temp;
        temp = head;
        temp = temp->next;
        temp->prev = NULL;
        head = temp;
    }

    void deleteAtEnd()
{
    struct node *temp, *p;
    temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
    }
    else
    {
        p = temp->next;
        while (p->next != NULL)
        {
            temp = p;
            p = p->next;
        }
        temp->next = NULL;
        delete p;
    }
}


    void countthenode()
    {
        struct node *temp;
        temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "Total number of nodes:" << count;
    }

    void display(){
        struct node*temp;
        temp=head;
        while(temp!=NULL){
            cout<<"SSN:"<<temp->ssn;
            cout<<"Name:"<<temp->name;
            cout<<"Dept:"<<temp->name;
            cout<<"Designation:"<<temp->designation;
            cout<<"Salary:"<<temp->sal;
            cout<<"Phone no.:"<<temp->ph_no;
            temp=temp->next;
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    DLL obj;
    cout<<"Jaspreet Singh \n URN-2203473\nOutput:\n\n";
    
    obj.insertAtBeg(1,"jaspreet","CSE","Engineer",60000,9830274978);
    obj.insertAtEnd(2,"karan","CSE","Engineer",70000,9875065358);
    obj.display();
    cout<<"Delete at beginning:\n";
    obj.deleteAtBeg();
    obj.display();
    cout<<endl;
    cout<<"Delete at end";
    obj.deleteAtEnd();
    cout<<endl;
    obj.display();
    return 0;
}