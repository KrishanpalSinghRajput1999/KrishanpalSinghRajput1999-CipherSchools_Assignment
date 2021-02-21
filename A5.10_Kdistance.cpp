# include<bits/stdc++.h>
# include<stdlib.h>
using namespace std;
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *newNode(int data)
{
struct node *temp = (struct node *) malloc(sizeof(struct node));
temp -> data = data;
temp -> left = NULL;
temp -> right = NULL;
return temp;
};
void print_nodes_k_Distance(node *root , int k)
{
if(root == NULL)
return;
if( k == 0 )
{
cout << root->data << ” “;
return ;
}
else
{
print_nodes_k_Distance( root->left, k – 1 ) ;
print_nodes_k_Distance( root->right, k – 1 ) ;
}
}
void insert_node(struct node *root, int n1, int n2, char lr)
{
if(root == NULL)
return;
if(root -> data == n1)
{
switch(lr)
{
case ‘l’ :root -> left = newNode(n2);
break;
case ‘r’ : root -> right = newNode(n2);
break;
}
}
else
{
insert_node(root -> left, n1, n2, lr);
insert_node(root -> right, n1, n2, lr);
}
}
void inorder(struct node *root)
{
if(root == NULL)
return;
inorder(root -> left);
cout << root -> data << ” “;
inorder(root -> right);
}
int main()
{
struct node *root = NULL;
int n;
cout << “nEnter the number of edges : “;
cin >> n;
cout << “nInput the tree : n”;
while(n–)
{
char lr; int n1,n2;
cin >> n1;cin >> n2;
cin >> lr;
if(root == NULL)
{
root = newNode(n1);
switch(lr)
{
case ‘l’ :root -> left = newNode(n2);
break;
case ‘r’ : root -> right = newNode(n2);
break;
}
}
else
{
insert_node(root,n1,n2,lr);

}

}

cout << “nInorder Tree Traversal : “;

inorder(root);

cout << endl;

int level;

cout <<“nEnter the level : “;

cin >> level;

print_nodes_k_Distance(root,level);

cout << endl;

return 0;

}
