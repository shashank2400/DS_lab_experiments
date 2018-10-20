#include <iostream>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
};
struct node *root=NULL;
class tree
{
public:

    node *createnode(int);
    node *insert_node(node *,int);
    int inorder(node *);
    int Search(node *,int);
    int printPostorder(node *);
    int printPreorder(node *);
};
int tree::Search(node *root,int num)
{
    if(root!=NULL)
    {
    if(num==root->key)
    {
        return(1);
    }
    else if(num>=root->key)
        return Search(root->right,num);
    else
        return Search(root->left,num);
    }
    else
        return 0;

}
int tree::inorder(node *root)
{
    if(root==NULL)
        return 0;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
node *tree::createnode(int x)
{
    node *temp=new node;
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;

}
node *tree::insert_node(node *root,int data)
{
    int ele;
    node *p;
    if(root==NULL)
    {
        root=createnode(data);
        return root;
    }
    else if(data<=root->key)
        root->left=insert_node(root->left,data);
    else
    {
    root->right=insert_node(root->right,data);
    }
}
int tree::printPreorder(node *root)
{
    if (root == NULL)
        return 0;


    cout << root->key << " ";

    printPreorder(root->left);

    printPreorder(root->right);
}
int tree::printPostorder( node *root)
{
    if (root == NULL)
        return 0;

    printPostorder(root->left);

    printPostorder(root->right);
    cout << root->key << " ";
}
int main()
{
    int e;
    int n;
    cin>>n;
    tree t;
    node *p;
     cin>>e;
        root=t.insert_node(root,e);
    for(int i=0;i<n-1;i++)
    {
        cin>>e;
        t.insert_node(root,e);
    }
    t.inorder(root);cout<<endl;
    t.printPreorder(root);cout<<endl;
    t.printPostorder(root);
    return 0;
}
