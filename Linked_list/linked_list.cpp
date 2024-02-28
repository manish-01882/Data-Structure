#include<iostream>
#include <cstring>


using namespace std;

struct node{
    int URN;
    char name[20];
    char branch[5];
    int sem;
    char phone_no[11];
    struct node* next;
};

class LinkedList{
    struct node *start;
    public:
        LinkedList(){ start = NULL;}
        
        void insertAtBeg(int URN,const char* name,const char* branch, int sem, const char* phone_no);
        void insertAtEnd(int URN,const char* name,const char* branch, int sem, const char* phone_no);

        void deleteFromBeg();
        void deleteFromEnd();

        void display();

};

void LinkedList::insertAtBeg(int u,const char* n,const char* b, int s, const char* ph ){
    struct node *p = new node;
    p-> URN = u;
    strcpy(p-> name,  n);
    strcpy(p-> branch, b);
    p-> sem = s;
    strcpy(p-> phone_no , ph);
    p-> next = start;
    start = p;
    

}

void LinkedList::insertAtEnd(int urn,const char* names,const char* branch, int semester, const char* phone){
    struct node *p = new node;
    struct node *temp;
    temp = start;
    p->URN = urn;
    strcpy(p->name, names);
    strcpy(p->branch, branch);
    p-> sem = semester;
    strcpy(p-> phone_no , phone);
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
    struct node *temp;
    temp = start;
    while(temp!=NULL){
        cout << temp->URN <<' ';
        cout << temp->name << ' ';
        cout << temp->branch << ' ';
        cout << temp->sem << ' ';
        cout << temp->phone_no << ' ';

        temp = temp-> next;
        cout << endl;
    }
    cout << endl;
}

int main(){
    LinkedList L;
    cout<<"Name: Manish\nURN: 2203495\n";

    // cout<<"Insert At beginning\nKaran \nCSE \n4 \n51351488\n";
    // cout<<"Insert at end \nKashyap \nCSE \n4 \n9163183155";
    // cout<<"\nDelete from end\n";
    cout << "Delete from beginning";

    // L.insertAtBeg(2203479, "Jaspreet","CSE",4,"7911531335");
    // L.insertAtBeg(2203495, "Manish", "CSE", 4, "7814086432" );
    L.insertAtBeg(220383, "Karan", "CSE", 4, "51351488");
    // L.insertAtEnd(2203490, "Komal", "CSE", 4, "7648613514");
    L.insertAtEnd(2215084, "Kashyap", "CSE", 4 ,"9163183155");
    L.deleteFromEnd();
    L.deleteFromBeg();

    L.display();
}
