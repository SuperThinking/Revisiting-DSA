#include<iostream>
using namespace std;

/*
Macro for For-Loop
*/
#define loop(i, b, a) for(int i=b; i<a; i++)

/*
Methods of allocating memory
For C => tree = (struct bstNode*)malloc(sizeof(struct bstNode));
For C++ => tree = new bstNode;
*/

struct bstNode
{
  int data;
  struct bstNode *left, *right;
};

/*
Helper function for 'insert(...)'
Returns a newly created Node for the tree
@params int data(To be inserted)
*/
struct bstNode *createNode(int data)
{
  struct bstNode *temp = new bstNode;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

/*
If
1)Tree is null => returns the newly created nodes
2)If Data < Tree->Data => The left part of tree is traversed for data insertion
3)If Data > Tree->Data => The right part of tree is traversed for data insertion
4)If Data == Tree->Data => Not possible in a BST
@params struct bstNode *tree (Tree in which data has to be inserted)
@params int data (Data that has to be inserted)
*/
struct bstNode *insert(struct bstNode *tree, int data)
{
  if(tree==NULL)
  {
    return createNode(data);
  }

  if(data>tree->data)
  {
    tree->right = insert(tree->right, data);
  }
  else if(data<tree->data)
  {
    tree->left = insert(tree->left, data);
  }
  else
  {
    cout<<"In a BST, 2 nodes can't have the same data!"<<endl;
    exit(0);
  }
}

/*
Helper Function for 'remove(..)'
@params struct bstNode *tree(Tree whose smallest child has to be found)
*/
struct bstNode *smallestInRight(struct bstNode *tree)
{
  while(tree->left!=NULL)
  {
    tree = tree->left;
  }
  return tree;
}

/*
If:
1)No child => Just delete the node
2)1 Child => Replace the node
3)Both Children => Replace (the data) with the smallest in the right node

@params struct bstNode *tree (Tree from which data has to be deleted)
@params int data (Data that has to be deleted)
*/
struct bstNode *remove(struct bstNode *tree, int data)
{
  if(tree==NULL)
  {
    cout<<"The node to be removed does not exist in this tree";
    exit(0);
  }

  if(data<tree->data)
  {
    tree->left = remove(tree->left, data);
  }
  else if(data>tree->data)
  {
    tree->right = remove(tree->right, data);
  }
  else
  {
    if(tree->data==data)
    {
      //No Child (Leaf Node)
      if(tree->left==NULL&&tree->right==NULL)
      {
        tree = NULL;
        free(tree);
      }

      //One Child
      else if(tree->left==NULL||tree->right==NULL)
      {
        int newData;
        if(tree->left==NULL)
        {
          tree = tree->right;
        }
        else
        {
          tree = tree->left;
        }
      }

      //Both Childs
      else
      {
        int newData = (smallestInRight(tree->right))->data;
        tree = remove(tree, newData);
        tree->data = newData;
      }
    }
  }

  return tree;
}

/*
Used to search whether the data exists in the tree or not
@params struct bstNode *tree(Tree in which data has to be searched)
@params int data(Data to be searched)
*/
int search(struct bstNode *tree, int data)
{
  if(tree==NULL)
  {
    return 0;
  }
  else if(data<tree->data)
  {
    search(tree->left, data);
  }
  else if(data>tree->data)
  {
    search(tree->right, data);
  }
  else if(tree->data==data)
  {
    return 1;
  }
}

/*
Below are the 3 types of printing techniques:
1)Inorder -> Left Child -> Parent -> Right Child (Always Ascending Order)
2)Preorder -> Parent -> Left Child -> Right Child
3)Postorder -> Left Child -> Right Child -> Parent
*/
void inorderPrint(struct bstNode *tree)
{
  if(tree!=NULL)
  {
    inorderPrint(tree->left);
    cout<<tree->data<<"\t";
    inorderPrint(tree->right);
  }
}

void preorderPrint(struct bstNode *tree)
{
  if(tree!=NULL)
  {
    cout<<tree->data<<"\t";
    preorderPrint(tree->left);
    preorderPrint(tree->right);
  }
}

void postorderPrint(struct bstNode *tree)
{
  if(tree!=NULL)
  {
    postorderPrint(tree->left);
    postorderPrint(tree->right);
    cout<<tree->data<<"\t";
  }
}

int main()
{
  struct bstNode *tree = NULL;
  int dataToInsert[] = {7, 6, 9, 4, 3, 5, 8, 12, 13, 15, 14};
  loop(i, 0, 11)
  {
    tree = insert(tree, dataToInsert[i]);
  }
  int dataToDelete[] = {14, 7, 6, 4};
  loop(i, 0, 4)
  {
    cout<<"After deleting "<<dataToDelete[i]<<" :\n";
    tree = remove(tree, dataToDelete[i]);
    inorderPrint(tree);cout<<endl;
    preorderPrint(tree);cout<<endl;
    postorderPrint(tree);cout<<endl;
  }

  (search(tree, 15))?cout<<"Found!"<<endl:cout<<"Not Found!"<<endl;
  (search(tree, 4))?cout<<"Found!"<<endl:cout<<"Not Found!"<<endl;
}
