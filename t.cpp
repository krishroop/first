#include<bits/stdc++.h>
using namespace std;
string str= "a?b?c:d:e";
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node *convertExpression(string str,int i)
{
    if(i>=str.size())
        return NULL;
        
    Node *t=new Node;
    t->data=str[i++];
    
    if(i<str.size() && str[i++]=='?')
        t->left=convertExpression(str,i);
        
    if(i<str.size() && str[i++]==':')
        t->left=convertExpression(str,i);
}

void preorder(Node *t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}
int main()
{
    Node *root=NULL;
    root=convertExpression(str,0);
    preorder(root);

    return 0;
}