#include <iostream>
using namespace std;
class BinarySearchTree
{
private:
    struct node
    {
        int element;
        struct node *linkToLeft;
        struct node *linkToRight;
    };
    void optionMenu(struct node *);
    void insertElement(struct node **);
    struct node *insert(struct node *, int);
    void inOrderTraversal(struct node *);
    void preOrderTraversal(struct node *);
    void postOrderTraversal(struct node *);
    bool searchElement(struct node *, int);

public:
    void initialiseList();
};
inline void BinarySearchTree ::initialiseList()
{
    struct node *root;
    root = NULL;
    optionMenu(root);
}
inline void BinarySearchTree ::optionMenu(struct node *root)
{
    int choice;
    cout << "\n\nPress 1 to insert element into tree" << endl;
    cout << "Press 2 to traverse the tree in In-order" << endl;
    cout << "Press 3 to traverse the tree in Pre-order" << endl;
    cout << "Press 4 to traverse the tree in Post-order" << endl;
    cout << "Press 5 to search an element from the tree" << endl;
    cout << "Press 0 to Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insertElement(&root);
        optionMenu(root);
        break;
    case 2:
        inOrderTraversal(root);
        optionMenu(root);
        break;
    case 3:
        preOrderTraversal(root);
        optionMenu(root);
        break;
    case 4:
        postOrderTraversal(root);
        optionMenu(root);
        break;
    case 5:
        int element;
        cout << "Enter the element you want to search from tree: ";
        cin >> element;
        if (searchElement(root, element))
        {
            cout << "Element exists" << endl;
        }
        else
        {
        cout << "Element doesn't exists" << endl;
        }
    }
    optionMenu(root);
    // break;
    // break;
    cout << "Invalid choice!" << endl
         << endl;
    optionMenu(root);
}
inline void BinarySearchTree ::insertElement(struct node **root)
{
    int choice;
    struct node *pointer;
    pointer = *root;
    cout << "\nPress any positive integer as element of tree" << endl;
    cout << "Press -1 to exit the insertion loop" << endl;
    cout << "Enter the data: ";
    cin >> choice;
    while (choice != -1)
    {
        if (pointer == NULL)
        {
            pointer = insert(pointer, choice);
        }
        else
        {
            insert(pointer, choice);
        }
        cin >> choice;
    }
    *root = pointer;
}
inline struct BinarySearchTree ::node *BinarySearchTree ::insert(struct node *pointer, int element)
{
    if (pointer == NULL)
    {
        struct node *newNode;
        newNode = new node();
        newNode->element = element;
        newNode->linkToLeft = NULL;
        newNode->linkToRight = NULL;
        return newNode;
    }
    if (element < pointer->element)
    {
        pointer->linkToLeft = insert(pointer->linkToLeft, element);
    }
    else if (element > pointer->element)
    {
        pointer->linkToRight = insert(pointer->linkToRight, element);
    }
    return pointer;
}
inline void BinarySearchTree ::inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->linkToLeft);
        cout << root->element << "\t";
        inOrderTraversal(root->linkToRight);
    }
}
inline void BinarySearchTree ::preOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        cout << root->element << "\t";
        preOrderTraversal(root->linkToLeft);
        preOrderTraversal(root->linkToRight);
    }
}
inline void BinarySearchTree ::postOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->linkToLeft);
        postOrderTraversal(root->linkToRight);
        cout << root->element << "\t";
    }
}
inline bool BinarySearchTree ::searchElement(struct node *root, int element)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->element == element)
    {
        return true;
    }
    if (searchElement(root->linkToLeft, element))
    {
        return true;
    }
    return (searchElement(root->linkToRight, element));
}
int main()
{
    BinarySearchTree bst;
    bst.initialiseList();
    return 0;
}