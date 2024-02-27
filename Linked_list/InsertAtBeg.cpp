#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void insertAtBeg(struct node **start, int element){
    struct node *p;
    p = new node;
    p->data=element;
    p->next=(*start);
    (*start) = p;
}

void display(struct node *node){
	while(node != NULL){
        if(node->next == NULL){
            cout << node->data <<endl;
            break;
        }
        else
		cout << node -> data << "-->";
		node = node -> next;
	}
}

int main(){
   struct node *start = NULL;
   int n,ele;
   cin >> n;
   for(int i=0;i<n; ++i) {
    cin>>ele;
    insertAtBeg(&start, ele);
   }
    cout<<"Final Linked List:"<<endl;
    display(start);
    cout<<endl;

}
