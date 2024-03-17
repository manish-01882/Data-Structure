#include<iostream>
using namespace std;

class tree {
public:
    int data;
    tree *left, *right;
    tree(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinarySearchTree {
public:
    tree *root;
    BinarySearchTree() {
        root = NULL;
    }
    
    void Insert(int value) {
        tree *temp = new tree(value);
        if (root == NULL) {
            root = temp;
            return;
        }
        tree *current = root;
        tree *parent = NULL;
        
        while (current != NULL) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (value < parent->data) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    }
   void display() {
        tree *current = root;
        while (current != NULL) {
            if (current->left == NULL) {
                cout << current->data << " ";
                current = current->right;
            }
            else {
                tree *pre = current->left;
                while (pre->right != NULL && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }
                else {
                    pre->right = NULL;
                    cout << current->data << " ";
                    current = current->right;
                }
            }
        }
        cout << endl;
    }
    void search(int ele)
    {
    	tree *c=root;
    	while(c!=NULL)
    	{
    		if(ele==c->data)
    		{
    			cout<<ele<<" is found in tree"<<endl;
			}
			if(ele<c->data)
			{
				c=c->left;
			}
			else
			{
				c=c->right;
			}
		}
    	cout<<"element not found"<<endl;
	}

};

int main() {
    BinarySearchTree n;
    n.Insert(22);
    n.Insert(15);
    n.Insert(48);
    n.Insert(2);
    n.display();
    n.search(7);
    return 0;
}