#include <iostream>

using namespace std;

class Node
{
public:
    Node* right;
    Node* left;
    int data;
    Node(int item)
    {
        this->right=NULL;
        this->left=NULL;
        this->data=item;
    }
};

class BinarySearchTree
{
private:
    Node* root;
public:
    BinarySearchTree()
    {
        this->root=NULL;
    }

    Node* InsertRec(Node* node,int newitem)
    {
        if(node==NULL)
        {
            return new Node(newitem);
        }
        if(newitem < node->data)
        {
             node->left=InsertRec(node->left,newitem);
        }
        else if(newitem > node->data)
        {
            node->right=InsertRec(node->right,newitem);
        }
        return node;
    }

    void Insert(int newitem)
    {
        root=InsertRec(root,newitem);
    }
    void PrintInOrderRec(Node *node)
    {
        if(node!=NULL)
        {
            PrintInOrderRec(node->left);
            cout << node->data << " ";
            PrintInOrderRec(node->right);
        }
    }
    void PrintInOrder()
    {
         PrintInOrderRec(root);
        cout <<endl<<endl;
    }


    void PrintPostOrderRec(Node *node)
    {
        if(node!=NULL)
        {
            PrintPostOrderRec(node->left);
            PrintPostOrderRec(node->right);
            cout << node->data << " ";
        }
    }
    void PrintPostOrder()
    {
        PrintPostOrderRec(root);
        cout << endl<<endl;
    }

    void PrintPreOrderRec(Node *node)
    {
        if(node!=NULL)
        {
            cout << node->data << " ";
            PrintPreOrderRec(node->left);
            PrintPreOrderRec(node->right);
        }
    }
    void PrintPreOrder()
    {
        PrintPreOrderRec(root);
        cout <<endl<<endl;
    }

};

int main()
{
    BinarySearchTree ob;
    int n;
    cout<<"Enter the count of Element in Tree : ";
    cin>>n;
    cout<<"\nEnter the Element in Tree : ";
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        ob.Insert(num);
    }
    cout<<endl;

    cout << "In-Order Traversal: ";
    ob.PrintInOrder();
    cout << "pre-Order Traversal: ";
    ob.PrintPreOrder();
    cout << "post-Order Traversal: ";
    ob.PrintPostOrder();

    return 0;
}
