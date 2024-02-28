/**********************************************************
Design, Develop and Implement a Program for the following
operationson Singly Linked List (SLL) with header
nodes a. Find the sum of two polynomials POLY1(x,y,z) and
POLY2(x,y,z) and store the result in POLYSUM(x,y,z)
***********************************************************/

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};

class poly{
    int x,y,z;
    node *start;
    public:
    poly(){
        x=0;y=0;z=0;
        start = NULL;
    }
    void insertAtEnd(int ele);
    void display();
    
}

