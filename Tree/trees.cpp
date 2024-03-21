#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node *buildtree(node *root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void treversal(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node *temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void preorder(node *root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Komalpreet Kaur\n";
    cout << "URN: 2203492 \n";
    cout << "Output is:\n";

    node *root = NULL;
    root = buildtree(root);
    cout << "The level order traversal is: " << endl;
    treversal(root);
    cout << "The preorder traversal is: " << endl;
    preorder(root);
    cout << "\nThe inorder traversal is: " << endl;
    inorder(root);
    cout << endl;
    return 0;
}
