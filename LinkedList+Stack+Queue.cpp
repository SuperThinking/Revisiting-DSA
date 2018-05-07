#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

/*
Macro for For-Loop
*/
#define loop(i, b, a) for(int i=b; i<a; i++)

/*
Node structure
data for storing int data;
nextNode stores the address of next node;
*/
struct Node
{
  int data;
  struct Node *nextNode;
};

/*
Searches the given data in the list
@params struct Node *head(List in which the data is searched)
@params int data(Data that has to be searched)
*/
int search(struct Node *head, int data)
{
  while(head!=NULL)
  {
    if(head->data==data){return 1;}
    head = head->nextNode;
  }
  return 0;
}

/*
RETURN THE NUMBER OF ELEMENTS IN LIST
@params struct Node *head(The list from which the elements have to be counted)
*/
int howMany(struct Node *head)
{
  int count = 0;
  struct Node *temp = head;
  while(temp!=NULL)
  {
    temp = temp->nextNode;
    count++;
  }
  return count;
}

/*
INSERT in BACK/TOP
@params struct Node* head(THE NODE IN WHICH THE VALUE HAS TO BE INSERTED)
@params int n (The data to be inserted)
*/
struct Node *insert_b(struct Node* head, int n)
{
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  struct Node *tempp = head;
  temp->data = n;
  temp->nextNode = NULL;
  if(head==NULL)
  {
    return temp;
  }

  while(tempp->nextNode!=NULL)
  {
    tempp = tempp->nextNode;
  }
  tempp->nextNode = temp;
  return head;
}

/*
INSERT in START/BOTTOM
@params struct Node* head(THE NODE IN WHICH THE VALUE HAS TO BE INSERTED)
@params int n (The data to be inserted)
*/
struct Node *insert_s(struct Node* head, int n)
{
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = n;
  temp->nextNode = head;

  return temp;
}

/*
INSERT AFTER GIVEN DATA
@params struct Node* head(THE NODE IN WHICH THE VALUE HAS TO BE INSERTED)
@params int n (The data to be inserted)
@params int after (After which data, the new data is to be inserted)
*/
struct Node *insert_after(struct Node* head, int n, int after)
{
  if(!search(head, after)){return head;}//Number is not inserted as the 'after' data does not exist in the list
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  struct Node *tempp = head;
  temp->data = n;
  if(head==NULL){temp->nextNode = NULL; return temp;}//Inserting at starting (Empty List)
  while(tempp!=NULL&&tempp->data!=after)
  {
    tempp = tempp->nextNode;
  }

  temp->nextNode = tempp->nextNode;

  tempp->nextNode = temp;

  return head;
}

/*
INSERT AT THE GIVEN POSITION
@params struct Node* head(THE NODE IN WHICH THE VALUE HAS TO BE INSERTED)
@params int n (The data to be inserted)
@params int pos (Postion at which the data has to be inserted)
*/
struct Node *insert_at(struct Node* head, int n, int pos)
{
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  struct Node *tempp = head;
  temp->data = n;
  if(pos>howMany(head)){cout<<"Position greater than the number of Elements in the List!\n";return head;}

  if(head==NULL){temp->nextNode = NULL; return temp;}//Inserting at starting (Empty List)
  else if(pos==0){return insert_s(head, n);}
  else if(pos==howMany(head)){return insert_b(head, n);}

  int p=0;
  struct Node *temppp = head->nextNode;
  while(p!=pos-1)
  {
    tempp = tempp->nextNode;
    temppp = temppp->nextNode;
    p++;
  }

  temp->nextNode = temppp;
  tempp->nextNode = temp;
  return head;
}

/*
DELETE (POP) THE LAST/TOP DATA
@params struct Node *head - Node from which the data has to be deleted
*/
struct Node *pop(struct Node *head)
{
  if(head==NULL){cout<<"NOTHING TO POP! (LIST/STACK EMPTY)\n";return NULL;}
  else if(head->nextNode==NULL){return NULL;}
  struct Node *temp = head;
  while((temp->nextNode)->nextNode!=NULL)
  {
    temp = temp->nextNode;
  }

  temp->nextNode = NULL;

  return head;
}

/*
DELETE (DEQUEUE) THE FIRST/BOTTOM DATA
@params struct Node *head - Node from which the data has to be deleted
*/
struct Node *dequeue(struct Node *head)
{
  if(head==NULL){cout<<"NOTHING TO DEQUEUE! (LIST/QUEUE EMPTY)\n";return NULL;}
  return head->nextNode;
}

/*
DELETE FROM ANYWHERE
@params struct Node *head - Node from which the data has to be deleted
@params int pos - Position from which data has to be deleted (Position starts from 0)
*/
struct Node *del_pos(struct Node *head, int pos)
{
  if(pos>howMany(head)-1){cout<<"Position greater than the number of Elements in the List!\n";return head;}
  else if(pos<0){cout<<"Please enter a Non-Negative Position :)\n";return head;}
  if(pos==0){return dequeue(head);}
  else if(pos==howMany(head)-1){return pop(head);}

  if(head==NULL){cout<<"NOTHING TO DELETE! (LIST EMPTY)\n";return NULL;}
  else if(head->nextNode==NULL){return NULL;}


  int p = 0;
  struct Node *temp = head;
  struct Node *tempp = head->nextNode;

  while(p!=pos-1)
  {
    temp = temp->nextNode;
    tempp = tempp->nextNode;
    p++;
  }
  temp->nextNode = tempp->nextNode;
  return head;
}

/*
REVERSE THE LINKED LIST
@params struct Node *head - The list that has to be reversed
*/
struct Node *reverse(struct Node *head)
{
  struct Node *temp = head;
  struct Node *temp2 = head->nextNode;
  struct Node *temp1 = temp2;
  temp->nextNode = NULL;
  while(temp2->nextNode!=NULL)
  {
    temp1 = temp2;
    temp2 = temp2->nextNode;
    temp1->nextNode = temp;
    temp = temp1;
  }
  temp2->nextNode = temp;
  return temp2;
}

/*
PRINT
@params struct *Node head(The list to be printed)
*/
void print(struct Node* head)
{
  while(head!=NULL)
  {
    cout<<head->data<<"\t";
    head = head->nextNode;
  }
  cout<<endl;
}


int main()
{
  struct Node *node = NULL;
  loop(i, 0, 8){node = insert_b(node, i);}loop(i, 8, 16){node = insert_s(node, i);}
  node = insert_after(node, 1123, 9);
  print(node);

  node = insert_at(node, 100, 16);
  print(node);

  node = pop(node);
  node = pop(node);
  node = pop(node);
  node = pop(node);
  print(node);

  node = dequeue(node);
  node = dequeue(node);
  node = dequeue(node);
  node = dequeue(node);
  print(node);

  node = del_pos(node, 3);
  node = del_pos(node, 5);
  node = del_pos(node, 2);
  node = del_pos(node, 2);
  node = dequeue(node);
  print(node);

  node = reverse(node);
  print(node);
}
