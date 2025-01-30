#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node():left(nullptr),right(nullptr),data(0){}
    node(int d):data(d),left(nullptr),right(nullptr){}
};

void insert(node* &root,int val)
{
    node* p=new node(val);

    if(root==nullptr) 
    root=p;
    else 
    {
        node* temp=root;
        while(true) 
        {
            cout<<"1.For Left Insert of "<<temp->data<<endl;
            cout<<"2.For Right Insert of "<<temp->data<<endl;
            int c;
            cout<<"Enter your choice: ";
            cin>>c;

            if(c==1) 
            {
                if(temp->left==nullptr) 
                {
                    temp->left=p;
                    break;
                } 
                else
                temp=temp->left;
            } 
            else if(c==2) 
            {
                if(temp->right==nullptr) 
                {
                    temp->right=p;
                    break;
                } 
                else
                temp=temp->right;
            } 
            else
            cout<<"Invalid choice! Please choose either 1 or 2."<<endl;
        }
    }
}

void inorder(node* root) 
{
    if(root!=nullptr) 
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    node* root=nullptr;
    int n;

    cout<<"Enter the number of nodes to insert: ";
    cin>>n;

    for(int i=0;i<n;i++) 
    {
        int val;
        cout<<"Enter value for node "<<i+1<<": ";
        cin>>val;
        insert(root,val);
    }

    cout<<"Inorder traversal of the tree: ";
    inorder(root);
    cout<<endl;
}
