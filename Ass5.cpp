#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    bool lbit, rbit;
    Node *left=NULL;
    Node *right=NULL;
};

Node *createNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->lbit = 0;
    temp->rbit = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertNode(Node *root, int data)
{
    Node *node = createNode(data);
    if (node->data < root->data)
    {
        if (root->lbit == 0)
        {
            node->left = root->left;
            node->right = root;
            root->left = node;
            root->lbit = 1;
        }
        else
        {
            insertNode(root->left, data);
        }
    }
    else
    {
        if (root->rbit == 0)
        {
            node->right = root->right;
            node->left = root;
            root->right = node;
            root->rbit = 1;
        }
        else
        {
            insertNode(root->right, data);
        }
    }
}


void printTBT(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->lbit == 1)
    {
        cout << "(";
        printTBT(root->left);
        cout << ")";
    }

    cout << "<-"<< root->data <<"->";

    if (root->rbit == 1)
    {
        cout << "(";
        printTBT(root->right);
        cout << ")";
    }
}


int main()
{
    // creating root
    Node *root = createNode(5);
    Node *dummy = createNode(9999);
    dummy->right = dummy;
    dummy->rbit = true;
    dummy->left = root;
    dummy->lbit = true;
    root->left = dummy;
    root->right = dummy;

    // node insertion
    insertNode(root,12);
    insertNode(root,3);
    insertNode(root,16);
    


    if (root != NULL) {
        printTBT(root);
    }

    return 0;
}