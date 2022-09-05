#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  Node* next;
  int val;
  
  Node(int v)
  {
    val=v;
  }
};

void insertNode(Node* &head,int val)
{
  Node* temp=new Node(val);
  if(head == NULL)
  {
    head=temp;
    return;
  }
  Node* curr=head;
  while(curr->next)
  {
    curr=curr->next;
  }
  curr->next=temp;
}

void insertAtHead(Node* &head,int val)
{
  Node* temp=new Node(val);
  temp->next=head;
  head=temp;
}
void insertAfterNode(Node* &head,int prevNode,int val)
{
  Node* temp=new Node(val);
  
  Node* curr=head;
  
  while(curr->next && curr->next->val != prevNode)
  {
    curr=curr->next;
  }
  curr=curr->next;
  
  Node* nxt=curr->next;
  curr->next=temp;
  temp->next=nxt;
}

void deleteAtHead(Node* &head)
{
  if(head == NULL)
  {
    return;
  }
  Node* temp=head;
  head=head->next;
  delete temp;
}

void deleteAtTail(Node* &head)
{
  if(head == NULL)
  {
    return;
  }
  Node* curr=head;
  
  while(curr->next->next)
  {
    curr=curr->next;
  }
  
  Node* temp=curr->next;
  curr->next=NULL;
  delete temp;
}


void deleteAtPos(Node* &head,int pos)
{
  if(head == NULL)
  {
    return;
  }
  if(pos == 0)
  {
    deleteAtHead(head);
  }
  Node* prev=NULL;
  Node* curr=head;
  
  int i=0;
  while(i < pos)
  {
    prev=curr;
    curr=curr->next;
    i++;
  }
  
  prev->next=curr->next;
  delete curr;
}

void print(Node* &head)
{
  Node* curr=head;
  while(curr)
  {
    cout<<curr->val<<"->";
    curr=curr->next;
  }
  cout<<"NULL";
  cout<<endl;
}

int main()
{
  Node* head=new Node(0);
  insertAtHead(head,1);
  insertNode(head,2);
  insertNode(head,3);
  insertNode(head,4);
  //insertAtHead(head,0);
  insertAfterNode(head,3,8);
  
  
  print(head);
  
  deleteAtHead(head);
    
  print(head);
 
  deleteAtTail(head);
 
  print(head);
  
  deleteAtPos(head,3);
  
  print(head);
}
