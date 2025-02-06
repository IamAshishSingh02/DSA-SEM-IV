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
            cout<<"\n1.For Left Insert of "<<temp->data<<endl;
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

void pre_rec(node* root)
{
    if(root!=nullptr)
    {
        cout<<root->data<<" ";
        pre_rec(root->left);
        pre_rec(root->right);
    }
}

void in_rec(node* root) 
{
    if(root!=nullptr) 
    {
        in_rec(root->left);
        cout<<root->data<<" ";
        in_rec(root->right);
    }
}

void post_rec(node* root)
{
    if(root!=nullptr)
    {
        post_rec(root->left);
        post_rec(root->right);
        cout<<root->data<<" ";
    }
}

void lvlorder(node* root)
{

}

int main()
{
    node* root=nullptr;
    int n;

    do
    {
        cout<<"1.Create Binary Tree";
        cout<<"2.Preorder Recursive";
        cout<<"3.Preorder Iterative";
        cout<<"4.Inorder Recursive";
        cout<<"5.Inorder Iterative";
        cout<<"6.Postorder Recursive";
        cout<<"7.Postorder Iterative";
        cout<<"8.Level Order";
        cout<<"9.Clone";
        cout<<"10.Check Equal Trees";
        cout<<"11.Mirror Image";
        cout<<"12.Create BST";
        cout<<"13.Delete node from BST";
        cout<<"14.BST from Preorder";
        cout<<"15.BST from Inorder";
        cout<<"16.Height";


    }

    cout<<"Enter the number of nodes to insert: ";
    cin>>n;

    for(int i=0;i<n;i++) 
    {
        int val;
        cout<<"\nEnter value for node "<<i+1<<": ";
        cin>>val;
        insert(root,val);
    }

    cout<<"\nInorder traversal of the tree: ";
    in_rec(root);
    cout<<endl;
}
